# Usage for Linux users

## Release usage

- Download the latest `linux.zip` [here](https://github.com/ArthurTakase/R-Type/releases)
- Unzip the file
- Move to the `build` folder :

```bash
cd build
```

- Launch the server with LD_LIBRARY_PATH :

```bash
LD_LIBRARY_PATH=src/Serializer:src/Tools:src/Time:src/Lib:src/ECS:src/Error:src/Json:_deps/sfml-build/lib ./r-type_server
```

- Launch a client with LD_LIBRARY_PATH :

```bash
LD_LIBRARY_PATH=src/Serializer:src/Tools:src/Time:src/Lib:src/ECS:src/Error:src/Json:_deps/sfml-build/lib ./r-type_client
```

If .so are missing, try to install the following packages

- xorg-dev
- libudev-dev
- libopenal-dev
- libvorbis-dev
- libflac-dev

## Build

- Debug mode: `just debug`
- Release mode: `just build`

Be careful, if you want to use the `justfile`, you need to install [just](https://just.systems/man/en/), you can do it with the following command:

```bash
cargo install just
```

## Run

/!\ If you want your game to launch, you need to have one server and at least one client running.

- Launch a client:

```bash
cd build && ./r-type_client
```

or

```bash
cd build && ./r-type_client [server port] [server ip] [client port]
```

- Launch the server:

```bash
cd build && ./r-type_server
```
