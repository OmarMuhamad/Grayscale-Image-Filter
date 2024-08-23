
---

# Grayscale Image Filter Program

## Overview

This C++ program allows users to apply various filters to grayscale images. The program reads image data from a text file, processes the image based on the selected filter, and then outputs the modified image to a new text file.

## Features

- **Load and Save Image**: Load a grayscale image from a file and save the modified image to a file.
- **Image Filters**:
  - **Rotate**: Rotate the image either 90 degrees clockwise or counterclockwise.
  - **Invert**: Invert the grayscale values of the image.
  - **Merge**: Merge two images into one.
  - **Enlarge**: Enlarge a specific quarter of the image.
  - **Shrink**: Shrink the image by a factor of 2, 3, or 4.
  - **Shuffle**: Shuffle the four quarters of the image.
  - **Edge Detection**: Detect edges in the image using a Sobel filter.
  - **Mirror**: Mirror the image either horizontally or vertically.
  - **Darken/Lighten**: Darken or lighten the image.
  - **Detect Image**: Detect shapes or patterns within the image.

## Requirements

- A C++ compiler (e.g., GCC, Clang, MSVC)
- Text files containing grayscale image data (images are represented as 2D arrays of integers ranging from 0 to 255)

## Usage

1. **Compile the Program**: Use a C++ compiler to compile the source code.
   ```bash
   g++ -o image_filter image_filter.cpp
   ```

2. **Run the Program**: Execute the compiled program.
   ```bash
   ./image_filter
   ```

3. **Follow the Prompts**: The program will guide you through loading an image, selecting a filter, and saving the modified image.

## File Format

The program expects the input image file to be a plain text file where each line represents a row of pixel values, separated by spaces. The pixel values should range from 0 (black) to 255 (white).

Example of a 5x5 grayscale image file:
```
0 255 100 100 0
50 100 150 200 250
255 255 255 255 255
0 0 0 0 0
100 50 0 50 100
```

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request. We welcome all improvements and suggestions!

## Authors

- Omar Mohammed
- Ahmed Gehad
- Hazem Amr

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
