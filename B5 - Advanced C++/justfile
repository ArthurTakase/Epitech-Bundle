format:
    find . -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
build:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. -GNinja && ninja && cd ..
build_clang:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCLANG=ON .. -GNinja && ninja && cd ..
debug:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. -GNinja && ninja && cd ..
compile:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. -GNinja && ninja && cd ..
tests:
    mkdir -p build && cd build && cmake -DTESTS=ON -DCMAKE_BUILD_TYPE=Debug .. -GNinja && ninja && cd .. && ./build/runTests
coverage:
    just tests && gcovr -r . --exclude "build/" --exclude "tests/" --exclude "src/Client/" --exclude "src/Server/" --exclude "include/"
clear:
    rm -rf build/
re:
    just clear && clear && just build
snake:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DSNAKE=ON .. -GNinja && ninja && cd ..