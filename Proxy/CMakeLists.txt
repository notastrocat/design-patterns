cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-proxy)
    add_library(dp-proxy SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Proxy.cc"
    )
    target_include_directories(dp-proxy PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-proxy LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Proxy.hpp DESTINATION "${INSTALL_PREFIX}/include")
