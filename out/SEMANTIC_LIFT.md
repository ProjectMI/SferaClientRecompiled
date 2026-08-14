# Семантический подъём: три прохода

Семантически разобраны все 4 892 функции исходного lifted-среза — 324 818 из 324 818 строк, то есть 100%. Третий проход закрыл оставшиеся 1 201 функцию и 108 484 строки (33,398% исходного листинга).

`semantic_native.h/.cpp` остаётся единственным предметным слоем. В нём нет `LiftCpu`, `LIFT_*`, `lift_load*`, `lift_store*` или адресной арифметики процессорной модели. `semantic_bridge.h/.cpp` остаётся одним универсальным ABI-маршаллером; он не получил отдельной обвязки под каждую новую объектную функцию.

## Третий проход

Остаток был разобран по исходным строкам, call graph и полям, а затем свёрнут в нормальные C++20-подсистемы. Закрыты ранние `Arrays/config/sDataContainers`, bootstrap/connect config, `CMatFilter`, `ModelsMngr`, `NatureManager`, `NetworkConnectionChecker`, `objparam`, `ParticleSystem`, quadtree, QuickFile, ServerWall, shadow support, `simpleHTMLParser`, `SimpleParser`, sky/sound/texture/update/zoning и весь хвост старого Sphere UI от `Button` до `Sprite`/`SphereOptions`.

Распознанные контейнерные и RAII-функции внутри этих диапазонов не воспроизводятся адрес-в-адрес: они поглощены `std::vector`, `std::list`, `std::deque`, `std::map`, `std::unordered_map`, `std::set`, `std::string`, `std::optional`, `std::variant`, `std::unique_ptr` и `std::filesystem`.

Крупные новые модели: `client_runtime::LaunchOptions/ModelManager/ConnectionProbe`, `content_runtime::MaterialFilter/ObjectConfig/ParticleLibrary/QuadTree/QuickFileArchive/ServerWall/NatureManager/TextureSet/UpdatePlan/ZoningManager`, `markup_runtime::HyperTextDocument/TokenStream`, `sky_runtime::SkyTimeline`, `legacy_sound::SoundLibrary/SoundTrack` и `ui_runtime::InterfaceModel/PropertyBag/TextBuffer/ScrollModel/ListModel/OptionsModel`.

## Граница исполнения

Семантическое покрытие теперь полное, но это не означает, что все 4 892 legacy-адреса уже переключены на native bridge. Точные ABI-безопасные входы остаются bridge-bound, а объектные методы со старым layout продолжают использовать compatibility fallback до миграции владеющего object graph. Это намеренно отделено от семантического подъёма, чтобы не повторить ошибки с частично восстановленным ABI.

## Второй проход

Диапазон `0x00421000–0x004308FF` восстановлен как подсистемы scripted effects, sound cues и журналирования. В native-модели появились типизированные определения эффектов, планировщик частей, blade trail, rain field, библиотека звуков, mixer голосов, logger, sink и registry.

Диапазон `0x00430900–0x0044DE2F` восстановлен как общий runtime контейнеров, интерпретатора и INet. Он включает регистр строк, списки предметов, каталог серверов, байткод-модули и их массивы, команды с типизированными callback-функциями, BMP-карту мира, транспортные сессии и менеджер соединений. Распознанные контейнеры представлены `std::map`, `std::unordered_map`, `std::vector`, `std::span`, `std::optional` и `std::function`.

Диапазон `0x0044DE30–0x0047D76F` восстановлен как runtime мира и сцены: animation clips, generation-checked object handles, иерархия объектов, преобразования, источники света, height field, planting map, weather timeline, model catalog и формирование draw-команд.

В этом срезе добавлены 13 точных ABI-входов для восстановленных предикатов и математических функций: inverse transform, transport-mode predicate, wrapped heading, interop storage class, wildcard matching, quaternion matrix, cross product, substring query, effect-time scaling, near-zero snapping, grid index и пересечение отрезка с плоскостью.

## Совокупно восстановлено

- конфигурация, битовые потоки и базовые строковые/байтовые операции;
- STL-модель значений и виртуальная машина скриптов;
- сетевые пакеты, очереди, потоки приёма и состояния соединений;
- матрицы, кватернионы, скелет, blood marks и файловый manifest;
- scripted effects, звук, логи, shared runtime, INet и интерпретаторные модули;
- объекты мира, анимация, освещение, terrain, planting, weather и scene rendering;
- Direct3D-ресурсы, render-state cache, shader constants и post effects;
- memory tracker, file image, antiflood и распознанные MSVC runtime helpers;
- полный zlib 1.1.3 и таблица 704 кодов DirectX;
- развёрнутые шаблоны STL и EH-cleanup/RAII funclets свёрнуты в стандартные контейнеры и правила времени жизни C++.

## Граница проверки

Таблица содержит 98 точных native-входов, соответствующих 18 055 строкам исходного листинга. Они вызываются процессорным runtime через общий мост. Для объектных подсистем с несовместимым legacy ABI сохранён процессорный fallback, пока не поднят весь владеющий объектный граф; частичная подмена legacy-экземпляров не выполняется.

`semantic_native_tests.cpp` проверяет структуры и алгоритмы всех добавленных подсистем, ABI-layout и вызовы native-входов, сетевой формат и контрольную сумму, BMP round-trip, handle generations, объектную иерархию, animation sampling, terrain/weather и таблицу DirectX. Сборка выполняется в C++20 с `-Wall -Wextra -Wpedantic -Werror`.

zlib повторно сравнен с оригинальным zlib 1.1.3 на 132 парах compression/decompression и ошибочном вводе. Production-проект рассчитан на Visual Studio 2022 `Release|Win32`; тестовый файл не включён в основной `.vcxproj`, чтобы не добавлять второй `main` в клиент.
