cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-strategy)
    # include_directories("${CMAKE_CURRENT_LIST_DIR}/../utils")
    add_library(dp-strategy SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Strategy.cc"
    )
    target_include_directories(dp-strategy PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-strategy LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Strategy.hpp DESTINATION "${INSTALL_PREFIX}/include")
