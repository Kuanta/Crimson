cmake_minimum_required(VERSION 3.21)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(CMAKE_PDB_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH $<0:>${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(CrimsonEngine)

# Conan toolchain and dependencies
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake OPTIONAL RESULT_VARIABLE TOOLCHAIN_INCLUDED)
include(${CMAKE_BINARY_DIR}/conan_deps.cmake OPTIONAL)

add_subdirectory(CrimsonEngine)
add_subdirectory(CrimsonEditor)
add_subdirectory(CrimsonGame)
