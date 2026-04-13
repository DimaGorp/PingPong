set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/ext)
include(FetchContent)

if(NOT SFML_FOUND)
    message(STATUS "SFML 3.0.2 not found - downloading dependency")
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
    )
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
    set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
    set(SFML_FOUND TRUE PARENT_SCOPE)
else()
    message(STATUS "Found SFML version: ${SFML_VERSION}")
endif()