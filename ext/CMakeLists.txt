if(CMAKE_VERSION VERSION_LESS "3.11")
    include(ExternalProject)
    ExternalProject_Add(
        SFML
        URL https://github.com/SFML/SFML/archive/refs/tags/2.5.1.tar.gz
        CMAKE_ARGS
            -DBUILD_SHARED_LIBS=OFF
            -DSFML_BUILD_AUDIO=OFF
            -DSFML_BUILD_NETWORK=OFF
            -DSFML_BUILD_EXAMPLES=OFF
            -DSFML_BUILD_TESTS=OFF
            -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    )
    ExternalProject_Get_Property(SFML install_dir)
    set(SFML_INCLUDE_DIR ${install_dir}/include)
    set(SFML_LIBRARIES ${install_dir}/lib/libsfml-graphics.a)
else()
    set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/ext)
    include(FetchContent)

    if(TARGET SFML::Graphics)
        message(STATUS "SFML::Graphics target EXISTS")
    else()
        message(STATUS "SFML::Graphics target NOT FOUND")
    endif()
    get_target_property(SFML_LOCATION SFML::Graphics LOCATION)
    message(STATUS "SFML::Graphics location: ${SFML_LOCATION}")
    if(NOT SFML_FOUND)
        message(STATUS "SFML 3.0.2 not found - downloading dependency")
        FetchContent_Declare(
            SFML
            GIT_REPOSITORY https://github.com/SFML/SFML.git
            GIT_TAG 3.0.2
        )
        #Set options for SFML
        set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
        set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
        set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
        set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
        set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(SFML)
        set(SFML_FOUND TRUE PARENT_SCOPE)
    else()
        message(STATUS "Found SFML version: ${SFML_VERSION}")
        message(STATUS "SFML include dir: ${SFML_INCLUDE_DIR}")
        message(STATUS "SFML libraries: ${SFML_LIBRARIES}")
        message(STATUS "SFML_FOUND: ${SFML_FOUND}")
        message(STATUS "SFML_GRAPHICS_FOUND: ${SFML_GRAPHICS_FOUND}")
        message(STATUS "SFML_WINDOW_FOUND: ${SFML_WINDOW_FOUND}")
        message(STATUS "SFML_SYSTEM_FOUND: ${SFML_SYSTEM_FOUND}")
    endif()
endif()