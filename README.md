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
    graph LR;
    class libft_h["libft.h"]
    
    class ft_printf_h["ft_printf_bonus.h"]
    class ft_parse_utils["ft_parse_utils.c"]
    class ft_parse["ft_parse_bonus.c"]
    class ft_print_c_pct["ft_print_chars_bonus.c"]
    class ft_print_s["ft_print_chars_bonus.c"]
    class ft_handle_nbrs["ft_handle_nbrs_d_i_u_data.c"]
    class ft_print_d_i_u["ft_print_nbrs_d_i_u_bonus.c"]
    class ft_print_o["ft_print_hex_o_bonus.c"]
    class ft_print_x["ft_print_hex_x_bonus.c"]
    class ft_print_p["ft_print_hex_p_bonus.c"]
    class ft_recursive_hex["ft_print_hex_utils.c"]
    class ft_convert_nbrs["ft_convert_nbrs_utils.c"]

    %% Relationships - Defined as a chain to force vertical layout
    libft_h --> ft_printf_h
    ft_printf_h --> ft_parse_utils
    ft_printf_h --> ft_parse
    ft_printf_h --> ft_print_c_pct
    ft_printf_h --> ft_print_s
    ft_printf_h --> ft_handle_nbrs
    ft_printf_h --> ft_print_d_i_u
    ft_printf_h --> ft_print_o
    ft_printf_h --> ft_print_x
    ft_printf_h --> ft_print_p
    ft_printf_h --> ft_recursive_hex
    ft_printf_h --> ft_convert_nbrs
    
    %% Methods
    class ft_parse["ft_parse_bonus.c"] {
        ft_parse(str, ap)
        ft_handle_flags(f)
    }
    class ft_parse_utils["ft_parse_utils.c"] {
        ft_parse_bonus(str, f)
        ft_parse_width(str, ap, f)
        ft_parse_precision(str, ap, f)
    }
    class ft_handle_nbrs["ft_handle_nbrs_d_i_u_data.c"] {
        ft_handle_d_i_u_data(f, ap, info)
        ft_get_num_arg(f, ap, neg)
        ft_read_and_convert_num(f, ap, neg)
    }
    class ft_print_d_i_u["ft_print_nbrs_d_i_u_bonus.c"] {
        ft_print_d_i_u(f, ap)
        ft_print_nbr(f, nbr, len, neg)
        ft_print_nbr_parts(f, nbr, data)
    }
    class ft_print_x["ft_print_hex_x_bonus.c"] {
        ft_print_x(f, ap)
        ft_print_x_output(f, n, len)
        ft_sharp(f)
    }
    class ft_print_o["ft_print_hex_o_bonus.c"] {
        ft_print_o(f, ap)
        ft_recursive_octal(f, n)
        ft_print_o_output(f, n, len, total_len)
    }
    class ft_print_p["ft_print_hex_p_bonus.c"] {
        ft_print_p(f, ap)
        ft_print_p_non_null(f, n, len)
        ft_print_p_null(f)
    }
    class ft_recursive_hex["ft_print_hex_utils.c"] {
        ft_recursive_hex_print(f, n, iteration)
    }
    class ft_print_c_pct["ft_print_chars_bonus.c"] {
        ft_print_c_pct(f, ap)
        ft_print_pct()
    }
    class ft_print_s["ft_print_chars_bonus.c"] {
        ft_print_s(f, ap)
        ft_get_str_len(f, string)
    }
    class ft_convert_nbrs["ft_convert_nbrs_utils.c"] {
        ft_uitoa_base(n, base)
    }

    %% Notes (Using simpler 'note for' syntax for maximum compatibility)
    note for ft_parse "Central parsing function. Calls ft_parse_width/precision. Finalizes flags (e.g., width<0 -> minus=1)."
    note for ft_parse_utils "Parses and sets all flags (+, ' ', #, -, 0) and width/precision values, including the '*' character."
    note for ft_handle_nbrs "Responsible for extracting and converting numerical arguments (d, i, u, o) to a string. Sets the NEG sign."
    note for ft_print_d_i_u "Formatting and printing logic for integers (d, i, u), respecting flags +, ' ', -, 0, and precision."
    note for ft_print_x "Hexadecimal number handling (x, X). Implements the # flag (0x/0X prefix)."
    note for ft_print_o "Octal number handling (o). Implements the # flag (0 prefix)."
    note for ft_print_p "Pointer handling (p). Includes special logic for NULL pointers (outputs '(nil)')."
    note for ft_recursive_hex "Recursive printing of hexadecimal numbers. Used for x, X, and p."
    note for ft_print_c_pct "Prints characters (c) and the percent sign (%). Handles width flag."
    note for ft_print_s "Prints strings (s). Handles precision (truncation) and width. Includes '(null)' logic."
    note for ft_convert_nbrs "Conversion utilities: converts unsigned int to a string in the given number base. Used for 'o'."
```