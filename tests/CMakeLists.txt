project(tests C CXX)

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

set(SOURCES
    StringConstructor.cpp
    StringView.cpp
    GeneratorRegistry.cpp)

add_executable(${PROJECT_NAME}
    ${SOURCES})
target_link_libraries(${PROJECT_NAME}
    StringConstructor
    LIBGTEST
    LIBGMOCK)

add_test(NAME StringConstructor
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})

