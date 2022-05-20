# imgui-sfml-glad-template

A template project using [ImGui](https://github.com/ocornut/imgui) (docking branch) with [SFML](https://www.sfml-dev.org/) using [ImGui-SFML](https://github.com/eliasdaler/imgui-sfml) and [GLAD](https://glad.dav1d.de/).

Also includes [mimalloc](https://github.com/microsoft/mimalloc) for fast allocators and [PLOG](https://github.com/SergiusTheBest/plog) for logging.

Compiles using **CMake** + **CMake Tools** through **Visual Studio Code**. (`Ctrl+Shift+B` to build after running `CMake: Configure` for initial setup)

> Make sure to update the compilerPath setting in `.vscode/c_cpp_properties.json` to a valid path on your system

The output binary and required files will be in `./build/<TARGET>/bin/` (These all need to be manually specified on the CMake build script)
