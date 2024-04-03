# Pong
A pong recreation with a server.
## Getting Started

### Dependencies
The system requirements for running on a Window are:
* Compiler: [MinGW](https://code.visualstudio.com/docs/languages/cpp)
  * If another compiler is used, update the Makefile compiler to your compiler
* [SDL2](https://www.libsdl.org/)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
* [SDL2_ttf](https://www.libsdl.org/projects/docs/SDL_ttf/SDL_ttf.html)

### Installation

1. Clone the repo
    ```sh
    git clone https://github.com/katrina-viray/pong.git
    ```
2. Download SDL2 libraries and link them to your project
  [Tutorial](https://www.youtube.com/watch?v=H08t6gD1Y1E)
  [Tutorial 2](https://www.youtube.com/watch?v=9Ca-RVPwnBE)

### Executing program

1. Compile the program into an executable
```
make or use "g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2" in the terminal
```
2. Run the executable
```
./main
```

## Acknowledgments

Special Thanks!
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)