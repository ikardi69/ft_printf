<h1 align="center">🖨️ ft_printf </h1>

<p align="center">
  <h1>🧾 Description</h1>
</p>

**ft\_printf** is a 42 school project that challenges you to reimplement the standard C `printf()` function. This project focuses on mastering **variadic functions**, **format parsing**, and **output formatting**—key elements in systems-level programming.

This implementation includes full support for the **mandatory conversion specifiers**, and an extensive **bonus part** that handles additional formatting flags and width/precision controls.

---

<p align="center">
  <h1>🛠️ Features</h1>
</p>

### ✅ Mandatory Support

Handles the following conversion specifiers:

* `%c` → character
* `%s` → string
* `%p` → pointer address in hexadecimal
* `%d` and `%i` → signed integers
* `%u` → unsigned decimal
* `%x` and `%X` → hexadecimal (lowercase/uppercase)
* `%%` → literal percent sign

### 🌟 Bonus Features

* Field width and precision control
* Flag support:

  * `-` (left-align)
  * `0` (zero-padding)
  * `.` (precision)
  * `#` (alternate form for hex)
  * `+` (explicit sign)
  * (space) (blank for positive numbers)

---

<p align="center">
  <h1>📂 Project Structure</h1>
</p>

```
.
├── Makefile
├── ft_printf.c              # Core printf logic
├── ft_printf.h              # Header file with function prototypes
├── b_format_handler.c       # Bonus: format specifier handling
├── ft_negative_bonus.c      # Bonus: handling negative numbers
├── ft_negative_utils_bonus.c# Bonus: utilities for negative numbers
├── ft_util_bonus.c          # Bonus: general utility functions
├── ft_util1_bonus.c         # Bonus: utility functions set 1
├── ft_util2_bonus.c         # Bonus: utility functions set 2
├── ft_util3_bonus.c         # Bonus: utility functions set 3
├── ft_util4_bonus.c         # Bonus: utility functions set 4
├── ft_util5_bonus.c         # Bonus: utility functions set 5
├── ft_util6_bonus.c         # Bonus: utility functions set 6
├── ft_util7_bonus.c         # Bonus: utility functions set 7
├── ft_util8_bonus.c         # Bonus: utility functions set 8
├── ft_zero_paddding_bonus.c # Bonus: zero-padding handling
└── .vscode/                 # VSCode configuration files
```

---

<p align="center">
  <h1>📦 Compilation</h1>
</p>

To compile the project:

```bash
make        # Builds the mandatory part
make bonus  # Builds with bonus features
```

This will generate the `libftprintf.a` static library.

---

<p align="center">
  <h1>🧪 Example Usage</h1>
</p>

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");               // Output: Hello, world!
    ft_printf("Value: %08d\n", 42);                   // Output: Value: 00000042
    ft_printf("Hex: %#x, Pointer: %p\n", 255, ptr);   // Output: Hex: 0xff, Pointer: 0x12345678
    return 0;
}
```

---

<p align="center">
  <h1>🧼 Makefile Rules</h1>
</p>

* `make` – builds `libftprintf.a`
* `make bonus` – builds with bonus features
* `make clean` – removes object files
* `make fclean` – removes object files and the library
* `make re` – full rebuild

---

<p align="center">
  <h1>🧠 What I Learned</h1>
</p>

* Variadic functions with `stdarg.h`
* Bit-level data formatting and flag parsing
* Modular and reusable code design
* Full implementation of a libc-level utility

---

<p align="center">
  <h1>📜 License</h1>
</p>

This project is part of the 42 School curriculum and is for educational purposes.

---

<p align="center">
  <h1>👤 Author</h1>
</p>

<p align="center">
  <h1>Mouhssine</h1>
</p>

<p align="center">
  <h1>1337 Student</h1>
</p>
