# ft_printf | psviatus@student.42berlin.de

This project has been created as part of the 42 curriculum by psviatus

### Table of Contents

* [1. Description](#1-description)
    * [1.1 Supported Format Specifiers and Flags](#11-supported-format-specifiers-and-flags)
    * [1.2 Mandatory Part: Core `ft_printf`](#12-description---mandatory-part-core-ft_printf)
    * [1.3 Bonus Part: Core Modifiers and Advanced Flags](#13-description---bonus-part-core-modifiers-and-advanced-flags)
* [2. Installation](#2-installation)
* [3. Resources](#3-resources)
    * [3.1 Third-Party Testers](#31-hird-party-testers)
    * [3.2 Useful Links](#32-useful-links)
* [4. Additional section](#4-additional-section)
    * [4.1 Functions](#41-functions)
    * [4.2 Bonus Structure](#42-bonus-structureexclamation)
* [Summary](#summary)

## 1. Description

**ft_printf** ft_printf is a custom implementation of the standard C library function `printf`. 

The project's goals are: 

- learn (`va_list`); 

- learn the logic of format specifier parsing; 

- learn how to build and debug large-scale projects.

### 1. Description - Supported Format Specifiers and Flags

This project is logically divided into two distinct parts: **Mandatory** and **Bonus**, which are compiled **separately!!!**

### 1.2 Description - Mandatory Part: Core `ft_printf`

Format structure: `%[Specifier]`

| Specifier | Type | Purpose |
| :-------: | :--- | :---------: |
| `c` | char | Prints a single character. |
| `s` | string | Prints a string (handles `(null)`). |
| `p` | pointer | Prints the memory address in lowercase hexadecimal (prefix `0x`). |
| `d`, `i` | integer | Prints a signed decimal integer (`int`). |
| `u` | unsigned int | Prints an unsigned decimal integer. |
| `x` | hex (lower) | Prints an unsigned number in lowercase hexadecimal (a-f). |
| `X` | hex (upper) | Prints an unsigned number in uppercase hexadecimal (A-F). |
| `%%` | percent | Prints the percent character `%`. |

### 1.3 Description - Bonus Part: Core Modifiers and Advanced Flags

Format structure: `%[Flags][Width][.Precision][Specifier]`

| Specifier | Type | Purpose |
| :-------: | :--- | :---------: |
| `c` | char | Prints a single character. |
| `s` | string | Prints a string (handles `(null)`). |
| `p` | pointer | Prints the memory address in lowercase hexadecimal (prefix `0x`). |
| `d`, `i` | integer | Prints a signed decimal integer (`int`). |
| `u` | unsigned int | Prints an unsigned decimal integer. |
| `x` | hex (lower) | Prints an unsigned number in lowercase hexadecimal (a-f). |
| `X` | hex (upper) | Prints an unsigned number in uppercase hexadecimal (A-F). |
| `%%` | percent | Prints the percent character `%`. |

| Modifier | Name | Purpose |
| :------: | :---: | :--------- |
| **(Width)** | Minimum Field Width | The minimum number of characters the output should occupy. Default padding is spaces on the left. |
| **(Precision)** | Precision | For `s`: maximum string length. For numbers: minimum number of digits (padded with `0`s). |
| **`*`** | Dynamic Argument | Indicates that Width or Precision will be specified using the next `va_list` argument (Bonus). |
| **`-`** | Left Justification | Pads the text with spaces on the right (overrides `0`). |
| **`0`** | Zero Padding | Pads the output with zeroes instead of spaces (for numeric types; ignored if Precision is set). |
| **`.`** | Precision Separator | Used to define the Precision field. |

| Bonus Flag | Purpose |
| :--------: | :---------: |
| **`#`** | Hex Prefix | Adds `0x` or `0X` prefix to non-zero hexadecimal numbers (`x`, `X`). |
| **` `** | Space Sign | Adds a space before positive numbers (ignored if `+` is present). |
| **`+`** | Forced Sign | Adds a plus sign (`+`) in front of positive numbers. |

### Limitations

* **Buffer Management:** `ft_printf` does not implement internal output buffering.
* **Full Feature Set:** Many advanced features of the real `printf` (e.g., floating-point, long long types, locales) are not included.
* **Dependencies:** Performance is limited by the underlying custom `libft` functions used for basic I/O and string manipulation.

## 2. Installation

```shell
make all #Compiles the Mandatory source files and creates the static library libftprintf.a
```
```shell
make bonus #Compiles the Bonus source files, including logic for all advanced flags.
```
```shell
make clean #Removes all object files (.o) from the project and libft.
```
```shell
make fclean #Runs clean and removes the final library file, libftprintf.a.
```
```shell
make re	#Performs a full re-compilation (fclean then all).
```
## 3. Resources

### 3.1 hird-party testers

- [printfTester](https://github.com/Tripouille/printfTester)
- [gavinfielder/pft](https://github.com/gavinfielder/pft)
- [Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
- [HappyTramp/ft_printf_test](https://github.com/HappyTramp/ft_printf_test)
- [t0mm4rx/ftprintfdestructor](https://github.com/t0mm4rx/ftprintfdestructor)
- [charMstr/printf_lover_v2](https://github.com/charMstr/printf_lover_v2)

### 3.2 Useful Links

- [C++ Reference - printf](http://www.cplusplus.com/reference/cstdio/printf/)
- [Article: Secrets of “printf” (PDF)](https://www.cypress.com/file/54441/download)
- [MacOS documentation - printf](https://opensource.apple.com/source/xnu/xnu-201/osfmk/kern/printf.c.auto.html)
- [IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)
- [How does one print floats for ft_printf? - Stack Overflow - 42 Network](https://stackoverflow.com/c/42network/questions/133/134#134)
- [Printing Floating-Point Numbers](http://www.ryanjuckett.com/programming/printing-floating-point-numbers/)
- [Printing Floating-Point Numbers Quickly and Accurately with Integers](https://www.cs.tufts.edu/~nr/cs257/archive/florian-loitsch/printf.pdf)
- [What precisely does the %g printf specifier mean? - Stack Overflow](https://stackoverflow.com/questions/54162152/what-precisely-does-the-g-printf-specifier-mean)

## 4. Additional section

### 4.1 Functions

### 4.2 Bonus Structure:exclamation

`ft_printf()`s bonus code base has the following file structure:

```mermaid
---
title ft_printf w/ Bonus Structure
---
classDiagram
direction LR
    class libft_h["libft.h"] {
    }

    class ft_printf_h["ft_printf_bonus.h"] {
    }

    class ft_printf_c["ft_printf_bonus.c"] {
	    int ft_printf(const char *str, ...)
    }

    class ft_parse_utils["ft_parse_utils.c"] {
	    int ft_parse_bonus(str, f)
	    void ft_parse_width(str, ap, f)
	    void ft_parse_precision(str, ap, f)
    }

    class ft_parse["ft_parse_bonus.c"] {
	    char *ft_parse(str, ap, f)
	    int ft_print_format(t_format f, va_list ap)
	    void ft_handle_flags(f)
    }

    class ft_print_chars["ft_print_chars_bonus.c"] {
	    int ft_print_c_pct(f, ap)
	    int ft_print_s(f, ap)
    }

    class ft_handle_nbrs["ft_handle_nbrs_d_i_u_data.c"] {
	    void ft_handle_d_i_u_data(f, ap, info)
	    long long ft_get_num_arg(f, ap, neg)
    }

    class ft_print_nbrs["ft_print_nbrs_d_i_u_bonus.c"] {
	    int ft_print_d_i_u(f, ap)
	    void ft_print_nbr(f, nbr, len, neg)
    }

    class ft_print_hex_o["ft_print_hex_o_bonus.c"] {
	    int ft_print_o(f, ap)
	    void ft_recursive_octal(f, n)
    }

    class ft_print_hex_x["ft_print_hex_x_bonus.c"] {
	    int ft_print_x(f, ap)
	    void ft_print_x_output(f, n, len)
    }

    class ft_print_hex_p["ft_print_hex_p_bonus.c"] {
	    int ft_print_p(f, ap)
	    void ft_print_p_non_null(f, n, len)
    }

    class ft_recursive_hex["ft_print_hex_utils.c"] {
	    void ft_recursive_hex_print(f, n, iteration)
    }

    class ft_convert_nbrs["ft_convert_nbrs_utils.c"] {
	    char *ft_uitoa_base(n, base)
    }

	note for ft_printf_h "Main header file."
	note for ft_printf_c "Central entry point and primary dispatcher."
	note for ft_parse "Central function for flag and width/precision analysis."
	note for ft_parse_utils "Parsing utilities for flags, width, and precision ('*')."
	note for ft_handle_nbrs "Extracts and handles numeric arguments (d, i, u, o)."
	note for ft_print_nbrs "Formatting and printing logic for signed and unsigned integers."
	note for ft_print_hex_x "Handles hex (x, X) conversion and printing."
	note for ft_print_hex_o "Handles octal (o) conversion and printing."
	note for ft_print_hex_p "Handles pointer (p) printing (including '(nil)')."
	note for ft_print_chars "Handles 'c', '%', and 's' conversions."
	note for ft_recursive_hex "Recursive function for hex output (shared by x, X, p)."
	note for ft_convert_nbrs "Numeric conversion utility (e.g., uitoa_base for octal)."

    libft_h --> ft_printf_h
    ft_printf_h <|-- ft_printf_c
    ft_printf_c --> ft_parse
    ft_printf_c --> ft_print_chars
    ft_printf_c --> ft_print_nbrs
    ft_printf_c --> ft_print_hex_x
    ft_parse --> ft_parse_utils
    ft_handle_nbrs --> ft_convert_nbrs
    ft_print_nbrs --> ft_handle_nbrs
    ft_print_hex_x --> ft_recursive_hex
    ft_print_hex_o --> ft_recursive_hex
    ft_print_hex_p --> ft_recursive_hex
```

## Summary

December 20th, 2025