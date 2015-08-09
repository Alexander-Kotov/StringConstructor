if (NOT TARGET LIBGMOCK)
    add_library(LIBGMOCK STATIC IMPORTED GLOBAL)
    set_target_properties(LIBGMOCK PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/external/gmock/include
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/external/gmock/lib/libgmock.a
        IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_SOURCE_DIR}/external/gmock/lib/libgmock_main.a)
endif()
