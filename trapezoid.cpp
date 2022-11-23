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
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
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
    angle_opposite_of_c1 = floor(acos(((a1 * a1) + (b1 * b1) - (c1 * c1)) / (2 * a1 * b1)) * (180 / PI));

    interior_angle_of_A = angle_opposite_of_b0;
    interior_angle_of_B = angle_opposite_of_c0 + angle_opposite_of_c1;
    interior_angle_of_C = angle_opposite_of_a1;
    interior_angle_of_D = angle_opposite_of_b1 + angle_opposite_of_a0;

    /* sides of quadrilateral */
    a = B.get_distance_from(C);
    b = C.get_distance_from(D);
    c = D.get_distance_from(A);
    d = A.get_distance_from(B);

    if (!points_represent_unique_coordinate_pairs(A,B,C,D) || !interior_angles_add_up_to_360_degrees()) return false;
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
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;

    // first triangle
    a0 = A.get_distance_from(B);
    b0 = B.get_distance_from(D);
    c0 = D.get_distance_from(A);
    angle_opposite_of_a0 = acos(((b0 * b0) + (c0 * c0) - (a0 * a0)) / (2 * b0 * c0)) * (180 / PI);
    angle_opposite_of_b0 = acos(((a0 * a0) + (c0 * c0) - (b0 * b0)) / (2 * a0 * c0)) * (180 / PI);
    angle_opposite_of_c0 = acos(((a0 * a0) + (b0 * b0) - (c0 * c0)) / (2 * a0 * b0)) * (180 / PI);

    // second triangle
    a1 = D.get_distance_from(B);
    b1 = B.get_distance_from(C);
    c1 = C.get_distance_from(D);
    angle_opposite_of_a1 = acos(((b1 * b1) + (c1 * c1) - (a1 * a1)) / (2 * b1 * c1)) * (180 / PI);
    angle_opposite_of_b1 = acos(((a1 * a1) + (c1 * c1) - (b1 * b1)) / (2 * a1 * c1)) * (180 / PI);
    angle_opposite_of_c1 = acos(((a1 * a1) + (b1 * b1) - (c1 * c1)) / (2 * a1 * b1)) * (180 / PI);

    interior_angle_of_A = angle_opposite_of_b0;
    interior_angle_of_B = angle_opposite_of_c0 + angle_opposite_of_c1;
    interior_angle_of_C = angle_opposite_of_a1;
    interior_angle_of_D = angle_opposite_of_b1 + angle_opposite_of_a0;

    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a QUADRILATERAL sized chunk of contiguous memory cells which are allocated to the caller TRIANGLE object.";
    output << "\n&category = " << &category << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named category.";
    output << "\n&color = " << &color << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named color..";
    output << "\n&A = " << &A << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named A.";
    output << "\n&B = " << &B << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named B.";
    output << "\n&C = " << &C << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named C.";
    output << "\n&D = " << &D << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named D.";
    output << "\nsizeof(int) = " << sizeof(int) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which an int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(int *) = " << sizeof(int *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(int **) = " << sizeof(int **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which an pointer-to-pointer-to-int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string) = " << sizeof(std::string) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string *) = " << sizeof(std::string *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string **) = " << sizeof(std::string **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a POINT type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT *) = " << sizeof(POINT *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-POINT type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT **) = " << sizeof(POINT **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-POINT type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON) = " << sizeof(POLYGON) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a POLYGON type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON *) = " << sizeof(POLYGON *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-POLYGON type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON **) = " << sizeof(POLYGON **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-POLYGON type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(QUADRILATERAL) = " << sizeof(QUADRILATERAL) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a QUADRILATERAL type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(QUADRILATERAL *) = " << sizeof(QUADRILATERAL *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-QUADRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(QUADRILATERAL **) = " << sizeof(QUADRILATERAL **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-QUADRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRAPEZOID) = " << sizeof(TRAPEZOID) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a TRAPEZOID type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRAPEZOID *) = " << sizeof(TRAPEZOID *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-TRAPEZOID type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRAPEZOID **) = " << sizeof(TRAPEZOID **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-TRAPEZOID type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\ncategory = " << category << ". // This is an immutable string type value which is a data member of the caller QUADRILATERAL object.";
    output << "\ncolor = " << color << ". // This is a string type value which is a data member of the caller QUADRILATERAL object.";
    output << "\nA = POINT(" << A.get_X() << "," << A.get_Y() << "). // A represents a point (which is neither B nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nB = POINT(" << B.get_X() << "," << B.get_Y() << "). // B represents a point (which is neither A nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nC = POINT(" << C.get_X() << "," << C.get_Y() << "). // C represents a point (which is neither A nor B nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nC = POINT(" << D.get_X() << "," << D.get_Y() << "). // D represents a point (which is neither A nor B nor C) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\na = B.get_distance_from(C) = " << B.get_distance_from(C) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points B and C.";
    output << "\nb = C.get_distance_from(D) = " << C.get_distance_from(D) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points C and D.";
    output << "\nc = D.get_distance_from(A) = " << D.get_distance_from(A) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points D and A.";
    output << "\nd = A.get_distance_from(B) = " << A.get_distance_from(D) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points A and B.";
    output << "\nA.get_slope_of_line_to(B) = " << A.get_slope_of_line_to(B) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points A and B.";
    output << "\nB.get_slope_of_line_to(C) = " << B.get_slope_of_line_to(C) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\nC.get_slope_of_line_to(D) = " << C.get_slope_of_line_to(D) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points C and D.";
    output << "\nD.get_slope_of_line_to(A) = " << D.get_slope_of_line_to(A) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\ninterior_angle_DAB = interior_angle_of_A = " << interior_angle_of_A << ". // The value represents the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are D and A with the line segment whose endpoints are A and B such that those two line segments intersect at A (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_ABC = interior_angle_of_B = " << interior_angle_of_B << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are A and B with the line segment whose endpoints are B and C such that those two line segments intersect at B (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_BCD = interior_angle_of_C = " << interior_angle_of_C << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are B and C with the line segment whose endpoints are C and D such that those two line segments intersect at C (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_CDA = interior_angle_of_D = " << interior_angle_of_D << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are C and D with the line segment whose endpoints are D and A such that those two line segments intersect at D (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D = " << interior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D << ". // sum of all four approximate interior angle measurements of the quadrilateral represented by the caller QUADRILATERAL object (in degrees and not in radians)";
    output << "\nget_perimeter() = a + b + c + d = " << get_perimeter() << ". // The method returns the sum of the four approximated side lengths of the quadrilateral which the caller QUADRILATERAL object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the four line segments which connect points A to B, B to C, C to D, and D to A.";
    output << "\n--------------------------------------------------------------------------------------------------";
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
    trapezoid.print(output);
    return output;
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