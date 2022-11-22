/**
 * file: quadrilateral.cpp
 * type: C++ (source file)
 * date: 21_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.
#include "quadrilateral.h" 

/**
 * If each of the four whole number coordinate pairs represented by the POINT type input values named _A, _B, _C, and _D each unique whole number coordinate pairs, 
 * return true. 
 * Otherwise, return false.
 */
bool QUADRILATERAL::points_represent_unique_coordinate_pairs(POINT _A, POINT _B, POINT _C, POINT _D)
{
    if ((_A.get_X() == _B.get_X()) && (_A.get_Y() == _B.get_Y())) 
    {
        std::cout << "\n\n_A and _B appear to represent the same coordinate pair.";
        std::cout << "\n_A := POINT(" << _A.get_X() << ", " << _A.get_Y() << ").";
        std::cout << "\n_B := POINT(" << _B.get_X() << ", " << _B.get_Y() << ").";
        return false;
    }
    if ((_A.get_X() == _C.get_X()) && (_A.get_Y() == _C.get_Y())) 
    {
        std::cout << "\n\n_A and _C appear to represent the same coordinate pair.";
        std::cout << "\n_A := POINT(" << _A.get_X() << ", " << _A.get_Y() << ").";
        std::cout << "\n_C := POINT(" << _C.get_X() << ", " << _C.get_Y() << ").";
        return false;
    }
    if ((_A.get_X() == _D.get_X()) && (_A.get_Y() == _D.get_Y())) 
    {
        std::cout << "\n\n_A and _D appear to represent the same coordinate pair.";
        std::cout << "\n_A := POINT(" << _A.get_X() << ", " << _A.get_Y() << ").";
        std::cout << "\n_D := POINT(" << _D.get_X() << ", " << _D.get_Y() << ").";
        return false;
    }
    if ((_B.get_X() == _C.get_X()) && (_B.get_Y() == _C.get_Y())) 
    {
        std::cout << "\n\n_B and _C appear to represent the same coordinate pair.";
        std::cout << "\n_B := POINT(" << _B.get_X() << ", " << _B.get_Y() << ").";
        std::cout << "\n_C := POINT(" << _C.get_X() << ", " << _C.get_Y() << ").";
        return false;
    }
    if ((_B.get_X() == _D.get_X()) && (_B.get_Y() == _D.get_Y())) 
    {
        std::cout << "\n\n_B and _D appear to represent the same coordinate pair.";
        std::cout << "\n_B := POINT(" << _B.get_X() << ", " << _B.get_Y() << ").";
        std::cout << "\n_D := POINT(" << _D.get_X() << ", " << _D.get_Y() << ").";
        return false;
    }
    if ((_C.get_X() == _D.get_X()) && (_C.get_Y() == _D.get_Y())) 
    {
        std::cout << "\n\n_C and _D appear to represent the same coordinate pair.";
        std::cout << "\n_C := POINT(" << _C.get_X() << ", " << _C.get_Y() << ").";
        std::cout << "\n_D := POINT(" << _D.get_X() << ", " << _D.get_Y() << ").";
        return false;
    }
    return true;
}

/**
 * If sum of the interior angle measurements of the quadrilateral which the caller QUADRILATERAL object represents add up to approximately 360 degrees, 
 * return true.
 * Otherwise, return false.
 */
bool QUADRILATERAL::interior_angles_add_up_to_360_degrees()
{
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;
    double sum_of_interior_angles = 0.0;

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

    sum_of_interior_angles = interior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D;

    // Allow for there to be a +/- 2 margin of error for the value stored in sum_of_interior_angles with the ideal value being 360.
    if ((sum_of_interior_angles >= 358) && (sum_of_interior_angles <= 362)) return true;
    std::cout << "\nThe interior angles of the quadrilateral must add up to 360 degrees.";
    std::cout << "\ninterior_angle_of_A := " << interior_angle_of_A << " degrees.";
    std::cout << "\ninterior_angle_of_B := " << interior_angle_of_B << " degrees.";
    std::cout << "\ninterior_angle_of_C := " << interior_angle_of_C << " degrees.";
    std::cout << "\ninterior_angle_of_D := " << interior_angle_of_D << " degrees.";
    return false;
}

/**
 * If the interior angle measurement of the angle whose vertice is A is identical to the interior angle measurement of the angle whose vertice is C and
 * if the interior angle measurement of the angle whose vertice is B is identical to the interior angle measurement of the angle whose vertice is D,
 * return true.
 * Otherwise, return false.
 */
bool QUADRILATERAL::opposite_interior_angles_are_equal()
{

}

/**
 * If the quadrilateral represented by the caller QUADRILATERAL object represents a quadrilateral 
 * whose vertices _A, _B, _C, and _D each represent a unique coordinate pair and 
 * each vertice connects with exactly two other vertices in that quadrilateral such that
 * the side of the quadrilateral labeled a is the line segment whose endpoints are _B and _C,
 * the side of the quadrilateral labeled b is the line segment whose endpoints are _C and _D,
 * the side of the quadrilateral labeled c is the line segment whose endpoints are _D and _A, 
 * the side of the quadrilateral labeled d is the line segment whose endpoints are _A and _B, and
 * such that the four interior angles of that quadrilateral add up to approximately 360 degrees,
 * return true.
 * Otherwise, return false.
 * 
 * (A bowtie quadrilateral has no diagonal lines because two sides of the quadrilateral intersect each other).
 */
