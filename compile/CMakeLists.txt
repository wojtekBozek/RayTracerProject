cmake_minimum_required(VERSION 3.12.0)



project (MyRayTracer)
if(CMAKE_SYSTEM MATCHES Windows)
   message(STATUS "Target system is Windows")
endif()

if(CMAKE_HOST_SYSTEM MATCHES Linux)
   message(STATUS "Build host runs Linux")
endif()

set(CMAKE_DEBUG_POSTFIX d)
add_compile_definitions(_USE_MATH_DEFINES)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -O2 -pthread)
endif()

include_directories(${CMAKE_SOURCE_DIR}/../headers
                    ${CMAKE_SOURCE_DIR}/../Timer)

file(GLOB_RECURSE MyRayTracer_src CONFIGURE_DEPENDS
     "../src/*.cpp")

add_executable(${PROJECT_NAME} ${MyRayTracer_src})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION "1.0.0")
