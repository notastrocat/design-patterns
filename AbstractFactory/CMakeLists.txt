cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-abstract-factory)
    # include_directories("${CMAKE_CURRENT_LIST_DIR}/../utils")
    add_library(dp-abstract-factory SHARED
        "${CMAKE_CURRENT_LIST_DIR}/AbstractFactory.cc"
    )
    target_include_directories(dp-abstract-factory PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-abstract-factory LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES AbstractFactory.hpp DESTINATION "${INSTALL_PREFIX}/include")
