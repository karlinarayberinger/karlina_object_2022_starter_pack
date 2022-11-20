/**
 * file: triangle.cpp
 * type: C++ (source file)
 * author: Karlina Ray Beringer
 * date: 20_NOVEMBER_2022
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRIANGLE class.
#include "triangle.h" 


/**
 * Determine whether or not point_0, point_1, and point_2 each represent unique coordinate pairs.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * If each of the three POINT objects represent unique coordinate pairs, return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2)
{
    if ((point_0.get_X() == point_1.get_X()) && (point_0.get_Y() == point_1.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_1 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        return false;
    }
    if ((point_0.get_X() == point_2.get_X()) && (point_0.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_1.get_X() == point_2.get_X()) && (point_1.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_1 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_2.get_X() == point_0.get_X()) && (point_2.get_Y() == point_0.get_Y())) 
    {
        std::cout << "\n\npoint_2 and point_0 appear to represent the same coordinate pair.";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        return false;
    }
    return true;
}

/**
 * Determine whether or not point_0, point_1, and point_2 form a non-degenerate triangle.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * A non-degenerate triangle is a triangle whose area is some positive real number quantity.
 * 
 * A degenerate triangle is a triangle whose area is zero (due to the fact that one line intersects each of the three points).
 * 
 * If point_0, point_1, and point_2 form a non-degenerate triangle, return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2)
{
    if (!points_represent_unique_coordinate_pairs(point_0, point_1, point_2))
    {
        std::cout << "\n\npoint_0, point_1, and point_2 do not each represent unique coordinate pairs.";
        std::cout << "\nHence, points_form_degenerate_triangle(point_0, point_1, point_2) is returning false.";
        return false;
    }
    A = point_0;
    B = point_1;
    C = point_2;
    if (get_area() <= 0) 
    {
        std::cout << "\n\nWhen setting the POINT values of the caller TRIANGLE object using the given inputs, get_area() returned a non-positive number result.";
        std::cout << "\nHence, points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2) is returning false.";
        return false;
    }
    return true;
}

/**
 * The default constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE()
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    A = POINT(0, 0);
    B = POINT(0, 1);
    C = POINT(1, 0);
}

/**
 * The normal constructor method of the TRIANGLE class (which takes six int type values as function inputs) returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (A_X, A_Y),
 * whose POINT property named B represents the coordinate pair (B_X, B_Y), and
 * whose POINT property named C represents the coordinate pair (C_X, C_Y)
 * if POINT(A_X, A_Y), POINT(B_X, B_Y), and POINT(C_X, C_Y) represent a non-degenerate triangle.
 * 
 * If POINT(A_X, A_Y, POINT(B_X, B_Y), and POINT(C_X, C_Y) do not represent a non-degenerate triangle,
 * this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE(int A_X, int A_Y, int B_X, int B_Y, int C_X, int C_Y)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    POINT input_A = POINT(A_X, A_Y);
    POINT input_B = POINT(B_X, B_Y);
    POINT input_C = POINT(C_X, C_Y);
    if (points_form_nondegenerate_triangle(input_A, input_B, input_C))
    {
        A = input_A;
        B = input_B;
        C = input_C;
    }
    else
    {
        A = POINT(0, 0);
        B = POINT(0, 1);
        C = POINT(1, 0);
    }
}

/**
 * The normal constructor method of the TRIANGLE class (which takes three POINT objects as function inputs) returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the parameter named A,
 * whose POINT property named B represents the same coordinate pair as the parameter named B, and
 * whose POINT property named C represents the same coordinate pair as the parameter named C
 * if parameter A, parameter B, and parameter C represent a non-degenerate triangle.
 * 
 * If parameter A, parameter B, and parameter C do not represent a non-degenerate triangle,
 * this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 * 
 * (The keyword this refers to the TRIANGLE object which is returned by the TRIANGLE(POINT A, POINT B, POINT C) method of the TRIANGLE class).
 */
TRIANGLE::TRIANGLE(POINT A, POINT B, POINT C)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    if (points_form_nondegenerate_triangle(A, B, C))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = POINT(0, 0);
        this -> B = POINT(0, 1);
        this -> C = POINT(1, 0);
    }
}

/**
 * The copy constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the POINT property named A which belongs to the input TRIANGLE object,
 * whose POINT property named B represents the same coordinate pair as the POINT property named B which belongs to the input TRIANGLE object, and
 * whose POINT property named C represents the same coordinate pair as the POINT property named C which belongs to the input TRIANGLE object. 
 * 
 * (The keyword this refers to the TRIANGLE object which is returned by the copy constructor method of the TRIANGLE class).
 */
TRIANGLE::TRIANGLE(const TRIANGLE & triangle)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    this -> A = triangle.A;
    this -> B = triangle.B;
    this -> C = triangle.C;
}
