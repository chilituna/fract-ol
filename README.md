# Fract-ol

An interactive fractal visualization engine that renders complex mathematical sets in real-time.

## Overview

Fract-ol is a computer graphics project that renders three classic fractals: the Mandelbrot set, Julia sets, and the Burning Ship fractal. Built entirely in C using the MLX42 graphics library, this program demonstrates the mathematical beauty of complex number iteration while providing an intuitive interface for exploration through zooming, panning, and dynamic color mapping.

This project challenged me to optimize rendering algorithms, implement efficient event handling, and work with low-level graphics programming - all while maintaining clean, modular code architecture.

**Score: 125/100** *(bonus features implemented)*

<!--## Demo / Screenshots

```
[Add Mandelbrot set rendering screenshot]
[Add Julia set with different parameters screenshot]  
[Add Burning Ship fractal screenshot]
[Add zoomed-in detail screenshot showing recursive patterns]
```-->

## Tech Stack

- **Language:** C
- **Graphics Library:** [MLX42](https://github.com/codam-coding-college/MLX42) (Modern MiniLibX)
- **Dependencies:** GLFW, OpenGL
- **Build System:** Make
- **Custom Library:** Libft (personal C standard library implementation)

## Architecture / Implementation

### Core Components

**Fractal Calculation Engine** ([fractals.c](fract_ol/src/fractals.c))
- Iterative algorithms for Mandelbrot, Julia, and Burning Ship sets
- Escape-time algorithm with configurable maximum iterations
- Complex number arithmetic implemented from scratch

**Viewport Management** ([calc.c](fract_ol/src/calc.c))
- Coordinate transformation between screen space and complex plane
- Dynamic zoom with mouse-position targeting
- Smooth panning with keyboard/mouse controls

**Rendering Pipeline** ([color_handling.c](fract_ol/src/color_handling.c), [colors.c](fract_ol/src/colors.c))
- Pixel-by-pixel iteration mapping to RGB values
- Multiple color scheme implementations (psychedelic, golden, bubblegum)
- Real-time re-rendering on parameter changes

**Event System** ([hooks.c](fract_ol/src/hooks.c))
- MLX42 callback hooks for keyboard, mouse, and scroll events
- Responsive controls with immediate visual feedback

### Key Technical Decisions

- **Precision:** Used `double` for complex number calculations to maintain accuracy at high zoom levels
- **Optimization:** Direct pixel buffer manipulation for faster rendering compared to individual draw calls
- **Modularity:** Separated fractal algorithms from rendering logic for easy extensibility
- **Input Validation:** Robust parameter checking for Julia set coordinates

## Features

- ✨ Three fractal types: Mandelbrot, Julia (customizable), and Burning Ship
- 🔍 Infinite zoom with mouse cursor targeting
- ⌨️ Keyboard controls for precise navigation
- 🎨 Multiple dynamic color schemes
- 🖱️ Interactive parameter adjustment (Julia coordinates via mouse click)
- 🪟 Clean 800x800 rendering window
- 🎯 Input validation and error handling
- 🚀 Real-time rendering with smooth interaction

## Getting Started

### Prerequisites

- GCC or Clang compiler
- CMake (for building MLX42)
- GLFW library
- Linux or macOS (Unix-based system)

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/chilituna/fract-ol.git
   cd fract-ol/fract_ol
   ```

2. **Download and build MLX42 library:**
   ```bash
   make mlx
   ```

3. **Compile the project:**
   ```bash
   make
   ```

### Usage

Run the program with one of the following commands:

**Mandelbrot set:**
```bash
./fractol m
```

**Julia set** *(requires real and imaginary parameters between -2 and 2):*
```bash
./fractol j <real> <imaginary>
# Example: ./fractol j -0.4 0.6
```

**Burning Ship fractal:**
```bash
./fractol b
```

### Controls

| Action | Control |
|--------|---------|
| Zoom to mouse position | Scroll wheel |
| Move fractal | Arrow keys |
| Cycle color schemes | Space |
| Get Julia coordinates | Click on fractal |
| Exit program | ESC or close window |

## Project Structure

```
fract_ol/
├── includes/
│   └── fractol.h           # Main header with structs and function prototypes
├── src/
│   ├── main.c              # Entry point and MLX initialization
│   ├── fractals.c          # Fractal calculation algorithms
│   ├── calc.c              # Coordinate transformations and zoom logic
│   ├── hooks.c             # Event handling callbacks
│   ├── color_handling.c    # Color mapping and pixel rendering
│   ├── colors.c            # Color scheme implementations
│   ├── init.c              # Fractal and window initialization
│   ├── check.c             # Input validation
│   └── error_and_exit.c    # Error handling and cleanup
├── Libft/                  # Custom C library implementation
├── Makefile                # Build configuration
└── icons/                  # Application icons
```

## Future Improvements

- [ ] Add more fractal types (Newton, Tricorn, etc.)
- [ ] Implement parallel rendering with threading for faster performance
- [ ] Add fractal animation/evolution over time
- [ ] Export high-resolution images to file
- [ ] GUI overlay for parameter adjustment
- [ ] Color gradient editor
- [ ] Variable iteration depth based on zoom level
- [ ] Smooth color interpolation for anti-aliasing

## What I Learned

This project was my introduction to computer graphics programming and reinforced several fundamental concepts:

- **Complex Number Mathematics:** Implementing iterative formulas and understanding escape-time algorithms
- **Graphics Programming:** Working with pixel buffers, color spaces, and efficient rendering techniques
- **Event-Driven Architecture:** Designing responsive user interfaces with callback systems
- **Coordinate Systems:** Translating between screen coordinates and mathematical planes
- **Algorithm Optimization:** Balancing visual quality with computational performance
- **Memory Management:** Proper allocation, deallocation, and avoiding leaks in C
- **Modular Design:** Structuring code for maintainability and extensibility

---

*This project was completed as part of the 42 School curriculum, achieving full marks with bonus features.*
