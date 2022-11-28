/**
 * file: square_root_approximation.cpp
 * type: C++ (source file)
 * date: 28_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#define MAXIMUM_N 100 // constant which represents maximum N value 
#define E 0.000001 // constant which represents the degree of accuracy of the square root approximation 

/* function prototype */
long double compute_square_root_of_nonnegative_integer(float N, std::ostream & output);

/**
 * Compute the approximate square root of a nonnegative integer, N, using the Babylonian Method.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * This function returns a value whose data type is long double (which is a floating-point number).
 */
long double compute_square_root_of_nonnegative_integer(float N, std::ostream & output)
{
    int i = 0;
    long double X = 0.0, Y = 1.0;
    X = ((N < 0) || (N > MAXIMUM_N)) ? 0 : N;
    X = N;
    output << "\n\nN = " << N << ". // number to take the square root of";
    output << "\nX = " << X << ". // approximate square root of N";
    output << "\nY = " << Y << ". // number to add to X to divide by 2 per square root approximation";
    while (X - Y > E) 
    {
        X = (X + Y) / 2;
        Y = N / X;
        output << "\n\nX = ((X + Y) / 2) = " << X << ". // approximate square root of N # " << i;
        output << "\nY = (N / X) = " << Y << ". // approximate square root of N # " << i;
        i += 1;
    }
    return X;
}

/* program entry point */
int main()
{
    // Declare a float type variable and set its initial value to zero.
    float N = 0;

    // Declare two long double type variables and set their initial values to zero.
    long double A = 0.0, B = 0.0;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If square_root_approximation_output.txt does not already exist in the same directory as square_root_approximation.cpp, 
     * create a new file named square_root_approximation_output.txt.
     * 
     * Open the plain-text file named square_root_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("square_root_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "Enter a nonnegative number which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a nonnegative number which is no larger than " << MAXIMUM_N << ": ";

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

    // Print "Computing the approximate square root of N:" to the command line terminal.
    std::cout << "\n\nComputing the approximate square root of N:";

    // Print "Computing the approximate square root of N:" to the file output stream.
    file << "\n\nComputing the approximate square root of N:";

    // Compute the approximate square root of N using the Babylonian method, print the computational steps to the command line terminal, and store the function result in A.
    A = compute_square_root_of_nonnegative_integer(N, std::cout);

    // Compute the approximate square root of N using the Babylonian method, print the computational steps to the file output stream.
    compute_square_root_of_nonnegative_integer(N, file);

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "A = approximate_square_root({N}) = {A}." to the command line terminal.
    std::cout << "\n\nA = approximate_square_root(" << N << ") = " << A << ".";

    // Print "A = approximate_square_root({N}) = {A}." to the file output stream.
    file << "\n\nA = approximate_square_root(" << N << ") = " << A << ".";

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