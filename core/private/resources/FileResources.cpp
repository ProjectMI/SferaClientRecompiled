#include <sys/utime.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fcntl.h>
#include <filesystem>
#include <io.h>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <share.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <sys/stat.h>
#include <system_error>
#include <utility>
#include <vector>

#include "compression/Zlib.h"
#include "diagnostics/ClientDiagnostics.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "text/Text.h"

SferaFileManager::~SferaFileManager()
{
    for (const auto &file : open_files)
        ::_close(file.first);
}

SferaFileManagerScopedFile::~SferaFileManagerScopedFile() noexcept
{
    if (descriptor_ < 0)
        return;
    const auto found = owner_.open_files.find(descriptor_);
    if (found == owner_.open_files.end())
        return;
    ::_close(descriptor_);
    owner_.open_files.erase(found);
}

int SferaFileManagerScopedFile::close()
{
    const auto descriptor = std::exchange(descriptor_, -1);
    return descriptor < 0 ? 0 : owner_.close(descriptor);
}

bool SferaFileManager::setErrorReporting(bool enabled)
{
    return std::exchange(error_reporting_enabled, enabled);
}

std::vector<std::string> SferaFileManager::candidatePaths(const std::string &filename, bool search_nested_paths) const
{
    std::vector<std::string> candidates{filename};
    if (search_nested_paths || filename.find('\\') == std::string::npos)
        for (const std::string &directory : search_paths)
            candidates.push_back(directory + filename);
    return candidates;
}

void SferaFileManager::addSearchPath(std::string_view directory)
{
    if (directory.empty())
        return;
    if (search_paths.size() == maximum_search_paths)
    {
        CSphereError error;
        error.write("File manager search path limit exceeded (100 paths).");
        return;
    }
    std::string path(directory);
    if (path.back() != '\\')
        path.push_back('\\');
    search_paths.push_back(std::move(path));
}

int SferaFileManager::registerDescriptor(int descriptor, const std::string &filename)
{
    if (descriptor == -1)
        return -1;
    if (open_files.size() == maximum_open_files)
    {
        ::_close(descriptor);
        CSphereError error;
        error.write("File manager open file limit exceeded (100 files).");
        return -1;
    }
    try
    {
        open_files.insert_or_assign(descriptor, filename);
    }
    catch (...)
    {
        ::_close(descriptor);
        throw;
    }
    return descriptor;
}

int SferaFileManager::open(const std::string &filename, int flags)
{
    for (const std::string &candidate : candidatePaths(filename))
    {
        if (candidate.empty())
            continue;
        int descriptor = -1;
        if (::_sopen_s(&descriptor, candidate.c_str(), flags | _O_BINARY, _SH_DENYNO, 0) == 0)
            return registerDescriptor(descriptor, candidate);
    }
    if (error_reporting_enabled)
        reportError("Unable to open file: ", filename);
    return -1;
}

int SferaFileManager::create(const std::string &filename)
{
    if (!filename.empty())
    {
        ::_chmod(filename.c_str(), _S_IREAD | _S_IWRITE);
        int descriptor = -1;
        if (::_sopen_s(&descriptor, filename.c_str(), _O_RDWR | _O_CREAT | _O_TRUNC | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE) == 0)
            return registerDescriptor(descriptor, filename);
    }
    if (error_reporting_enabled)
        reportError("Unable to create file: ", filename);
    return -1;
}

const std::string *SferaFileManager::filenameFor(int descriptor, std::string_view invalid_handle_message) const
{
    const auto found = open_files.find(descriptor);
    if (found != open_files.end())
        return &found->second;
    CSphereError error;
    error.write(invalid_handle_message);
    return nullptr;
}

template <class Byte, class Transfer> std::ptrdiff_t SferaFileManager::transferFileBytes(int descriptor, std::span<Byte> buffer, Transfer transfer)
{
    const auto size = buffer.size();
    if (!std::in_range<std::ptrdiff_t>(size))
    {
        errno = EINVAL;
        return -1;
    }
    std::size_t completed = 0;
    while (completed < size)
    {
        const unsigned int chunk = SferaNumeric::lowWord(std::min(size - completed, std::size_t{std::numeric_limits<int>::max()}));
        const int transferred = transfer(descriptor, buffer.data() + completed, chunk);
        if (transferred < 0)
            return -1;
        completed += transferred;
        if (std::cmp_not_equal(transferred, chunk))
            break;
    }
    return completed;
}

std::ptrdiff_t SferaFileManager::read(int descriptor, std::span<std::byte> destination)
{
    const std::string *filename = filenameFor(descriptor, "Attempt of reading from the file with the wrong handle.");
    if (filename == nullptr)
        return -1;
    const auto transferred = SferaFileManager::transferFileBytes(descriptor, destination, ::_read);
    if (std::cmp_equal(transferred, destination.size()))
        return transferred;
    if (error_reporting_enabled)
        reportError(transferred == -1 ? "Unable to read file: " : "Unexpected end of file: ", *filename);
    return -1;
}

