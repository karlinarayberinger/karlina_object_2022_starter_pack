/**
 * file: triangle_class_tester.cpp
 * type: C++ (source file)
 * date: 20_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "triangle.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRIANGLE class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);

// Unit Test # 0: TRIANGLE class default constructor, TRIANGLE class print method, and TRIANGLE class destructor.
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: TRIANGLE class default constructor, TRIANGLE class print method, and TRIANGLE class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE point;";
    output << "\ntriangle.print(output);";
    TRIANGLE triangle;
    triangle.print(output);
}

// Unit Test # 1: TRIANGLE class default constructor, TRIANGLE class overloaded ostream operator method, TRIANGLE getter methods, and TRIANGLE class destructor.
void unit_test_1(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: TRIANGLE class default constructor, TRIANGLE class overloaded ostream operator method, TRIANGLE getter methods, and TRIANGLE class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE triangle;";
    output << "\nPOINT copy_of_point_A = triangle.get_A();";
    output << "\nPOINT copy_of_point_B = triangle.get_B();";
    output << "\nPOINT copy_of_point_C = triangle.get_C();";
    output << "\noutput << triangle;";
    TRIANGLE triangle;
    POINT copy_of_point_A = triangle.get_A();
    POINT copy_of_point_B = triangle.get_B();
    POINT copy_of_point_C = triangle.get_C();
    output << triangle;
    output << "\n\ncopy_of_point_A.print(output);";
    copy_of_point_A.print(output);
    output << "\n\ncopy_of_point_B.print(output);";
    copy_of_point_B.print(output);
    output << "\n\ncopy_of_point_C.print(output);";
    copy_of_point_C.print(output);
    output << "\ntriangle.get_side_length_AB() = " << triangle.get_side_length_AB() << ".";
    output << "\ntriangle.get_side_length_BC() = " << triangle.get_side_length_BC() << ".";
    output << "\ntriangle.get_side_length_CA() = " << triangle.get_side_length_CA() << ".";
    output << "\ntriangle.get_interior_angle_ABC() = " << triangle.get_interior_angle_ABC() << ".";
    output << "\ntriangle.get_interior_angle_BCA() := " << triangle.get_interior_angle_BCA() << ".";
    output << "\ntriangle.get_interior_angle_CAB() = " << triangle.get_interior_angle_CAB() << ".";
    output << "\ntriangle.get_perimeter() = " << triangle.get_perimeter() << ".";
    output << "\ntriangle.get_area() = " << triangle.get_area() << ".";
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
     * If triangle_class_tester_output.txt does not already exist in the same directory as triangle_class_tester.cpp, 
     * create a new file named triangle_class_tester_output.txt.
     * 
     * Open the plain-text file named triangle_class_tester_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("triangle_class_tester_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of TRIANGLE class variables.
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