// File: src/core/CMakeLists.txt
add_library(suno_core STATIC
    Logger.cpp
    SingleInstanceGuard.cpp
    AsyncExecutor.cpp
)

target_link_libraries(suno_core PUBLIC
    Qt6::Core
    Qt6::Concurrent
    spdlog::spdlog
    KDSingleApplication::KDSingleApplication
)

target_include_directories(suno_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_project_warnings(suno_core)