# Usage for Windows users

## Build Windows

```bat
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
mv .\build\Debug\r-type_client.exe ./build
mv .\build\Debug\r-type_server.exe ./build
mv .\build\_deps\sfml-build\bin\Debug\sfml-audio-d-3.dll ./build
mv .\build\_deps\sfml-build\bin\Debug\sfml-network-d-3.dll ./build
mv .\build\_deps\sfml-build\bin\Debug\sfml-graphics-d-3.dll ./build
mv .\build\_deps\sfml-build\bin\Debug\sfml-system-d-3.dll ./build
mv .\build\_deps\sfml-build\bin\Debug\sfml-window-d-3.dll ./build
mv .\build\_deps\sfml-src\extlibs\bin\x64\openal32.dll ./build
```

If you have a 32 bits system, you need to run the following command:

```bat
mv .\build\_deps\sfml-src\extlibs\bin\x86\openal32.dll ./build
```

## Run Windows

Launch .exe `r-type_client.exe` and `r-type_server.exe`
