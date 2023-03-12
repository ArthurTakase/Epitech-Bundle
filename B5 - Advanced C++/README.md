# {EPITECH} | Third year | Network | OOP | R-Type

## About the project

This project aims to recreate the cross-platform video game R-Type with an online mutiplayer mode.
It required the implementation of a multithreaded server and a graphical client, using an engine of our own design.

- `Tools:`
  - Project made in `C++` version 20
  - use of the `SFML` graphical library to display game elements
  - Compiled with `CMake`, minimum version required : `3.17`
  - `Google Test` for unit tests
  - `Doxygen` for documentation
  - A `justfile` is provided to compile, run and test the project

- Some of the features we implemented:
  - A `multithreaded` server, to handle communication and game logic at the same time
  - A graphical client, to display the game and handle user input
  - A generic `Entity Component System` architecture and game engine
  - A encapsulated implementation of an `UDP socket`, compatible with Linux and Windows
  - A client-server communication protocol

For further details about the implementation of these notions, you can click [here](https://arthurtakase.github.io/R-Type/) to be redirected to our documentation.

## Usage

- For Linux users, check out our [Usage for Linux users](docs/UsageLinux.md) guide.
- For Windows users, check out our [Usage for Windows users](docs/UsageWindows.md) guide.

## Documentation

- ECS architecture graph : [documentation](docs/ECS.md)
- Client protocol graph : [documentation](docs/ClientProtocol.md)
- Server protocol graph : [documentation](docs/ServerProtocol.md)

Our complete documentation can be found [here](https://arthurtakase.github.io/R-Type/).

## Game improvements

- Want to contribute to the project ? Check out our [Contributor's guide](docs/Contributor.md) !
- Want to create your own custom levels ? Check out our [Level's guide](docs/CustomLevel.md) !

## Continuous integration/Continuous Deployment

- Automatic build on `main` and `develop` branches.
- Running Google Test unit tests on `main` and `develop` branches.
- Generating coverage on `main` and `develop` branches.
- Automatic generation of Doxygen documentation on `main` and `develop` branches accessible [here](https://arthurtakase.github.io/R-Type/).
- Sending a discord message on push/merge on all branches.

Project made by [Arthur D.](https://github.com/ArthurTakase), [Solène L.](https://github.com/slefeu), [Corentin R.](https://github.com/roy-corentin), [Geoffrey L.](https://github.com/GeoffreyLabruyere) and [Guillaume V.](https://github.com/GuillaumeVernizeau)