std::ptrdiff_t SferaFileManager::write(int descriptor, std::span<const std::byte> source)
{
    const std::string *filename = filenameFor(descriptor, "Attempt of writing to the file with the wrong handle.");
    if (filename == nullptr)
        return -1;
    const auto transferred = SferaFileManager::transferFileBytes(descriptor, source, ::_write);
    if (std::cmp_equal(transferred, source.size()))
        return transferred;
    if (error_reporting_enabled)
        reportError(transferred == -1 ? "Unable to write file: " : "Incomplete file write (possibly insufficient disk space): ", *filename);
    return -1;
}

std::int64_t SferaFileManager::seek(int descriptor, std::int64_t offset, int origin)
{
    const std::string *filename = filenameFor(descriptor, "Attempt of seeking in the file with the wrong handle.");
    if (filename == nullptr)
        return -1;
    const auto position = ::_lseeki64(descriptor, offset, origin);
    if (position == -1 && error_reporting_enabled)
        reportError("Unable to seek in file: ", *filename);
    return position;
}

int SferaFileManager::close(int descriptor)
{
    const std::string *filename = filenameFor(descriptor, "Attempt of closing the file with the wrong handle.");
    if (filename == nullptr)
        return -1;
    if (::_close(descriptor) == 0)
    {
        open_files.erase(descriptor);
        return 0;
    }
    if (error_reporting_enabled)
        reportError("Unable to close file: ", *filename);
    return -1;
}

std::int64_t SferaFileManager::fileSize(const std::string &filename)
{
    SferaFileManagerScopedFile file(*this, open(filename, _O_RDONLY));
    return file.get() < 0 ? -1 : ::_filelengthi64(file.get());
}

std::optional<std::vector<std::uint8_t>> SferaFileManager::readBounded(const std::string &filename, std::size_t capacity)
{
    if (filename.empty())
        return std::nullopt;
    std::unique_ptr<std::FILE, decltype(&std::fclose)> file(::_fsopen(filename.c_str(), "rb", _SH_DENYNO), &std::fclose);
    if (!file)
        return std::nullopt;
    const auto length = ::_filelengthi64(::_fileno(file.get()));
    if (length < 0 || std::cmp_greater_equal(length, capacity))
        return std::nullopt;
    std::vector<std::uint8_t> bytes(length);
    if (!bytes.empty() && std::fread(bytes.data(), 1, bytes.size(), file.get()) != bytes.size())
        return std::nullopt;
    return bytes;
}

void SferaFileManager::reportError(std::string_view description, const std::string &filename) const
{
    std::string message(description);
    message += filename;
    CSphereError error;
    error.write(message);
}

std::vector<std::uint8_t> SferaFileManager::readAll(const std::string &filename)
{
    SferaFileManagerScopedFile file(*this, open(filename, _O_RDONLY));
    const auto &path = filename;
    if (file.get() < 0)
        throw std::runtime_error(std::string("Unable to open file: ") + path);
    const auto length = seek(file.get(), 0, SEEK_END);
    if (length < 0 || seek(file.get(), 0, SEEK_SET) != 0)
        throw std::runtime_error(std::string("Unable to measure file: ") + path);
    if (std::cmp_greater(length, std::numeric_limits<std::ptrdiff_t>::max()))
        throw std::length_error("File exceeds native buffer capacity");
    std::vector<std::uint8_t> bytes(length);
    if (length != 0 && read(file.get(), std::as_writable_bytes(std::span(bytes))) != length)
        throw std::runtime_error(std::string("Incomplete file read: ") + path);
    return bytes;
}

bool SferaFileManager::writeFile(const std::string &path, std::span<const std::byte> source)
{
    if (path.empty())
        return false;
    ::_chmod(path.c_str(), _S_IREAD | _S_IWRITE);
    std::unique_ptr<FILE, decltype(&std::fclose)> stream(::_fsopen(path.c_str(), "wb", _SH_DENYNO), &std::fclose);
    if (!stream)
        return false;
    const auto written = SferaFileManager::transferFileBytes(::_fileno(stream.get()), source, ::_write);
    const bool closed = std::fclose(stream.release()) == 0;
    return std::cmp_equal(written, source.size()) && closed;
}

void SferaFileManager::keepTail(const std::string &filename, std::size_t size)
{
    const auto length = fileSize(filename);
    if (length < 0 || std::cmp_less_equal(length, size) || size > std::size_t{std::numeric_limits<std::ptrdiff_t>::max()})
        return;
    std::vector<std::uint8_t> tail(size);
    SferaFileManagerScopedFile file(*this, open(filename, _O_RDWR));
    if (file.get() < 0)
        return;
    const std::int64_t tail_offset = size;
    const std::ptrdiff_t tail_size = size;
    if (seek(file.get(), -tail_offset, SEEK_END) < 0 || read(file.get(), std::as_writable_bytes(std::span(tail))) != tail_size)
        return;
    if (seek(file.get(), 0, SEEK_SET) >= 0 && write(file.get(), std::as_bytes(std::span(tail))) == tail_size)
        ::_chsize_s(file.get(), size);
}

