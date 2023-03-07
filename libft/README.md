# libft
My solutions for the libft project of 42

![image](https://user-images.githubusercontent.com/85911265/173158832-c42d180f-8ed3-46aa-ad67-8d5f12e98811.png)

This is a project where I had to reimplement many of glibc most used functions, along with some usefull function that are not original to C. All the functions are to be
compiled into a Lib that can be included in future projects to give you access to all the functions.

This took me around a week to complete (not including the time to the requiered p2p avaliations)



## 🛠️ Usage

### Requirements

The library is written in C language and has to be compiled with the **`Clang` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/libft && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "libft.h"
```

and, when compiling your code, add the required flags:

```shell
-lft -L path/to/libft.a -I path/to/libft.h
```
