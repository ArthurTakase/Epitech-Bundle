# Contributor's guide

If you want to contribute to the project, here is a few things you will need to know beforehand.

## Commit norm

We have a commit norm to keep the project clean and easy to read. Please follow this format when you commit.

| Name | Explanation                                                            |
| ---- | ---------------------------------------------------------------------- |
| ADD  | If you add files, features...                                          |
| FIX  | If you were working on a bug or any form of default that you corrected |
| DEL  | If you removed files, features...                                      |
| UP   | If you change something without adding any features or content         |

Example:

```cpp
git commit -m "FIX:" no collision on same entity
git commit -m "UP:" remove useless print in MusicSystem.cpp file
`````

## Documentation

Each function must be documented using Doxygen. For proper documentation generation, please put comments above your functions using the following format:

```cpp
/**
 * @brief Description of the function's behavior
 *
 * @param parameter1 description of the parameter
 * @param parameter2 description of the parameter
 *
 * @return explanation of the return value
 */
```

You can install the extension [Mintlify Doc Writer](https://marketplace.visualstudio.com/items?itemName=mintlify.document) for Visual Studio Code to help you with the documentation, as it follows this format already.

## Testing Policy

Every function must have at least one unit test. The tests work with [Google Test](https://github.com/google/googletest), click [here](http://google.github.io/googletest/) to see a beginner's user guide.

To run our tests you can do the following:

```bash
    mkdir -p build && just test
```
