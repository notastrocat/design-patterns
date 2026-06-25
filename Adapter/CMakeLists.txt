cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-adapter)
    add_library(dp-adapter SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Adapter.cc"
    )
    target_include_directories(dp-adapter PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-adapter LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Adapter.hpp DESTINATION "${INSTALL_PREFIX}/include")
