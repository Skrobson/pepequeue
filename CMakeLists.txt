cmake_minimum_required (VERSION 3.28)

project(pepequeue)

set(VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake/Modules)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_INCLUDEDIR include)
set(CMAKE_INSTALL_BINDIR bin)

####packages
#find_package(Boost 1.83 REQUIRED COMPONENTS program_options)
find_package(Threads REQUIRED)
find_package(libtins REQUIRED)

add_subdirectory (src)
#add_subdirectory (examples)
