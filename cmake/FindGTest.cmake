find_package (Threads)

if (NOT TARGET LIBGTEST)
    add_library(LIBGTEST STATIC IMPORTED GLOBAL)
    set_target_properties(LIBGTEST PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/external/gtest/include
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/external/gtest/lib/libgtest.a
        IMPORTED_LINK_INTERFACE_LIBRARIES "${CMAKE_SOURCE_DIR}/external/gtest/lib/libgtest_main.a;${CMAKE_THREAD_LIBS_INIT}")
endif()
