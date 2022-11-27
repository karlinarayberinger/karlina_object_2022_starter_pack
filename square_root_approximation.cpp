/**
 * file: square_root_approximation.cpp
 * type: C++ (source file)
 * date: 27_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#define MAXIMUM_N 100 // constant which represents maximum N value 
#define E 0.000001 // constant which represents the degree of accuracy of the square root approximation

/* function prototype */
long double compute_square_root_of_nonnegative_integer(int N, std::ostream & output);

/**
 * Compute the approximate square root of a nonnegative integer, N, using the Babylonian Method.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * This function returns a value whose data type is long double (which is a floating-point number).
 */
long double compute_square_root_of_nonnegative_integer(int N, std::ostream & output)
{
    return 0;
}

/* program entry point */
int main()
{
    // Declare three int type variables and set each of their initial values to 0.
    int N = 0, A = 0, B = 0;

    // Declare a file output stream object.
    std::ofstream file;

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