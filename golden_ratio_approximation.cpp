/**
 * file: golden_ratio_approximation.cpp
 * type: C++ (source file)
 * date: 18_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 93 // constant which represents maximum N value

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#define MAXIMUM_N 93 // constant which represents maximum N value

/* function prototypes */
unsigned long long int compute_Nth_fibonacci_sequence_term_using_iteration(int N);
long double golden_ratio_approximation(int N, std::ostream & output);


/**
 * Compute the Nth term of the Fibonacci Sequence using an iterative algorithm.
 * 
 * Assume that N is an integer value.
 * 
 * For each while loop iteration, i, 
 * print an algebraic expression which represents the ith term of the Fibonacci Sequence.
 * 
 * fibonacci(0) := 1. // The first term of the Fibonacci Sequence is 1.
 * fibonacci(1) := 1. // The second term of the Fibonacci Sequence is 1.
 * fibonacci(i) := fibonacci(i - 2) + fibonacci(i - 1). // if i is a natural number larger than 1
 */
int compute_Nth_fibonacci_sequence_term_using_iteration(int N)
{
    int i = 0, A = 1, B = 1, C = 0;
    if ((N < 2) || (N > MAXIMUM_N)) return 1;
    for (i = 2; i < N; i += 1) 
    {
        C = A;
        A = B;
        B += C;
    }
    return B;
}