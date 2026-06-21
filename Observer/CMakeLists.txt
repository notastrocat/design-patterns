cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-observer)
    # include_directories("${CMAKE_CURRENT_LIST_DIR}/../utils")
    add_library(dp-observer SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Observer.cc"
    )
    target_include_directories(dp-observer PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-observer LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Observer.hpp DESTINATION "${INSTALL_PREFIX}/include")
