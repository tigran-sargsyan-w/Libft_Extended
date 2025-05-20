# Libft_Extended

`Libft_Extended` is an enhanced version of the original [*libft*](https://github.com/tigran-sargsyan-w/Libft) library. It combines multiple essential modules into a single, reusable static library — `libft.a`.  

Included modules:

- ✅ **Libft** – core standard library reimplementations  
- ✅ **ft_printf** – custom implementation of `printf`  
- ✅ **get_next_line** – function to read a line from a file descriptor  

Each module has been integrated from its original standalone repository:

- [*libft*](https://github.com/tigran-sargsyan-w/Libft)  
- [*ft_printf*](https://github.com/tigran-sargsyan-w/ft_printf)  
- [*get_next_line*](https://github.com/tigran-sargsyan-w/get_next_line)

---

## 🔧 Extended Features

Although each module was initially built as a faithful reimplementation of the standard C library functions (according to the 42 school specifications), they have since been **modernized and extended** with additional functionality:

- `libft` includes extra validation utilities and list helpers  
- `ft_printf` supports `ft_printf` — a custom version of `printf` for output to STDOUT and also supports `ft_dprintf` — a custom version of `dprintf` for output to specific file descriptors  
- `get_next_line` remains lightweight, but now integrates better with other components  

This makes **Libft_Extended** a robust base for building real-world C applications and projects.

---

## 📦 Getting Started

### 1. Clone the repository

```
git clone https://github.com/tigran-sargsyan-w/Libft_Extended.git libft
```

### 2. Build the library

Use the provided Makefile to compile all modules into `libft.a`:

```
make
```

This will generate `libft.a` in the root of the repository.

### 3. Compile your project using `libft.a`

Assuming your `main.c` is located in the root of your project:

```
cc main.c -I./libft -L./libft -lft
```

- `-I./libft` — adds the path to the header files (`libft.h`, `ft_printf.h`, `get_next_line.h`)  
- `-L./libft` — adds the path to the compiled static library  
- `-lft` — links against `libft.a` (as the compiler interprets `-lft` as `libft.a`)

---

## 📌 Notes

- `libft.a` includes all compiled code from `libft`, `ft_printf`, and `get_next_line`.
- Make sure to include the appropriate headers in your source files:

```
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
```

- Depending on your project structure, you may need to adapt `-I` and `-L` paths.

---

## 🛠️ Tip

For a simple test setup, place your `main.c` alongside the `libft` folder and compile using:

```
cc main.c libft/libft.a -Ilibft
```

---

Enjoy using **Libft_Extended** as a robust foundation for your future C projects!
