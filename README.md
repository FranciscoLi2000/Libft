# Libft

[![License: MIT](https://img.shields.io/github/license/FranciscoLi2000/Libft)](LICENSE)
[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build: make](https://img.shields.io/badge/build-make-brightgreen)](https://www.gnu.org/software/make/)

## Table of Contents
- [Project Introduction](#project-introduction)
- [Tech Stack](#tech-stack)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing Guide](#contributing-guide)
- [License](#license)

## Project Introduction
Libft is a reusable C static library that reimplements common libc functions and provides utility helpers plus bonus linked-list tools for building future C projects faster and more consistently.

## Tech Stack
- C (C89/C99-compatible style)
- Makefile build system
- POSIX environment (Linux/macOS)

## Project Structure
```text
.
├── includes/               # Public headers
│   ├── libft.h
│   └── libft_bonus.h
├── src/                    # Part 1 + Part 2 implementations
├── bonus/                  # Bonus linked-list functions
├── test/                   # Sample test entry
│   └── main.c
├── Makefile
└── README.md
```

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/FranciscoLi2000/Libft.git
   cd Libft
   ```
2. Build the base library:
   ```bash
   make
   ```
3. (Optional) Build bonus functions:
   ```bash
   make bonus
   ```
4. (Optional) Clean build artifacts:
   ```bash
   make clean
   make fclean
   ```

## Usage
1. Link the static library in your project:
   ```bash
   cc your_main.c -Iincludes -L. -lft -o your_app
   ```
2. Include the header you need:
   ```c
   #include "libft.h"
   ```
3. Typical workflow:
   - Build `libft.a` with `make` (and `make bonus` if needed).
   - Compile your project against the library with `-Iincludes -L. -lft`.

## Testing
The repository includes a sample test entry in `test/main.c`:
```bash
make re
make bonus
cc -Wall -Wextra -Werror test/main.c -Iincludes -L. -lft -o test/main
./test/main
```

## Contributing Guide
Contributions are welcome!
- Open an issue to report bugs or suggest enhancements.
- Fork the repository and create a feature branch.
- Keep changes focused and follow the existing coding style (`-Wall -Wextra -Werror`).
- Submit a pull request with a clear description of your changes and testing performed.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
