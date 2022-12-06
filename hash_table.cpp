/**
 * file: hash_table.cpp
 * type: C++ (source file)
 * author: karbytes
 * date: 05_DECEMBER_2022
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the HASH_TABLE class.
#include "hash_table.h" 

/**
 * The getter method returns the number of LINKED_LIST type values stored in the hash table array (and the value returned is N).
 */
int HASH_TABLE::get_number_of_linked_lists_in_hash_table()
{
    return N;
}

/**
 * The getter method returns the total number of NODE type values stored in the hash table array (and the value returned is an integer which is equal to or larger than N).
 */
int HASH_TABLE::get_number_of_nodes_in_hash_table()
{
    int node_count = 0, i = 0;
    for (i = 0; i < N; i += 1) node_count += array[i].get_number_of_nodes_in_list();
    return node_count;
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * (Overloading an operator is assigning a different function to a native operator other than the function which that operator is used to represent by default).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the HASH_TABLE class header file (i.e. hash_table.h).
 * 
 * The friend function is not a member of the HASH_TABLE class, 
 * but the friend function has access to the private and protected members 
 * of the HASH_TABLE class and not just to the public members of the HASH_TABLE class.
 * 
 * The friend keyword only prefaces the function prototype of this function 
 * (and the prototype of this function is declared in the HASH_TABLE class header file (i.e. hash_table.h)). 
 * 
 * The friend keyword does not preface the definition of this function
 * (and the definition of this function is specified in the HASH_TABLE class source file (i.e. hash_table.cpp)).
 * 
 * // overloaded print function example one
 * HASH_TABLE hash_table_0;
 * std::cout << hash_table_0; // identical to hash_table_0.print();
 * 
 * // overloaded print function example two
 * std::ofstream file;
 * HASH_TABLE hash_table_1;
 * file << hash_table_1; // identical to hash_table_1.print(file);
 */
std::ostream & operator << (std::ostream & output, HASH_TABLE & hash_table)
{
    hash_table.print(output);
    return output;
}

/**
 * The destructor method of the HASH_TABLE class de-allocates memory which was used to 
 * instantiate the HASH_TABLE object which is calling this function.
 * 
 * The destructor method of the HASH_TABLE class is automatically called when 
 * the program scope in which the caller HABLE_TABLE object was instantiated terminates.
 */
HASH_TABLE::~HASH_TABLE()
{
    delete [] array;
}