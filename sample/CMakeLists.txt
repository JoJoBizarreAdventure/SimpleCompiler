project(CompilerSample)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE CompilerImpl)

target_sources(${PROJECT_NAME} PRIVATE lexical.cpp)

file(COPY input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})