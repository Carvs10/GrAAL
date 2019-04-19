cmake_minimum_required(VERSION 3.5)
project(GrAAL)

#=== FINDING PACKAGES ===#

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
set(GCC_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

#=== Include dir ===
include_directories(include)

#=== Library ===
add_library(GrAAL STATIC "src/graal.cpp")
install(TARGETS GrAAL ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

#=== Test target ===
file(GLOB SOURCES_TEST "test/*.cpp")
add_executable(run_tests ${SOURCES_TEST})
target_link_libraries(run_tests PRIVATE ${GTEST_LIBRARIES} PRIVATE pthread PRIVATE GrAAL)