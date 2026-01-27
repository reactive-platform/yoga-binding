PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
TOOLCHAIN_FILE="$PROJECT_ROOT/windows-toolchain.cmake"

if [ ! -f "$TOOLCHAIN_FILE" ]; then
    echo "$TOOLCHAIN_FILE does not exist!"
    exit 1
fi

mkdir -p bin
cmake "$PROJECT_ROOT" --toolchain="$TOOLCHAIN_FILE" -B bin
cmake --build bin

mkdir -p "$BUILD_DIR"
cp bin/libyoga_binding.dll build/yoga.dll

echo "Build finished."
