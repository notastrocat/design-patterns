cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-factory)
    # include_directories("${CMAKE_CURRENT_LIST_DIR}/../utils")
    add_library(dp-factory SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Factory.cc"
    )
    target_include_directories(dp-factory PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-factory LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Factory.hpp DESTINATION "${INSTALL_PREFIX}/include")
