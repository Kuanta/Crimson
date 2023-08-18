cmake_minimum_required(VERSION 3.21)
project(crimson)

set(CMAKE_CXX_STANDARD 14)

# Source and Header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.h" "includes/*.h")

find_package(glfw3 CONFIG REQUIRED)

add_executable(crimson ${SOURCES} ${HEADERS} includes/Core/Modules/RenderWindowModule.h src/Core/EngineModules/RenderWindowModule.cpp includes/Core/Modules/ECSModule.h includes/Core/ECS/Entity.h src/Core/ECS/SceneManager.cpp includes/Core/ECS/SceneManager.h src/Core/ECS/Entity.cpp includes/Rendering/Components/MeshRenderer.h includes/Core/TimeManager.h Testing/NotifierComponent.cpp Testing/NotifierComponent.h src/Core/TimeManager.cpp src/Core/AMS/AssetManager.cpp includes/Core/AMS/AssetManager.h)

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
        -lassimp.dll
        -lgdi32
        -lopengl32
        )