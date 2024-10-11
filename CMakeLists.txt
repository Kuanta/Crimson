cmake_minimum_required(VERSION 3.21)
project(crimson)

set(CMAKE_CXX_STANDARD 14)


# Set the CMAKE_PREFIX_PATH to vcpkg's installation directory
set(CMAKE_PREFIX_PATH "../vcpkg/installed/arm64-osx")

set(CMAKE_TOOLCHAIN_FILE "../vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../vcpkg/installed/arm64-osx/share/stb")

# Source and Header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "Testing/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "includes/*.h" "Testing/*.h")

find_package(glfw3 CONFIG REQUIRED)
find_package(Boost REQUIRED)
find_package(Lua REQUIRED)
find_package(Assimp CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(crimson ${SOURCES})

# Include directories
target_include_directories(crimson PRIVATE
        ${CMAKE_SOURCE_DIR}/includes
        ${CMAKE_SOURCE_DIR}/src
        PRIVATE ${LUA_INCLUDE_DIR}
        PRIVATE glm::glm-header-only
        )

# Link libraries
target_link_libraries(crimson
        PRIVATE glfw
        PRIVATE ${Boost_LIBRARIES}
        PRIVATE ${LUA_LIBRARIES}
        PRIVATE assimp::assimp
        -lassimp.dll
        -lgdi32
        -lopengl32
        -lbcrypt
        )
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Assets")
set(DEST_DIR "${CMAKE_CURRENT_BINARY_DIR}")


file(COPY ${SOURCE_DIR} DESTINATION ${DEST_DIR})