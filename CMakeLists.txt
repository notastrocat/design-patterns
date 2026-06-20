cmake_minimum_required(VERSION 3.10)

project(design-patterns-cpp)

message(STATUS "------------------------------")
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "CMake generator: ${CMAKE_GENERATOR}")
message(STATUS "CMake generator platform: ${CMAKE_GENERATOR_PLATFORM}")
message(STATUS "C COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "C++ COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "------------------------------")

set(CMAKE_CXX_STANDARD 20)

set(INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

add_subdirectory(Decorator)

add_executable(main main.cc)
target_link_libraries(main dp-decorator)

install(TARGETS main RUNTIME DESTINATION "${INSTALL_PREFIX}/bin")
