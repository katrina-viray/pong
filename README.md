# Pong
A pong recreation with a server.
## Getting Started

### Dependencies
The system requirements for running on Windows are on Visual Studio Code are:
* IDE: [VSCode](https://code.visualstudio.com/docs/languages/cpp)
* Compiler: [MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites)
  * If another compiler is used, update the Makefile compiler to your compiler
  * Ensure you run VSCode from the Developer Command Prompt for VS
* [SDL2](https://www.libsdl.org/)
* [SDL2_image](https://github.com/libsdl-org/SDL_image)

### Installation

1. Clone the repo
    ```sh
    git clone https://github.com/katrina-viray/pong.git
    ```
2. Download SDL2 libraries and link them to your project
  [Tutorial](https://www.youtube.com/watch?v=9Ca-RVPwnBE)

### Executing program

1. Compile the program into an executable
```
make or use "	g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image" in the terminal
```
2. Run the executable
```
./main
```

## Acknowledgments

Special Thanks!
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)