# L-System Visualiser

This project is an L-System Visualiser written in C++ using the SFML library. It allows users to generate and visualise different fractal patterns based on [L-System algorithms](https://www1.biologie.uni-hamburg.de/b-online/e28_3/lsys.html). The application also includes a UI for real-time interaction and customization of the fractals.

![Short GIF of LSystem generation](https://cameronmain.com/wp-content/uploads/2023/11/LSystemDemoShort.gif)


## Features

- Generate complex fractal structures from a simple axiom with an L-System algorithm.
- Interactive UI to change and apply different predefined fractal settings.
- Render fractal patterns in real-time using SFML LineStrips.
- Extendable codebase for adding new fractal definitions and rules.

## Getting Started

### Prerequisites

- SFML SDK 2.6 or later
- ImGui-SFML for UI components
- A C++17 capable compiler

### Installation
1. Clone the repository:
```git clone https://github.com/cameronmain/l-system-visualizer.git```
2. Navigate to the cloned repository directory.
3. Open and build in Visual Studio or compile the project with CMake:
`mkdir build && cd build` 
`cmake .. `
`make`

4. Run the executable generated in the `build` directory.

## Usage

- Launch the application.
- Use the UI to select from predefined fractal settings or create your own.
- Adjust the number of iterations to see changes in fractal complexity.
- Click "Generate" to apply the settings and visualize the fractal.

## License

Copyright (c) 2023 Cameron Main
Released under the MIT license

