PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
ARCH="${1:-x64}"

case "$ARCH" in
    x64)
        TOOLCHAIN_FILE="$PROJECT_ROOT/windows-toolchain.cmake"
        OUTPUT_DIR="$BUILD_DIR"
        ;;
    arm64)
        TOOLCHAIN_FILE="$PROJECT_ROOT/windows-arm64-toolchain.cmake"
        OUTPUT_DIR="$BUILD_DIR/arm64"
        ;;
    *)
        echo "Unknown architecture: $ARCH (expected x64 or arm64)"
        exit 1
        ;;
esac

if [ ! -f "$TOOLCHAIN_FILE" ]; then
    echo "$TOOLCHAIN_FILE does not exist!"
    exit 1
fi

BIN_DIR="$PROJECT_ROOT/bin/$ARCH"

mkdir -p "$BIN_DIR"
cmake "$PROJECT_ROOT" --toolchain="$TOOLCHAIN_FILE" -B "$BIN_DIR"
cmake --build "$BIN_DIR"

mkdir -p "$OUTPUT_DIR"
cp "$BIN_DIR/libyoga_binding.dll" "$OUTPUT_DIR/yoga.dll"

(cd "$PROJECT_ROOT" && bash -e get_version.sh > "$BUILD_DIR/VERSION")

echo "Build finished ($ARCH)."
