/**
 * file: probability.cpp
 * type: C++ (source file)
 * date: 18_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#include <stdio.h> // library which defines the NULL macro
#include <stdlib.h> // library which defines the srand() and rand() functions
#include <time.h> // library which defines the time() function
#define MAXIMUM_S 1000 // upper limit constant for values of S
#define MAXIMUM_T 1000 // upper limit constant for values of T

/* function prototypes */
void bubble_sort(int * A, int S);
void print_histogram(int * A, int S, int T, std::ostream & output);
