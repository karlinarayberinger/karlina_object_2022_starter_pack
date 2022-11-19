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

/* program entry point */
int main()
{
    // Declare three int type variables and set each of their initial values to 0.
    int S = 0, T = 0, i = 0;

    // Declare a pointer-to-int type variable.
    int * A;

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If probability_output.txt does not already exist in the same directory as probability.cpp, 
     * create a new file named probability_output.txt.
     * 
     * Open the plain-text file named probability_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("probability_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "The following statements describe the data capacities of various primitive C++ data types:" to the command line terminal.
    std::cout << "\n\nThe following statements describe the data capacities of various primitive C++ data types:";

    // Print "The following statements describe the data capacities of various primitive C++ data types:" to the file output stream.
    file << "\n\nThe following statements describe the data capacities of various primitive C++ data types:";

    // Print the data size of an int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int) = " << sizeof(int) << " byte(s). // integer (i.e. whole number) values";

    // Print the data size of an int type variable to the file output stream.
    file << "\n\nsizeof(int) = " << sizeof(int) << " byte(s). // integer (i.e. whole number) values";

    // Print the data size of an unsigned long long int type variable to the command line terminal.
    std::cout << "\n\nsizeof(unsigned long long int) = " << sizeof(unsigned long long int) << " byte(s). // integer values from a larger set than what int encompasses";

    // Print the data size of an unsigned long long int type variable to the file output stream.
    file << "\n\nsizeof(unsigned long long int) = " << sizeof(unsigned long long int) << " byte(s). // integer values from a larger set that what int encompasses";

    // Print the data size of a bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool) = " << sizeof(bool) << " byte(s). // Boolean values (true : not(0) :: false : 0)";

    // Print the data size of a bool type variable to the file output stream.
    file << "\n\nsizeof(bool) = " << sizeof(bool) << " byte(s). // Boolean values (true : not(0) :: false : 0)";

    /*
    bool X = 77; // The last character output by the command below is 1.
    std::cout << "\n\nTest: bool X = 77. What is X? X is " << X; 
    X = false; // The last character output by the command below is 0.
    std::cout << "\n\nTest: bool X = false. What is X? X is " << X; 
    */

    // Print the data size of a char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char) = " << sizeof(char) << " byte(s). // string character value such as 'A' or '?' or '7'";

    // Print the data size of a char type variable to the file output stream.
    file << "\n\nsizeof(char) = " << sizeof(char) << " byte(s). // string character value such as 'A' or '?' or '7'";

    // Print the data size of a float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float) = " << sizeof(float) << " byte(s). // floating-point number value such as 3.14";

    // Print the data size of a float type variable to the file output stream.
    file << "\n\nsizeof(float) = " << sizeof(float) << " byte(s). // floating-point number value such as 3.14";

    // Print the data size of a double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double) = " << sizeof(double) << " byte(s). // floating-point number values from a larger set than what float encompasses";

    // Print the data size of a double type variable to the file output stream.
    file << "\n\nsizeof(double) = " << sizeof(double) << " byte(s). // floating-point number values from a larger set than what float encompasses";

    // Print the data size of a long double type variable to the command line terminal.
    std::cout << "\n\nsizeof(long double) = " << sizeof(long double) << " byte(s). // floating-point number values from a larger set than what double encompasses";

    // Print the data size of a long double type variable to the file output stream.
    file << "\n\nsizeof(long double) = " << sizeof(long double) << " byte(s). // floating-point number values from a larger set than what double encompasses";

    // Print the data size of a pointer-to-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int *) = " << sizeof(int *) << " byte(s). // A pointer-to-int type variable stores the memory address of the first memory cell of 4 contiguous memory cells which are allocated to an int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-int type variable to the file output stream.
    file << "\n\nsizeof(int *) = " << sizeof(int *) << " byte(s). // A pointer-to-int type variable stores the memory address of the first memory cell of 4 contiguous memory cells which are allocated to an int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-unsigned-long-long-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(unsigned long long int *) = " << sizeof(unsigned long long int *) << " byte(s). // A pointer-to-unsigned-long-long-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to an unsigned long long int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-unsigned-long-long-int type variable to the file output stream.
    file << "\n\nsizeof(unsigned long long int *) = " << sizeof(unsigned long long int *) << " byte(s). // A pointer-to-unsigned-long-long-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to an unsigned long long int type variable (and each memory cell has a data capacity of 1 byte)..";

    // Print the data size of a pointer-to-bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool *) = " << sizeof(bool *) << " byte(s). // A pointer-to-bool type variable stores the memory address of a bool type variable.";

    // Print the data size of a pointer-to-bool type variable to the file output stream.
    file << "\n\nsizeof(bool *) = " << sizeof(bool *) << " byte(s). // A pointer-to-bool type variable stores the memory address of a bool type variable.";

    // Print the data size of a pointer-to-char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char *) = " << sizeof(char *) << " byte(s). // A pointer-to-char type variable stores the memory address of a char type variable.";

    // Print the data size of a pointer-to-char type variable to the file output stream.
    file << "\n\nsizeof(char *) = " << sizeof(char *) << " byte(s). // A pointer-to-char type variable stores the memory address of a char type variable.";

    // Print the data size of a pointer-to-float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float *) = " << sizeof(float *) << " byte(s). // A pointer-to-float type variable stores the memory address of the first memory cell of 4 contiguous memory cells which are allocated to a float type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-float type variable to the file output stream.
    file << "\n\nsizeof(float *) = " << sizeof(float *) << " byte(s). // A pointer-to-float type variable stores the memory address of the first memory cell of 4 contiguous memory cells which are allocated to a float type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double *) = " << sizeof(double *) << " byte(s). // A pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-double type variable to the file output stream.
    file << "\n\nsizeof(double *) = " << sizeof(double *) << " byte(s). // A pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-long-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(long double *) = " << sizeof(long double *) << " byte(s). // A pointer-to-long-double type variable stores the memory address of the first memory cell of 16 contiguous memory cells which are allocated to a long double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-long-double type variable to the file output stream.
    file << "\n\nsizeof(long double *) = " << sizeof(long double *) << " byte(s). // A pointer-to-long-double type variable stores the memory address of the first memory cell of 16 contiguous memory cells which are allocated to a long double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int **) = " << sizeof(int **) << " byte(s). // A pointer-to-pointer-to-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-int type variable to the file output stream.
    file << "\n\nsizeof(int **) = " << sizeof(int **) << " byte(s). // A pointer-to-pointer-to-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool **) = " << sizeof(bool **) << " byte(s). // A pointer-to-pointer-to-bool type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-bool type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-bool type variable to the file output stream.
    file << "\n\nsizeof(bool **) = " << sizeof(bool **) << " byte(s). // A pointer-to-pointer-to-bool type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-bool type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double **) = " << sizeof(double **) << " byte(s). // A pointer-to-pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-double type variable to the file output stream.
    file << "\n\nsizeof(double **) = " << sizeof(double **) << " byte(s). // A pointer-to-pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int ***) = " << sizeof(int ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-int type variable to the file output stream.
    file << "\n\nsizeof(int ***) = " << sizeof(int ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-int type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-int type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool ***) = " << sizeof(bool ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-bool type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-bool type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-bool type variable to the file output stream.
    file << "\n\nsizeof(bool ***) = " << sizeof(bool ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-bool type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-bool type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double ***) = " << sizeof(double ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print the data size of a pointer-to-pointer-to-pointer-to-double type variable to the file output stream.
    file << "\n\nsizeof(double ***) = " << sizeof(double ***) << " byte(s). // A pointer-to-pointer-to-pointer-to-double type variable stores the memory address of the first memory cell of 8 contiguous memory cells which are allocated to a pointer-to-pointer-to-double type variable (and each memory cell has a data capacity of 1 byte).";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES." to the command line terminal.
    std::cout << "\n\nSTEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES.";

    // Print "STEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES." to the file output stream.
    file << "\n\nSTEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number, S, for representing the number of elements to include in an array which is no larger than than {MAXIMUM_S}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number, S, for representing the number of elements to include in an array which is no larger than " << MAXIMUM_S << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> S;

    // Print "The value which was entered for S is {S}." to the command line terminal.
    std::cout << "\nThe value which was entered for S is " << S << ".";

    // Print "The value which was entered for S is {S}." to the file output stream.
    file << "\n\nThe value which was entered for S is " << S << ".";

    // If S is smaller than 1 or if S is larger than MAXIMUM_S, set S to 10.
    S = ((S < 1) || (S > MAXIMUM_S)) ? 10 : S; 

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A" to the command line terminal.
    std::cout << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A";

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A" to the file output stream.
    file << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0]. inside the pointer-to-int variable named A.
    A = new int [S];

    // Print the program instruction used to generate the dynamic array represented by A to the command line terminal.
    std::cout << "\n\n// Declare a pointer-to-int type variable named A.";
    std::cout << "\nint * A;";
    std::cout << "\n\n// Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0]. inside the pointer-to-int variable named A.";
    std::cout << "\nA = new int [S];"; 

    // Print the program instruction used to generate the dynamic array represented by A to the file output stream.
    file << "\n\n// Declare a pointer-to-int type variable named A.";
    file << "\nint * A;";
    file << "\n\n// Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0]. inside the pointer-to-int variable named A.";
    file << "\nA = new int [S];"; 

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA = " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA = " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] = " << A[i] << ". \t// &A[" << i << "] = \t" << &A[i] << ". \t(memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "].";
        file << "\nA[" << i << "] = " << A[i] << ". \t// &A[" << i << "] = \t" << &A[i] << ". \t(memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "].";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_1: ASSIGN ONE OF T RANDOM INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A." to the command line terminal.
    std::cout << "\n\nSTEP_1: ASSIGN ONE OF T RANDOM INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A.";

    // Print "STEP_1: ASSIGN ONE OF T RANDOM INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A." to the file output stream.
    file << "\n\nSTEP_1: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number, T, for representing the number of unique states which each element of the array can store exactly one of which is no larger than {MAXIMUM_T}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number, T, for representing the number of unique states which each element of the array can store exactly one of which is no larger than " << MAXIMUM_T << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> T;

    // Print "The value which was entered for T is {T}." to the command line terminal.
    std::cout << "\nThe value which was entered for T is " << T << ".";

    // Print "The value which was entered for T is {T}." to the file output stream.
    file << "\n\nThe value which was entered for T is " << T << ".";

    // If T is smaller than 1 or if T is larger than MAXIMUM_T, set T to 100.
    T = ((T < 1) || (T > MAXIMUM_T)) ? 100 : T; 

    // Print "T := {T}. // number of unique states which each element of the array pointed to by A can store exactly one of at a time" to the command line terminal.
    std::cout << "\n\nT := " << T << ". // number of unique states which each element of the array pointed to by A can store exactly one of at a time";

    // Print "T := {T}. /// number of unique states which each element of the array pointed to by A can store exactly one of at a time" to the file output stream.
    file << "\n\nT := " << T << ". // number of unique states which each element of the array pointed to by A can store exactly one of at a time";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).
    srand(time(NULL));

    // Print the command to seed the pseudo random number generator to the command line.
    std::cout << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    std::cout << "\nsrand(time(NULL));";

    // Print the command to seed the pseudo random number generator to the file output stream.
    file << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    file << "\nsrand(time(NULL));";

    // For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).
    for (i = 0; i < S; i += 1) A[i] = rand() % T;

    // Print the command to populate each element of the array named A with a randomly generated integer which is no smaller than 0 and no larger than (T - 1) to the command line terminal.
    std::cout << "\n\n// For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).";
    std::cout << "\nfor (i = 0; i < S; i += 1) A[i] = rand() % T;";

    // Print the command to populate each element of the array named A with a randomly generated integer which is no smaller than 0 and no larger than (T - 1) to the file output stream.
    file << "\n\n// For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).";
    file << "\nfor (i = 0; i < S; i += 1) A[i] = rand() % T;";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA = " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA = " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] = " << A[i] << ". \t// &A[" << i << "] = \t" << &A[i] << ". \t(memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "].";
        file << "\nA[" << i << "] = " << A[i] << ". \t// &A[" << i << "] = \t" << &A[i] << ". \t(memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "].";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Deallocate the memory which was used to instantiate the dynamic array represented by A (and a dynamic array is assigned memory during program runtime rather than during program compile time).
    delete [] A;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the command line terminal.
    std::cout << "\n\n// Deallocate the memory which was used to instantiate the dynamic array represented by A (and a dynamic array (unlike a normal array) is assigned memory during program runtime rather than during program compile time).";
    std::cout << "\ndelete [] A;";

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the file output stream.
    file << "\n\n// Deallocate the memory which was used to instantiate the dynamic array represented by A (and a dynamic array (unlike a normal array) is assigned memory during program runtime rather than during program compile time).";
    file << "\ndelete [] A;";

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
