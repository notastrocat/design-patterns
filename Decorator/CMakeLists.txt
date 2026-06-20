cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET dp-decorator)
    add_library(dp-decorator SHARED
        "${CMAKE_CURRENT_LIST_DIR}/Decorator.cc"
    )
    target_include_directories(dp-decorator PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS dp-decorator LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES Decorator.hpp DESTINATION "${INSTALL_PREFIX}/include")
