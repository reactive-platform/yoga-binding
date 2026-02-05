cmake_minimum_required(VERSION 3.27)
project(yoga_binding)

set(CMAKE_CXX_STANDARD 20)
set(LIBDIR lib)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")


macro(extract_version)
    execute_process(
       COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/get_version.sh
       OUTPUT_VARIABLE YOGA_VERSION
       OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # Formatting as 3,2,1,0
    string(REPLACE "." "," YOGA_PRODUCT_VERSION "${YOGA_VERSION},0")
endmacro()


# Adding bindings
add_library(${PROJECT_NAME} SHARED src/bindings.cpp)

# Adding windows exif metadata
extract_version()
configure_file(manifests/version.rc.in "${CMAKE_CURRENT_BINARY_DIR}/version.rc" @ONLY)
target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/version.rc")

# Adding yoga library
add_subdirectory(${LIBDIR}/yoga/yoga)

# Linking everything
target_link_libraries(${PROJECT_NAME} PUBLIC -Wl,--whole-archive yogacore -Wl,--no-whole-archive)

