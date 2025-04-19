cmake_minimum_required(VERSION 3.27)
project(yoga_binding)

set(CMAKE_CXX_STANDARD 20)
set(LIBDIR lib)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

#adding bindings
add_library(${PROJECT_NAME} SHARED src/bindings.cpp)
#adding yoga library
add_subdirectory(${LIBDIR}/yoga/yoga)
#linking everything
target_link_libraries(${PROJECT_NAME} PUBLIC -Wl,--whole-archive yogacore -Wl,--no-whole-archive)

