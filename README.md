This was developed as part of a homework received during the `Advanced Data Structures` course that I'm currently taking. 
The goal was to implement the `aho-corasick` string matching algorithm.

# About the implementation

In addition to the *failure links* described in our class, this code also implements *dictionary links*.

This is because, to my understanding, on slide 46 of the `course10.pdf` file provided during class,
the word `at` would not be found in the word `potato` as you are on a completely different path of the trie tree.

This implementation is partially based on the following explanations:

- https://www.youtube.com/watch?v=O7_w001f58c
- https://www.youtube.com/watch?v=OFKxWFew_L0

from [Niema Moshiri](https://niema.net/), Associate Professor at the University of California, Sn Diego (UCSD).

# Guide

## Compilation

### CLion

The simplest way to get the program working is through CLion, like it was developed. 
Simply clone the repo and open it in the IDE.

Important notes:

- Running in CLion messes with relative paths, as the executable is opened inside the `cmake-debug-build` directory. 
If it can't find your file, use absolute paths.
- The default output view can mess up text formatting, I recommend enabling `Emulate terminal output in console`.

### CMake

Compiling with CMake is quite platform-specific, so I won't go into it, but a `CMakeLists.txt` file is provided.

### Manual (GCC/Clang)

To manually compile the file, you just need to mention all the input files and the C++ standard.

```bash
# gcc
$ g++.exe main.cpp ac-node.cpp ac-tree.cpp -std=c++23 -o output_file

# clang
$ clang++.exe main.cpp ac-node.cpp ac-tree.cpp -std=c++23 -o output_file
```

## Usage

The program functions according to the requirements given by my professor:

> The interaction of the user with the program should be as follows:
>
> Enter the source file for the text: file-name
>
> Enter the number of patterns: z
>
> Enter pattern 1: P1
> 
> ...
> 
> Enter pattern z: Pz
>
> Afterwards, the program displays the occurrences of every pattern in text the T which was
read from the text file file-name:
> 
> Pattern 1 occurs at positions p1,1 ... p1,n1
> 
> ...
> 
> Pattern z occurs at positions pz,1 ... pz,nz

Additionally, a debug flag was added (`-d` or `--debug`). This enables displaying the trie tree.