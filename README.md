# Libft_Extended

`Libft_Extended` is an enhanced version of the original `libft` library, combining additional functionalities for future projects. It includes:

- **Core libft functions**  
  Original `libft` repository: [libft](https://github.com/tigran-sargsyan-w/Libft)

- **ft_printf**  
  A custom implementation of the standard `printf` function.  
  Original `ft_printf` repository: [ft_printf](https://github.com/tigran-sargsyan-w/ft_printf)

- **get_next_line**  
  A function to read a line from a file descriptor.  
  Original `get_next_line` repository: [get_next_line](https://github.com/tigran-sargsyan-w/get_next_line)

All these modules are compiled into a single static library called **`libft.a`**.

---

## Getting Started

1. **Clone the Repository**
   ```bash
   git clone https://github.com/tigran-sargsyan-w/Libft_Extended.git libft
   ```
2. Usage in Your Project
    - **Place your `main.c`** (or other source files) in the same directory (or wherever you prefer).
    - **Compile** your code against `libft.a`. For example, if your `main.c` is in the same directory as `libft.a`, you can run:
     

   ```bash
   cc main.c -L./libft -lft
   ```
    - `-L./libft` tells the compiler where to look for the library (`libft.a`).
    - `-lft` links against `libft.a` (the compiler automatically adds the `lib` prefix and the `.a` extension).
    - You may also need to include the header paths with `-I./libft` (or similar) if your headers (`libft.h`, `ft_printf.h`, `get_next_line.h`) reside in subdirectories.

## Notes

- `libft.a` is a static library that contains all functions from **libft**, **ft_printf**, and **get_next_line**.
- Make sure to include the correct headers (`libft.h`, `ft_printf.h`, `get_next_line.h`) in your source files.
- You may need to add `-I./libft` or similar include paths depending on how you organize your includes.

Enjoy using **Libft_Extended** for your future C projects!

