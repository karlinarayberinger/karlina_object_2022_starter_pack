/**
 * file: cube_root_approximation.cpp
 * type: C++ (source file)
 * date: 28_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#include <cmath> // library which contains the absolute value function
#define MAXIMUM_N 100 // constant which represents maximum N value 
#define E 0.00000001 // constant which represents the degree of accuracy of the cube root approximation 

/* function prototype */
long double difference(long double n, long double mid);
long double compute_cube_root_of_nonnegative_integer(float N, std::ostream & output);

// Returns the absolute value of n-mid*mid*mid
double diff(double n,double mid)
{
    if (n > (mid*mid*mid))
        return (n-(mid*mid*mid));
    else
        return ((mid*mid*mid) - n);
}

// Returns cube root of a no n
double cubicRoot(double n)
{
    // Set start and end for binary search
    double start = 0, end = n;

    // Set precision
    double e = 0.0000001;

    while (true)
    {
        double mid = (start + end)/2;
        double error = diff(n, mid);

        // If error is less than e then mid is
        // our answer so return mid
        if (error <= e)
            return mid;

        // If mid*mid*mid is greater than n set
        // end = mid
        if ((mid*mid*mid) > n)
            end = mid;

        // If mid*mid*mid is less than n set
        // start = mid
        else
            start = mid;
    }
}

/**
 * Compute the approximate cube root of a nonnegative number, N.
 * 
 * Assume that N is a float type value and that output is an output stream object.
 * 
 * This function returns a value whose data type is long double (which is a floating-point number).
 */
long double compute_cube_root_of_nonnegative_integer(float N, std::ostream & output)
{
    return cubicRoot(N);
}

/* program entry point */
int main()
{
    // Declare a float type variable and set its initial value to zero.
    float N = 0;

    // Declare one double type variable and set its initial value to zero.
    long double S = 0.0;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If cube_root_approximation_output.txt does not already exist in the same directory as cube_root_approximation.cpp, 
     * create a new file named cube_root_approximation_output.txt.
     * 
     * Open the plain-text file named cube_root_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("cube_root_approximation_output.txt");

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

    // Print "Computing the approximate cube root of N:" to the command line terminal.
    std::cout << "\n\nComputing the approximate cube root of N:";

    // Print "Computing the approximate square root of N:" to the file output stream.
    file << "\n\nComputing the approximate cube root of N:";

    // Compute the approximate cube root of N, print the computational steps to the command line terminal, and store the function result in S.
    S = compute_cube_root_of_nonnegative_integer(N, std::cout);

    // Compute the approximate cube root of N and print the computational steps to the file output stream.
    compute_cube_root_of_nonnegative_integer(N, file);

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "S = approximate_cube_root({N}) = {S}." to the command line terminal.
    std::cout << "\n\nS = approximate_cube_root(" << N << ") = " << S << ".";

    // Print "S = approximate_cube_root({N}) = {S}." to the file output stream.
    file << "\n\nS = approximate_cube_root(" << N << ") = " << S << ".";

    // Print "(S * S * S) = " << {(S * S * S)} << ". // the approximate value of N" to the command line terminal.
    std::cout << "\n\n(S * S * S) = " << (S * S * S) << ". // the approximate value of N";

    // Print "(S * S * S) = " << {(S * S * S)} << ". // the approximate value of N" to the file output stream.
    file << "\n\n(S * S * S) = " << (S * S * S) << ". // the approximate value of N";

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