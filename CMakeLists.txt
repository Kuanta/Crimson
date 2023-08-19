cmake_minimum_required(VERSION 3.21)
project(crimson)

set(CMAKE_CXX_STANDARD 14)

# Source and Header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "Testing/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "includes/*.h" "Testing/*.h")

find_package(glfw3 CONFIG REQUIRED)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(crimson ${SOURCES})

# Include directories
target_include_directories(crimson PRIVATE
        ${CMAKE_SOURCE_DIR}/includes
        ${CMAKE_SOURCE_DIR}/src
        D:/Documents/Codes/Cpp/Libraries/Includes
        D:/Documents/Codes/Cpp/Libraries/Includes/glad
        )

# Link libraries
target_link_libraries(crimson
        PRIVATE glfw
        PRIVATE ${Boost_LIBRARIES}
        -lassimp.dll
        -lgdi32
        -lopengl32
        -lbcrypt
        )