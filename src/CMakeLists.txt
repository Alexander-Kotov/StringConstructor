project(StringConstructor C CXX)

set(SOURCES
    StringConstructor.cpp
    StringView.cpp
    TextGenerator.cpp)
set(HEADERS
    StringConstructor.h
    IGeneratorRegistry.h
    IGenerator.h
    StringView.h)

add_library(${PROJECT_NAME}
    STATIC
    ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME}
    ARCHIVE
    DESTINATION lib)
install(FILES ${HEADERS}
    DESTINATION include/StringConstructor)
