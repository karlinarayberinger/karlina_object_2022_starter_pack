/**
 * file: hash_table_driver.cpp
 * type: C++ (source file)
 * date: 08_DECEMBER_2022
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "hash_table.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the HASH_TABLE class.

/* function prototypes */
void unit_test_0(std::ostream & output);

/**
 * Unit Test # 0: HASH_TABLE constructor, print method, and destructor.
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 0: HASH_TABLE constructor, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nhash_table.print(output);";
    HASH_TABLE hash_table;
    hash_table.print(output);
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If hash_table_driver_output.txt does not already exist in the same directory as hash_table_driver.cpp, 
     * create a new file named hash_table_driver_output.txt.
     * 
     * Open the plain-text file named hash_table_driver_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("hash_table_driver_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of LINKED_LIST class variables.
    unit_test_0(std::cout);
    unit_test_0(file);

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