/**
 * file: golden_ratio_approximation.cpp
 * type: C++ (source file)
 * date: 17_NOVEMBER_2022
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