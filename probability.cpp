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

/**
 * Use the Bubble Sort algorithm to arrange the elements of 
 * an int type array, A, in ascending order
 * such that A[0] represents the smallest integer value in that array and 
 * such that A[S - 1] represents the largest integer value in that array.
 * 
 * Assume that S is a natural number no larger than MAXIMUM_S.
 * 
 * Assume that A is a pointer to an int type variable and that 
 * A stores the memory address of the first element, A[0], 
 * of an int type array comprised of exactly S elements.
 * (In other words, assume that exactly S consecutive int-sized 
 * chunks of memory are allocated to the array represented by A).
 * 
 * Although this function returns no value, 
 * the array which the pointer variable, A, points to is updated 
 * if the elements of that array are not already arranged in ascending order. 
 */
void bubble_sort(int * A, int S)
{
    int i = 0, placeholder = 0; 
    bool array_is_sorted = false, adjacent_elements_were_swapped = false;
    while (!array_is_sorted)
    {
        adjacent_elements_were_swapped = false;
        for (i = 1; i < S; i += 1)
        {
            if (A[i] < A[i - 1])
            {
                placeholder = A[i];
                A[i] = A[i - 1];
                A[i - 1] = placeholder;
                adjacent_elements_were_swapped = true;
            }
        }
        if (!adjacent_elements_were_swapped) array_is_sorted = true;
    }
}
