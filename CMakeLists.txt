cmake_minimum_required(VERSION 3.21)
project(crimson)

set(CMAKE_CXX_STANDARD 14)

# Source and Header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "Testing/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "includes/*.h" "Testing/*.h")

find_package(glfw3 CONFIG REQUIRED)
find_package(Boost REQUIRED)
find_package(Lua REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(crimson ${SOURCES} includes/Core/Actor.h src/Core/Actor.cpp src/Rendering/MeshInstance.cpp includes/Rendering/MeshInstance.h includes/Core/AMS/MeshAsset.h src/Core/AMS/MeshAsset.cpp includes/Rendering/MaterialParameter.h src/Rendering/MaterialLibrary.cpp includes/Rendering/MaterialLibrary.h src/Rendering/MaterialParameter.cpp includes/Scripting/ScriptingModule.cpp includes/Scripting/ScriptingModule.h includes/Scripting/ScriptingComponent.cpp includes/Scripting/ScriptingComponent.h)

# Include directories
target_include_directories(crimson PRIVATE
        ${CMAKE_SOURCE_DIR}/includes
        ${CMAKE_SOURCE_DIR}/src
        PRIVATE ${LUA_INCLUDE_DIR}
        D:/Documents/Codes/Cpp/Libraries/Includes
        D:/Documents/Codes/Cpp/Libraries/Includes/glad
        )

# Link libraries
target_link_libraries(crimson
        PRIVATE glfw
        PRIVATE ${Boost_LIBRARIES}
        PRIVATE ${LUA_LIBRARIES}
        -lassimp.dll
        -lgdi32
        -lopengl32
        -lbcrypt
        )
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/EngineScripts")
set(DEST_DIR "${CMAKE_CURRENT_BINARY_DIR}/Assets/Scripts/")

file(COPY ${SOURCE_DIR} DESTINATION ${DEST_DIR})