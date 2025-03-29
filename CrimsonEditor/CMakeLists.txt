project(Editor)
file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)