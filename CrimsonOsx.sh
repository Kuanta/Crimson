#!/usr/bin/env bash

# Basit kullanım: ./CrimsonOsx.sh Debug  veya  ./CrimsonOsx.sh Release
# (Conan 2.x için düzenlenmiştir)

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <Debug|Release>"
    exit 1
fi

BUILD_TYPE=$1
TARGET_DIR="Targets/$BUILD_TYPE"

# 1) Hedef klasörü oluştur (varsa atlar)
mkdir -p "$TARGET_DIR"

# 2) Conan (2.x) ile bağımlılıkları indir/kur
# -b missing --> eğer paket binary'si yoksa, kaynak koddan derle
# -s build_type=$BUILD_TYPE --> Debug mı Release mi?
# -g CMakeDeps ve -g CMakeToolchain, conan_toolchain.cmake vb. dosyaları oluşturur
conan install . \
  -of="$TARGET_DIR" \
  -b missing \
  -s build_type="$BUILD_TYPE" \
  -c tools.system.package_manager:sudo=True \
  -c tools.system.package_manager:mode=install \
  -g CMakeDeps \
  -g CMakeToolchain

# 3) CMake konfigürasyonu
# CMAKE_TOOLCHAIN_FILE -> conan_toolchain.cmake (Conan 2.x default)
cmake -S . -B "$TARGET_DIR" \
  -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
  -DCMAKE_TOOLCHAIN_FILE="$TARGET_DIR/conan_toolchain.cmake"

# 4) Compile
cmake --build "$TARGET_DIR" --config "$BUILD_TYPE"