bool QUADRILATERAL::point_sequence_represents_non_bowtie_quadrilateral(POINT _A, POINT _B, POINT _C, POINT _D)
{
    if (!points_represent_unique_coordinate_pairs(_A, _B, _C, _D))
    {
        std::cout << "\n\n_A, _B, _C, and _D do not each represent unique coordinate pairs.";
        std::cout << "\nHence, point_sequence_represents_non_hemipolytopes(_A, _B, _C, _D) is returning false.";
        return false;
    }

    // Create a test QUADRILATERAL object by which to run the following helper method.
    QUADRILATERAL test_quadrilateral;
    test_quadrilateral.A.set_X(_A.get_X());
    test_quadrilateral.A.set_Y(_A.get_Y());
    test_quadrilateral.B.set_X(_B.get_X());
    test_quadrilateral.B.set_Y(_B.get_Y());
    test_quadrilateral.C.set_X(_C.get_X());
    test_quadrilateral.C.set_Y(_C.get_Y());
    test_quadrilateral.D.set_X(_D.get_X());
    test_quadrilateral.D.set_Y(_D.get_Y());

    if (!test_quadrilateral.interior_angles_add_up_to_360_degrees())
    {
        std::cout << "\n\n_A, _B, _C, and _D do not represent a quadrilateral whose interior angles add up to 360 degrees.";
        std::cout << "\nHence, point_sequence_represents_non_hemipolytope(_A, _B, _C, _D) is returning false.";
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
 * The default constructor of the QUADRILATERAL calls the constructor of the POLYGON class
 * and sets the string type color of the QUADRILATERAL object returned by this funnction to "green" 
 * (which overrides the default color value "orange" which is specified by the POLYGON constructor) and
 * sets the POINT type data member of that quadrilateral named A to POINT(0,0), 
 * sets the POINT type data member of that quadrilateral named B to POINT(0,5), 
 * sets the POINT type data member of that quadrilateral named C to POINT(4,5), and
 * sets the POINT type data member of that quadrilateral named D to POINT(4,0).
 */
QUADRILATERAL::QUADRILATERAL();
    
/**
 * The normal constructor of QUADRILATERAL attempts to set
 * the string type data member of this to the input string type value named color and
 * the POINT type data member of this to the input POINT type value named A and
 * the POINT type data member of this to the input POINT type value named B and
 * the POINT type data member of this to the input POINT type value named C and
 * the POINT type data member of this to the input POINT type value named D.
 * 
 * (The keyword this refers to the QUADRILATERAL object which is returned by this function).
 * 
 * If A, B, C, and D represent points which do not connect to each other linearly in the order specified by this sentence,
 * then set the data members of this named A, B, C, and D to have the same coordinate values as 
 * the data members named A, B, C, and D of a QUADRILATERAL object returned by the default QUADRILATERAL constructor.
 */
QUADRILATERAL::QUADRILATERAL(std::string color, POINT A, POINT B, POINT C, POINT D);

/**
 * The copy constructor method of the QUADRILATERAL class 
 * instantiates QUADRILATERAL type objects 
 * whose A value is set to the A value of the input QUADRILATERAL object,
 * whose B value is set to the B value of the input QUADRILATERAL object,
 * whose C value is set to the C value of the input QUADRILATERAL object, and
 * whose D value is set to the D value of the input QUADRILATERAL object.
 */
QUADRILATERAL::QUADRILATERAL(QUADRILATERAL & quadrilateral);

/**
 * The QUADRILATERAL class implements the virtual get_area() method of the POLYGON class.
 * 
 * The getter method returns the area of the quadrilateral represented by the caller QUADRILATERAL object
 * using using Heron's Formula to 
 * compute the area of each of the two triangles which comprise that quadrilateral.
 * 
 * Let AB be the length of the line segment whose endpoints are A and B.
 * Let BC be the length of the line segment whose endpoints are B and C.
 * Let CA be the length of the line segment whose endpoints are C and A.
 * Let CD be the length of the line segment whose endpoints are C and D.
 * Let DA be the length of the line segment whose endpoints are D and A.
 * 
 * Let the first triangle be the area which is enclosed inside line segments represented by AB, BC, and CA.
 * Let the second triangle be the area which is enclosed inside line segments represented by AC, CD, and DA.
 * 
 * Then compute the area of each triangle using Heron's Formula as follows:
 * 
 * Let s be the semiperimeter of a triangle (i.e. the perimeter divided by 2).
 * Let a, b, and c be the side lengths of a triangle.
 * 
 * Then 
 * 
 * area = square_root( s * (s - a) * (s - b) * (s - c) ).
 * 
 * Finally, return the sum of the two triangle areas.
 */
double QUADRILATERAL::get_area();

/**
 * The QUADRILATERAL class implements the virtual get_perimeter() method of the POLYGON class.
 * 
 * The getter method returns the perimeter of the quadrilateral represented by the caller QUADRILATERAL object
 * by adding up the four side lengths of that quadrilateral.
 * 
 * Let AB be the length of the line segment whose endpoints are A and B.
 * Let BC be the length of the line segment whose endpoints are B and C.
 * Let CD be the length of the line segment whose endpoints are C and D.
 * Let DA be the length of the line segment whose endpoints are D and A.
 * 
 * Then return the sum of AB, BC, CD, and DA.
 */
double QUADRILATERAL::get_perimeter();
    
/** 
 * This method overrides the POLYGON class's print method.
 * 
 * The descriptor method prints a description of the caller QUADRILATERAL instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void print(std::ostream & output = std::cout);

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the QUADRILATERAL class,
 * but it does have access to the members of QUADRILATERAL as though
 * it were a member of that class.
 */
std::ostream & operator << (std::ostream & output, QUADRILATERAL & quadrilateral);