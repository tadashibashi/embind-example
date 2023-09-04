# Minimal Embind Example

Converting a C++ Class to JavaScript

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![TypeScript](https://img.shields.io/badge/typescript-%23007ACC.svg?style=for-the-badge&logo=typescript&logoColor=white)
![JavaScript](https://img.shields.io/badge/javascript-%23323330.svg?style=for-the-badge&logo=javascript&logoColor=%23F7DF1E)

A working example of embind from the Emscripten docs using 
an automated build process via CMake, and a quick test run 
in Node.js

Corresponding TypeScript definitions are auto-generated using
the latest --embind-emit-tsd functionality. You may need to update
emscripten if it's not available.

## Getting Started

### Requirements

- Emscripten (tested on v3.1.45)

### Steps

1. create the build folder e.g. `mkdir build`
2. `cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=<path-to-emscripten>/cmake/Modules/Platform/Emscripten.cmake`
3. Running `cmake --build build --target embind_test` will generate files in lib/embind_test
4. To run a quick test in Node.js, run `npm install` then `npm run start`
5. If '4' and 'hello world!' appear in the console, it was a success!

Please check the Embind docs for further info: 
https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html
