/**
 * file: linked_list_driver.cpp
 * type: C++ (source file)
 * date: 05_DECEMBER_2022
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "linked_list.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the LINKED_LIST class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);

/**
 * Unit Test # 0: LINKED_LIST constructor, print method, and destructor.
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 0: LINKED_LIST constructor, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    linked_list.print(output);
}

/**
 * Unit Test # 1: LINKED_LIST constructor, insert method, print method, and destructor.
 */
void unit_test_1(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 1: LINKED_LIST constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nNODE node;";
    output << "\nnode.key = \"unit_test_1\";";
    output << "\nnode.next = NULL;";
    output << "\nlinked_list.insert_node_at_end_of_list(&node);";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    NODE node;
    node.key = "unit_test_1";
    node.next = NULL;
    linked_list.insert_node_at_end_of_list(&node);
    linked_list.print(output);
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If linked_list_driver_output.txt does not already exist in the same directory as linked_list_driver.cpp, 
     * create a new file named linked_list_driver_output.txt.
     * 
     * Open the plain-text file named linked_list_driver_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("linked_list_driver_output.txt");

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