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
for f in bin/lib*.dll; do
    [ -f "$f" ] && cp "$f" "$BUILD_DIR"
done

echo "Build finished."
