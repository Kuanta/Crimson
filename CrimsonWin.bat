@echo off
set BUILD_TYPE=%1
set TARGET_DIR=Targets\%BUILD_TYPE%

CALL %USERPROFILE%\anaconda3\Scripts\activate.bat
CALL conda activate crimson

REM 1) Hedef klasörü oluştur
mkdir %TARGET_DIR%

REM Conan install (C++17 + Ninja)
conan install . -of=%TARGET_DIR% -b missing -s build_type=%BUILD_TYPE% -s compiler.cppstd=17 -g CMakeDeps -g CMakeToolchain

REM 3) CMake konfigürasyonu
cmake -S . -B %TARGET_DIR% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_TOOLCHAIN_FILE=%TARGET_DIR%\conan_toolchain.cmake

REM 4) Build
cmake --build %TARGET_DIR% --config %BUILD_TYPE%