set(CONTENT_RES_SOURCES
    Configuration.cpp
    Resources.cpp
)

set(CONTENT_RES_HEADERS
    Configuration.h
    Resources.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
)

add_library(android.content.res OBJECT ${CONTENT_RES_HEADERS} ${CONTENT_RES_SOURCES})
