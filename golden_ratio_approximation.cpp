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


/**
 * Compute the approximate value of the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * For each Golden Ratio approximation, i,
 * print an algebraic expression which represents the ith Golden Ratio approximation 
 * (and the ith Golden Ratio approximation is produced by dividing fibonacci(i) by fibonacci(i - 1)).
 * 
 * golden_ratio := (1 + square_root(2)) / 5. 
 * golden_ratio_approximation(N) := fibonacci(N) / fibonacci(N - 1). 
 */
long double golden_ratio_approximation(int N, std::ostream & output)
{
    unsigned long long int A = 0, B = 0; 
    long double C = 0.0;
    A = fibonacci_sequence_term(N);
    B = fibonacci_sequence_term(N - 1);
    C = (long double) A / B;
    output << "\n\ngolden_ratio_approximation(" << N << ") = fibonacci(" << N << ") / fibonacci(" << N - 1 << ").";
    output << "\ngolden_ratio_approximation(" << N << ") = " << A << " / " << B << ".";
    output << "\ngolden_ratio_approximation(" << N << ") = " << C << ".";
    return C;
}


/* program entry point */
int main()
{
    // Declare two int type variables and set their initial values to 0.
    int N = 0, i = 0;

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If golden_ratio_approximation_output.txt does not already exist in the same directory as golden_ratio_approximation.cpp, 
     * create a new file named golden_ratio_approximation_output.txt .
     * 
     * Open the plain-text file named golden_ratio_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("golden_ratio_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal.
    std::cout << "\nThe value which was entered for N is " << N << ".";

    // Print "The value which was entered for N is {N}." to the file output stream.
    file << "\n\nThe value which was entered for N is " << N << ".";

    // If N is smaller than 0 or if N is larger than MAXIMUM_N, set N to 0.
    N = ((N < 0) || (N > MAXIMUM_N)) ? 0 : N; // A tertiary operation (using the tertiary operator (?)) is an alternative to using if-else statements.

    // Print "N := {N}." to the command line terminal.
    std::cout << "\n\nN := " << N << ".";

    // Print "N := {N}." to the file output stream.
    file << "\n\nN := " << N << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Computing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:" to the command line terminal.
    std::cout << "\n\nComputing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:";

    // Print "Computing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:" to the file output stream.
    file << "\n\nComputing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}