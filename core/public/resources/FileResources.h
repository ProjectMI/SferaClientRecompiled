#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class SferaFileManager;
class SferaFileManagerScopedFile;

class SferaFileManagerScopedFile
{
  public:
    SferaFileManagerScopedFile(SferaFileManager &owner, int descriptor) noexcept : owner_(owner), descriptor_(descriptor)
    {
    }
    SferaFileManagerScopedFile(const SferaFileManagerScopedFile &) = delete;
    SferaFileManagerScopedFile &operator=(const SferaFileManagerScopedFile &) = delete;
    ~SferaFileManagerScopedFile() noexcept;
    int get() const noexcept
    {
        return descriptor_;
    }
    int close();

  private:
    SferaFileManager &owner_;
    int descriptor_;
};

class SferaFileManager
{
  public:
    SferaFileManager() = default;
    ~SferaFileManager();
    SferaFileManager(const SferaFileManager &) = delete;
    SferaFileManager &operator=(const SferaFileManager &) = delete;
    bool setErrorReporting(bool enabled);
    int open(const std::string &filename, int flags);
    int create(const std::string &filename);
    int transformEnvelope(const std::string &destination, const std::string &source, bool compress);
    std::ptrdiff_t read(int descriptor, std::span<std::byte> destination);
    std::ptrdiff_t write(int descriptor, std::span<const std::byte> source);
    std::int64_t seek(int descriptor, std::int64_t offset, int origin);
    int close(int descriptor);
    std::int64_t fileSize(const std::string &filename);
    std::vector<std::uint8_t> readAll(const std::string &filename);
    static bool writeFile(const std::string &path, std::span<const std::byte> source);
    static std::optional<std::vector<std::uint8_t>> readBounded(const std::string &filename, std::size_t capacity);
    void keepTail(const std::string &filename, std::size_t size);
    void addSearchPath(std::string_view directory);
    std::vector<std::string> candidatePaths(const std::string &filename, bool search_nested_paths = false) const;

  private:
    static constexpr std::size_t maximum_open_files = 100u;
    static constexpr std::size_t maximum_search_paths = 100u;
    void reportError(std::string_view description, const std::string &filename) const;
    bool error_reporting_enabled = false;
    std::vector<std::string> search_paths;
    std::unordered_map<int, std::string> open_files;
    int registerDescriptor(int descriptor, const std::string &filename);
    const std::string *filenameFor(int descriptor, std::string_view invalid_handle_message) const;

  private:
    friend class SferaFileManagerScopedFile;

  private:
    template <class Byte, class Transfer> static std::ptrdiff_t transferFileBytes(int descriptor, std::span<Byte> buffer, Transfer transfer);

  private:
    auto transformEnvelopeData(const std::string &destination, const std::string &source, bool compress) -> int;
};

extern SferaFileManager g_sfera_files;

struct SferaFileReportingScope;

struct SferaFileReportingScope
{
    SferaFileManager &owner;
    bool previous;
    ~SferaFileReportingScope();
};

class QuickFile;
struct QuickFileEntry;

struct QuickFileEntry
{
    std::vector<std::uint8_t> bytes;
    std::size_t module_id;
};

class QuickFile
{
  public:
    static constexpr std::size_t file_capacity = 400;
    QuickFile *initialize(const std::string &directory);
    void release();
    int load(const std::string &filename, std::size_t size);
    const QuickFileEntry *find(std::string_view filename) const;

  private:
    static constexpr std::size_t maximum_filename_length = 32;
    std::vector<QuickFileEntry> files;
    std::unordered_map<std::string, std::size_t> index;
};
