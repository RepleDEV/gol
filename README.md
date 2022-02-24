# Game of Life (C++ / WASM implementation)
Thought I'd make a more practical implementation of [this thing](https://github.com/edwinm/game-of-life).

## Building
Must have [emscripten](https://emscripten.org/) `emcc` ready.

First, clone the wasm repository.
```bash
$ git clone https://github.com/emscripten-core/emsdk.git ./wasm
```
Then, build using `em++`.
```bash
$ em++ -lembind -o ./out/out.js ./cpp/wasm.cpp -s MODULARIZE=1
```
Out directory must be in `./out/` bc js wont work otherwise.  
Also the `-s MODULARIZE=1`.

# Testing
For testing, mocha is used (though tests are currently limited).
```bash
$ npm test
```