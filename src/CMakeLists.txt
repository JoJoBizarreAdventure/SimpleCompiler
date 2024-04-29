project(CompilerImpl)

add_library(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_sources(${PROJECT_NAME} PRIVATE compilerStructure.cpp lexicalAnalysis.cpp syntacticAnalysis.cpp transformation.cpp)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_LOG)
endif ()

add_library(${PROJECT_NAME}_header INTERFACE)
target_include_directories(${PROJECT_NAME}_header INTERFACE include)
target_link_libraries(${PROJECT_NAME} INTERFACE ${PROJECT_NAME}_header)