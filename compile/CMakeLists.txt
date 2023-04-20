cmake_minimum_required(VERSION 3.12.0)

project (MyRayTracer)
set(CMAKE_DEBUG_POSTFIX d)
add_compile_definitions(_USE_MATH_DEFINES)

include_directories(${CMAKE_SOURCE_DIR}/../headers
                    ${CMAKE_SOURCE_DIR}/../Timer)

file(GLOB_RECURSE MyRayTracer_src CONFIGURE_DEPENDS
     "../src/*.cpp")

add_executable(${PROJECT_NAME} ${MyRayTracer_src})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION "1.0.0")
