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
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);

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

/**
 * Unit Test # 1: HASH_TABLE constructor, insert method, print method, and destructor.
 */
void unit_test_1(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 1: HASH_TABLE constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nNODE node;";
    output << "\nnode.key = \"unit_test_1\";";
    output << "\nnode.next = NULL;";
    output << "\nhash_table.insert_node(&node);";
    output << "\nhash_table.print(output);";
    HASH_TABLE hash_table;
    NODE node;
    node.key = "unit_test_1";
    node.next = NULL;
    hash_table.insert_node(&node);
    hash_table.print(output);
}

/**
 * Unit Test # 2: HASH_TABLE constructor, insert method, print method, and destructor.
 */
void unit_test_2(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 2: HASH_TABLE constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nNODE node_A = { key : \"node_A\", next : NULL };";
    output << "\nNODE node_B = { key : \"node_B\", next : NULL };";
    output << "\nNODE node_C = { key : \"node_C\", next : NULL };";
    output << "\nhash_table.insert_node(&node_A);";
    output << "\nhash_table.insert_node(&node_B);";
    output << "\nhash_table.insert_node(&node_C);";
    output << "\noutput << hash_table; // functionally identical to hash_table.print(output)";
    HASH_TABLE hash_table;
    NODE node_A = { key : "node_A", next : NULL };
    NODE node_B = { key : "node_B", next : NULL };
    NODE node_C = { key : "node_C", next : NULL };
    hash_table.insert_node(&node_A);
    hash_table.insert_node(&node_B);
    hash_table.insert_node(&node_C);
    output << hash_table; // functionally identical to hash_table.print(output)
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
    unit_test_1(std::cout);
    unit_test_1(file);
    unit_test_2(std::cout);
    unit_test_2(file);

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