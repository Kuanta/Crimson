project(Engine)

file(GLOB_RECURSE ENGINE_SOURCES 
"${CMAKE_CURRENT_SOURCE_DIR}/*.c"
"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(${PROJECT_NAME} SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_compile_definitions(${PROJECT_NAME} PUBLIC -DCRIMSON_EXPORT)

find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(lua REQUIRED)
find_package(assimp REQUIRED)
find_package(spdlog REQUIRED)
find_package(Boost REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CONAN_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${Boost_LIBRARIES}     
    glfw     
    glm::glm
    lua::lua
    assimp::assimp 
    spdlog::spdlog
)
