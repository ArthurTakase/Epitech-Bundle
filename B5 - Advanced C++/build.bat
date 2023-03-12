rmdir build
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build