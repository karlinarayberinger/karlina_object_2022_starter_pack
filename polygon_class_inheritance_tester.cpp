
/**
 * file: polygon_class_inheritance_tester.cpp
 * type: C++ (source file)
 * date: 22_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "polygon.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "quadrilateral.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);

/**
 * Unit Test # 0: Implement a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the QUADRILATERAL class).
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: Implement a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the QUADRILATERAL class).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << "\npointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
    pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/**
 * Unit Test # 1: Test the default QUADRILATERAL constructor and QUADRILATERAL print method.
 */
void unit_test_1(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: Test the default QUADRILATERAL constructor and QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral;";
    output << "\nquadrilateral.print(output);";
    output << "\nquadrilateral.print(); // Test the default argument (which is std::cout).";
    output << "\nquadrilateral.print(output);";
    output << "\noutput << quadrilateral; // overloaded ostream operator as defined in quadrilateral.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral;
    quadrilateral.print(output);
    quadrilateral.print(); // Test the default argument (which is std::cout).
    quadrilateral.print(output);
    output << quadrilateral; // overloaded ostream operator as defined in quadrilateral.cpp
}

/** 
 * Unit Test # 2: Implement a pointer-to-POLYGON type variable to call the overloaded ostream operator method of the POLYGON class.
 */
void unit_test_2(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 2: Implement a pointer-to-POLYGON type variable to call the overloaded ostream operator method of the POLYGON class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << "\noutput << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.";
    output << "\n--------------------------------------------------------------------------------------------------";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.";
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If polygon_class_inheritance_tester_output.txt does not already exist in the same directory as polygon_class_inheritance_tester.cpp, 
     * create a new file named polygon_class_inheritance_tester_output.txt.
     * 
     * Open the plain-text file named polygon_class_inheritance_tester_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("polygon_class_inheritance_tester_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of POLYGON class variables.
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