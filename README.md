# ft_printf | 42 Gefolgwar

*Because ft_putstr & ft_putnbr aren't enough :stuck_out_tongue_winking_eye:*

### Table of Contents

* [ft_print what?](#ft_print-what)
* [Capabilities](#capabilities)
* [Bonus](#bonus)
* [Limitations](#limitations)
* [Installation](#installation)
* [Summary](#summary)

## ft_print what?
Printf is likely one of the most popular commands people see when learning a new programming language, and for a good reason. They are easy to understand and very powerful too. This is why learning to implement our own version of printf can help us better understand what happens internally when entering ``printf("Hello World")``!

## Capabilities
Our version of the printf function will be called ``ft_printf``, and will be able to work with the following inputs:


* Specifiers

| Specifier | Description |
| :-------: | :---------: |
| ``%`` | Prints the percent character |
| ``c`` | Prints a character |
| ``s`` | Prints a string (array of characters) |
| ``d``,``i`` | Prints an integer |
| ``p`` | Prints pointer address (hex starting with ``0x``) |
| ``u`` | Prints an unsigned integer |
| ``x`` | Prints an unsigned hexadecimal integer (lowecase a-f) |
| ``X`` | Prints an unsigned hexadecimal integer (uppercase A-F) |

* Flags

| Flag | Description |
| :--: | :---------: |
| (width) | Specifies the minimum width of the printed variable (adds spaces when necessary) |
| (precision) | Selects the minimum number of elements of the variable that are printed (Eg. number of chars from a string) |
| ``-`` | Pads text to the left (adds spaces to the right) |
| ``0`` | Pads text with zeroes instead of spaces |
| ``.`` | Separates Width and Precision |
| ``*`` | Indicates that the Width or the Precision will be specified using an additional variable |

Our ft_printf function has the following prototype:
```C
int ft_printf(const char *str, ...);
```

The general idea of the function is to iterate over ``str`` and print normally until a ``%`` is read. From there, we parse the next elements until one of the Specifiers is found or until the end of the string ``\0`` is reached, whichever comes first. The general structure of the elements we want to parse is the following:

```
%[Flags][Width].[Precision][Specifier]
```

## Bonus
As of July 2021, the subject for this project has changed, and the flags ``-0.`` are now part of the bonuses. Also the ``*`` flag is gone entirely, though I have decided to keep it in my version of the code, since it took a while to implement and I wish to keep it. Other flags we need to implement in this bonus part are:

| Bonus Flag | Description |
| :--------: | :---------: |
| ``#`` | Adds "0X" or "0x" to conversions with hexadecimal specifiers (excluding p) for values other than zero |
| (space) |A blank space is added provided that no sign is specified |
| ``+`` | Adds a plus sign in front of positive numbers |

## Limitations

As this is quite a straightforward approach at printf, there are a few limitations to consider, namely:

* Our ``ft_printf`` does not have buffer management, unlike the real printf
* This implementation of printf doesn't handle overflows and unexpected inputs the same way the real printf would
* Our ``ft_printf`` isn't nearly as powerful as the real prinft since many features are not included
* ``ft_printf`` relies on our personal libft library, which makes it slower in performance when compared to the original printf

## Installation

In order for you to test this printf, it is recommended that you install the following dependencies:

```shell
111111111111111111gcc clang python-norminette make
```
111111111111111111For Linux users, it is also recommended to install ``valgrind`` (Leak checker)

111111111111111111* Testing the ``ft_printf`` function
```shell
1111111111111111111git clone 
1111111111111111111cd ft_printf
1111111111111111111make
```
1111111111111111111111111111111Feel free to replace your own libft inside the ``ft_printf`` folder


* Usage:

The makefile compiles all files from the ``src/`` or ``srcb/`` folders and saves the object files to the ``obj/`` and ``objb/`` folders. It then generates the output file ``libftprintf.a`` inside the 111111111111111111``bin/`` folder. Here are some of the commands you can try:

```
11111111111111111111111make all		Compiles the libftprintf.a file
11111111111111111111111make test		Compiles ft_printf and libft with a custom main. Checks for leaks in Mac and Linux
1111111111111111111111111111make bonus		Compiles all bonus files instead of the mandatory ones
111111111111111111111111111111make norminette		Checks Norm for both printf and libft files	
111111111111111111111111111111111make git		Stages every modified file to commit and pushes to upstream branch
```

## Summary


December 20th, 2025

### Bonus Structure:exclamation:

#### Bonus Files & Folder Structure

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
	    int ft_print_format(t_format f, va_list ap)
    }

    class ft_parse_utils["ft_parse_utils.c"] {
	    int ft_parse_bonus(str, f)
	    void ft_parse_width(str, ap, f)
	    void ft_parse_precision(str, ap, f)
    }

    class ft_parse["ft_parse_bonus.c"] {
	    char *ft_parse(str, ap, f)
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