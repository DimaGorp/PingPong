if(CMAKE_VERSION VERSION_LESS "3.11")
    include(ExternalProject)
    ExternalProject_Add(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.1
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

    find_package(SFML 3.0.2 QUIET COMPONENTS Graphics)
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
    endif()
endif()