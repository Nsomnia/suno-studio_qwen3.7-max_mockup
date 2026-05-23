# File: CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

project(SunoStudio
    VERSION 0.1.0
    DESCRIPTION "AI Music & Video Automation Studio"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Include custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CPM)
include(CompilerWarnings)
include(QtHelpers)

# Global dependencies
CPMAddPackage("gh:nlohmann/json@3.11.3")
CPMAddPackage("gh:gabime/spdlog@1.14.1")
CPMAddPackage("gh:Neargye/magic_enum@0.9.5")
CPMAddPackage("gh:ericniebler/range-v3@0.12.0")
CPMAddPackage("gh:frankosterfeld/qtkeychain@0.14.2")
CPMAddPackage("gh:KDAB/KDSingleApplication@1.1.0")

# Qt6 Components
find_package(Qt6 6.11 REQUIRED COMPONENTS 
    Core 
    Quick 
    QuickControls2 
    Multimedia 
    Svg 
    Concurrent
)

qt_standard_project_setup()

add_subdirectory(src/core)
add_subdirectory(src/theme)
add_subdirectory(src/shared)
add_subdirectory(src/modules/suno)
add_subdirectory(src/modules/player)
add_subdirectory(src/modules/automation)
add_subdirectory(src/app)