auto SferaFileManager::transformEnvelopeData(const std::string &destination, const std::string &source, bool compress) -> int
{
    const auto length = fileSize(source);
    if (length < 0 || std::cmp_greater(length, std::numeric_limits<std::ptrdiff_t>::max()))
        return -1;
    std::vector<std::uint8_t> input(length);
    SferaFileManagerScopedFile inputFile(*this, open(source, _O_RDONLY));
    if (inputFile.get() < 0)
        return -1;
    struct _stat64i32 information{};
    const bool haveTimes = ::_fstat64i32(inputFile.get(), &information) == 0;
    const auto received = read(inputFile.get(), std::as_writable_bytes(std::span(input)));
    inputFile.close();
    if (received != length)
        return -1;
    std::vector<std::uint8_t> transformed;
    std::span<const std::uint8_t> output = input;
    std::uint32_t size = 0;
    if (compress)
    {
        const auto capacity = input.size() * 101ull / 100u + 20u;
        if (capacity > UINT32_MAX)
            return -1;
        size = SferaNumeric::lowWord(capacity);
        transformed.resize(size);
        if (SferaZStream32::compressEnvelope(transformed.data(), size, input) != 0)
            return -1;
        output = std::span<const std::uint8_t>(transformed.data(), size);
    }
    else if (SferaZStream32::decompressEnvelope(nullptr, size, input) == 0)
    {
        if (size > UINT32_MAX - 100)
            return -1;
        transformed.resize(size + 100);
        if (SferaZStream32::decompressEnvelope(transformed.data(), size, input) != 0)
            return -1;
        output = std::span<const std::uint8_t>(transformed.data(), size);
    }
    ::_chmod(destination.c_str(), _S_IREAD | _S_IWRITE);
    SferaFileManagerScopedFile outputFile(*this, create(destination));
    if (outputFile.get() < 0)
        return -1;
    const auto written = write(outputFile.get(), std::as_bytes(output));
    if (haveTimes)
    {
        __utimbuf64 times{information.st_mtime, information.st_mtime};
        ::_futime64(outputFile.get(), &times);
    }
    const auto closed = outputFile.close();
    return written == std::ssize(output) && closed == 0 ? 0 : -1;
}

int SferaFileManager::transformEnvelope(const std::string &destination, const std::string &source, bool compress)
{
    SferaFileReportingScope reporting{*this, setErrorReporting(false)};

    return transformEnvelopeData(destination, source, compress);
}

SferaFileReportingScope::~SferaFileReportingScope()
{
    owner.setErrorReporting(previous);
}

QuickFile *QuickFile::initialize(const std::string &directory)
{
    release();
    files.reserve(file_capacity);
    index.reserve(file_capacity);
    if (directory.empty())
        return this;
    std::error_code error;
    std::filesystem::directory_iterator cursor(std::filesystem::path(directory), error);
    const std::filesystem::directory_iterator end;
    while (!error && cursor != end)
    {
        const auto path = cursor->path();
        if (SferaText::resourceKey(path.extension().string()) == ".mbc" && cursor->is_regular_file(error))
            load(path.string(), 0);
        cursor.increment(error);
    }
    return this;
}

void QuickFile::release()
{
    index.clear();
    std::vector<QuickFileEntry>().swap(files);
}

int QuickFile::load(const std::string &filename, std::size_t size)
{
    if (filename.empty())
        return 2;
    std::unique_ptr<std::FILE, decltype(&std::fclose)> stream(::_fsopen(filename.c_str(), "rb", _SH_DENYNO), &std::fclose);
    if (!stream)
        return 2;
    if (files.size() >= file_capacity)
        return -1;
    if (size == 0)
    {
        const auto length = ::_filelengthi64(::_fileno(stream.get()));
        if (!std::in_range<std::size_t>(length))
            return 3;
        size = length;
    }
    QuickFileEntry loaded{std::vector<std::uint8_t>(size), files.size() + 1};
    if (size != 0 && std::fread(loaded.bytes.data(), 1, size, stream.get()) != size)
        return 3;
    const std::string_view path(filename);
    const auto separator = path.find_last_of("/\\");
    const auto basename = path.substr(separator == std::string_view::npos ? 0 : separator + 1);
    if (basename.size() > maximum_filename_length)
        throw std::length_error("QuickFile: module filename is too long");
    auto key = SferaText::resourceKey(basename);
    files.push_back(std::move(loaded));
    try
    {
        index.try_emplace(std::move(key), files.size() - 1);
    }
    catch (...)
    {
        files.pop_back();
        throw;
    }
    return 0;
}

const QuickFileEntry *QuickFile::find(std::string_view filename) const
{
    if (filename.size() > maximum_filename_length)
        return nullptr;
    const auto found = index.find(SferaText::resourceKey(filename));
    return found == index.end() ? nullptr : &files[found->second];
}
