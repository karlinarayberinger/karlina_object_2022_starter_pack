/**
 * file: trapezoid.cpp
 * type: C++ (source file)
 * date: 22_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRAPEZOID class.
#include "trapezoid.h" 

/**
 * The helper method determines whether or not the caller TRAPEZOID instance represents a
 * quadrilateral with exactly two parallel opposite sides whose lengths are not identical.
 * Return true if the caller TRAPEZOID satisfies those conditions. Otherwise, return false.
 */
bool TRAPEZOID::is_trapezoid()
{
    double a = 0.0, b = 0.0, c = 0.0;
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;
    double sum_of_interior_angles = 0.0;

    // first triangle
    a0 = floor(A.get_distance_from(B));
    b0 = floor(B.get_distance_from(D));
    c0 = floor(D.get_distance_from(A));
    angle_opposite_of_a0 = floor(acos(((b0 * b0) + (c0 * c0) - (a0 * a0)) / (2 * b0 * c0)) * (180 / PI));
    angle_opposite_of_b0 = floor(acos(((a0 * a0) + (c0 * c0) - (b0 * b0)) / (2 * a0 * c0)) * (180 / PI));
    angle_opposite_of_c0 = floor(acos(((a0 * a0) + (b0 * b0) - (c0 * c0)) / (2 * a0 * b0)) * (180 / PI));

    // second triangle
    a1 = floor(D.get_distance_from(B));
    b1 = floor(B.get_distance_from(C));
    c1 = floor(C.get_distance_from(D));
    angle_opposite_of_a1 = floor(acos(((b1 * b1) + (c1 * c1) - (a1 * a1)) / (2 * b1 * c1)) * (180 / PI));
    angle_opposite_of_b1 = floor(acos(((a1 * a1) + (c1 * c1) - (b1 * b1)) / (2 * a1 * c1)) * (180 / PI));
    angle_opposite_of_c1 = floor(acos(((a1 * a1) + (b1 * b1) - (c1 * c1)) / (2 * a1 * b1)) * (180 / PI);

    interior_angle_of_A = angle_opposite_of_b0;
    interior_angle_of_B = angle_opposite_of_c0 + angle_opposite_of_c1;
    interior_angle_of_C = angle_opposite_of_a1;
    interior_angle_of_D = angle_opposite_of_b1 + angle_opposite_of_a0;

    /* sides of quadrilateral */
    a = B.get_distance_from(C);
    b = C.get_distance_from(D);
    c = D.get_distance_from(A);
    d = A.get_distance_from(B);

    if (!points_represent_unique_coordinate_pairs() || !interior_angles_add_up_to_360_degrees()) return false;
    if (((a == c) && (b != d)) || ((a != c) && (b == d))) return false;
    return true;
}

/**
 * The default constructor of the TRAPEZOID class calls the constructor of the QUADRILATERAL class and
 * sets the POINT type data member of the TRAPEZOID object returned by this function named A to POINT(0,0), 
 * sets the POINT type data member of the TRAPEZOID object returned by this function named B to POINT(1,1), 
 * sets the POINT type data member of the TRAPEZOID object returned by this function named C to POINT(2,1), and
 * sets the POINT type data member of the TRAPEZOID object returned by this function named D to POINT(3,0).
 */
TRAPEZOID::TRAPEZOID()
{
    std::cout << "\n\nCreating the TRAPEZOID type object whose memory address is " << this << "...";
    A = POINT(0,0);
    B = POINT(1,1);
    C = POINT(2,1);
    D = POINT(3,0);
}

/**
 * The normal constructor of TRAPEZOID attempts to set
 * the string type data member of this to the input string type value named color and
 * the POINT type data member of this named A to the input POINT type value named A and
 * the POINT type data member of this named B to the input POINT type value named B and
 * the POINT type data member of this named C to the input POINT type value named C and
 * the POINT type data member of this named D to the input POINT type value named D.
 * 
 * (The keyword this refers to the QUADRILATERAL object which is returned by this function).
 * 
 * If A, B, C, and D represent unique points on a Cartesian plane and
 * if the interior angles of the quadrilateral which those points would represent add up to 360 degrees and
 * if the area of the quadrilateral which those points represents is larger than zero,
 * use the input POINT values as the POINT values for the QUADRILATERAL object which is returned by this function.
 */
TRAPEZOID::TRAPEZOID(std::string color, POINT A, POINT B, POINT C, POINT D)
{
    std::cout << "\n\nCreating the TRAPEZOID type object whose memory address is " << this << "...";
}

/**
 * The copy constructor of TRAPEZOID creates a clone of 
 * the input TRAPEZOID instance.
 */
TRAPEZOID::TRAPEZOID(TRAPEZOID & trapezoid)
{
    std::cout << "\n\nCreating the TRAPEZOID type object whose memory address is " << this << "...";
    A = trapezoid.A;
    B = trapezoid.B;
    C = trapezoid.C;
    D = trapezoid.D;
    color = trapezoid.color;
}

/** 
 * This method overrides the QUADRILATERAL class's print method.
 * 
 * The descriptor method prints a description of the caller TRAPEZOID instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void TRAPEZOID::print(std::ostream & output)
{

}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the TRAPEZOID class,
 * but the friend function does have access to the private and protected members of the TRAPEZOID class as though
 * the friend function was a member of the TRAPEZOID class.
 */
std::ostream & operator << (std::ostream & output, TRAPEZOID & trapezoid)
{

}

/**
 * The destructor method of the TRAPEZOID class de-allocates memory which was used to 
 * instantiate the TRAPEZOID object which is calling this function.
 * 
 * The destructor method of the TRAPEZOID class is automatically called when 
 * the program scope in which the caller TRAPEZOID object was instantiated terminates.
 */
TRAPEZOID::~TRAPEZOID()
{
    std::cout << "\n\nDeleting the TRAPEZOID type object whose memory address is " << this << "...";
}