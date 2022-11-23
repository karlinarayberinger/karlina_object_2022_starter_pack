
/**
 * file: polygon_class_inheritance_tester.cpp
 * type: C++ (source file)
 * date: 22_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "polygon.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "quadrilateral.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.
#include "trapezoid.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRAPEZOID class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);
void unit_test_5(std::ostream & output);
void unit_test_6(std::ostream & output);
void unit_test_7(std::ostream & output);

/**
 * Unit Test # 0: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the QUADRILATERAL class).
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the QUADRILATERAL class).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
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
 * Unit Test # 1: Test the default QUADRILATERAL constructor and the QUADRILATERAL print method.
 */
void unit_test_1(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: Test the default QUADRILATERAL constructor and the QUADRILATERAL print method.";
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
 * Unit Test # 2: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-POLYGON to call the overloaded ostream operator method of the POLYGON class (and not of the QUADRILATERAL class).
 */
void unit_test_2(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 2: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-POLYGON to call the overloaded ostream operator method of the POLYGON class (and not of the QUADRILATERAL class).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << "\npointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\noutput << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
    pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    output << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/** 
 * Unit Test # 3: Unit Test # 3: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-QUADRILATERAL to call the overloaded ostream operator method of the QUADRILATERAL class and the public getter methods of the QUADRILATERAL class.
 */
void unit_test_3(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 3: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-QUADRILATERAL to call the overloaded ostream operator method of the QUADRILATERAL class and the public getter methods of the QUADRILATERAL class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRATERAL type variable can store the memory address of an object whose data type is QUADRILATERAL or else a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.";
    output << "\npointer_to_quadrilateral = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\noutput << * pointer_to_quadrilateral; // Use the overloaded ostream operator as defined in quadrilateral.cpp to print the data which is stored at the memory address which pointer_to_quadrilateral stores.";
    output << "\ndelete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRATERAL type variable can store the memory address of an object whose data type is QUADRILATERAL or else a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.
    pointer_to_quadrilateral = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    output << * pointer_to_quadrilateral; // Use the overloaded ostream operator as defined in quadrilateral.cpp to print the data which is stored at the memory address which pointer_to_quadrilateral stores.
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\npointer_to_quadrilateral -> get_area() = " << pointer_to_quadrilateral -> get_area(); // Indirectly call the get_area() method of the QUADRILATERAL class.
    output << "\npointer_to_quadrilateral -> get_perimeter() = " << pointer_to_quadrilateral -> get_perimeter(); // Indirectly call the get_perimeter() method of the QUADRILATERAL class.
    delete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/**
 * Unit Test # 4: Test the normal QUADRILATERAL constructor and QUADRILATERAL copy constructor using valid function inputs and the QUADRILATERAL print method.
 */
void unit_test_4(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 4: Test the normal QUADRILATERAL constructor and QUADRILATERAL copy constructor using valid function inputs and the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral_0 = QUADRILATERAL(\"green\", POINT(-2,-2), POINT(-2,2), POINT(2,2), POINT(2,-2));";
    output << "\nquadrilateral_0.print(output);";
    output << "\nQUADRILATERAL quadrilateral_1 = QUADRILATERAL(\"blue\", POINT(0,0), POINT(3,2), POINT(5,1), POINT(-1,-2));";
    output << "\nquadrilateral_1.print(output);";
    output << "\nQUADRILATERAL quadrilateral_2 = QUADRILATERAL(quadrilateral_0);";
    output << "\nquadrilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral_0 = QUADRILATERAL("green", POINT(-2,-2), POINT(-2,2), POINT(2,2), POINT(2,-2));
    quadrilateral_0.print(output);
    QUADRILATERAL quadrilateral_1 = QUADRILATERAL("blue", POINT(0,0), POINT(3,2), POINT(5,1), POINT(-1,-2));
    quadrilateral_1.print(output);
    QUADRILATERAL quadrilateral_2 = QUADRILATERAL(quadrilateral_0);
    quadrilateral_2.print(output);
}

/**
 * Unit Test # 5: Test the normal QUADRILATERAL constructor using invalid function inputs and the QUADRILATERAL print method.
 */
void unit_test_5(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 5: Test the normal QUADRILATERAL constructor using invalid function inputs and the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral_0 = QUADRILATERAL(\"red\", POINT(-2,-2), POINT(0,0), POINT(1,1), POINT(2,2)); // A line intersects all four points.";
    output << "\nquadrilateral_0.print(output);";
    output << "\nQUADRILATERAL quadrilateral_1 = QUADRILATERAL(\"purple\", POINT(0,0), POINT(3,2), POINT(0,0), POINT(-1,-2)); // Not all point coordinate pairs are unique.";
    output << "\nquadrilateral_1.print(output);";
    output << "\nQUADRILATERAL quadrilateral_2 = QUADRILATERAL(\"yellow\", POINT(0,0), POINT(0,2), POINT(4,0), POINT(4,2)); // The points form a bow-tie shaped polygon.";
    output << "\nquadrilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral_0 = QUADRILATERAL("red", POINT(-2,-2), POINT(0,0), POINT(1,1), POINT(2,2)); // A line intersects all four points.
    quadrilateral_0.print(output);
    QUADRILATERAL quadrilateral_1 = QUADRILATERAL("purple", POINT(0,0), POINT(3,2), POINT(0,0), POINT(-1,-2)); // Not all point coordinate pairs are unique.
    quadrilateral_1.print(output);
    QUADRILATERAL quadrilateral_2 = QUADRILATERAL("yellow", POINT(0,0), POINT(0,2), POINT(4,0), POINT(4,2)); // The points form a bow-tie shaped polygon.
    quadrilateral_2.print(output);
}

/**
 * Unit Test # 6: Test the default TRAPEZOID constructor and the TRAPEZOID print method.
 */
void unit_test_6(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 6: Test the default TRAPEZOID constructor and the TRAPEZOID print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRAPEZOID trapezoid;";
    output << "\ntrapezoid.print(output);";
    output << "\ntrapezoid.print(); // Test the default argument (which is std::cout).";
    output << "\ntrapezoid.print(output);";
    output << "\noutput << trapezoid; // overloaded ostream operator as defined in trapezoid.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRAPEZOID trapezoid;
    trapezoid.print(output);
    trapezoid.print(); // Test the default argument (which is std::cout).
    trapezoid.print(output);
    output << trapezoid; // overloaded ostream operator as defined in trapezoid.cpp
}

/**
 * Unit Test # 7: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRAPEZOID instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the TRAPEZOID class).
 */
void unit_test_7(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 7: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRAPEZOID instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class (and not of the TRAPEZOID class).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as TRAPEZOID.";
    output << "\npointer_to_polygon = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as TRAPEZOID.
    pointer_to_polygon = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.";
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
    unit_test_3(std::cout);
    unit_test_3(file);
    unit_test_4(std::cout);
    unit_test_4(file);
    unit_test_5(std::cout);
    unit_test_5(file);
    unit_test_6(std::cout);
    unit_test_6(file);
    unit_test_7(std::cout);
    unit_test_7(file);

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