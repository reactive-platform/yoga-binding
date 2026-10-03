set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR ARM64)

# llvm-mingw (https://github.com/mstorsjo/llvm-mingw)
set(CMAKE_C_COMPILER aarch64-w64-mingw32-clang)
set(CMAKE_CXX_COMPILER aarch64-w64-mingw32-clang++)

set(CMAKE_RC_COMPILER aarch64-w64-mingw32-windres)
