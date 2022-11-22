/**
 * file: quadrilateral.h
 * type: C++ (header file)
 * date: 21_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

// If quadrilateral.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef QUADRILATERAL_H 
#define QUADRILATERAL_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "polygon.h" 

/**
 * QUADRILATERAL is a class which inherits the protected and public data
 * attributes and methods of POLYGON (and POLYGON is an abstract class).
 * 
 * Each QUADRILATERAL instance represents a specific four-sided polygon.
 * 
 * A TRIANGLE object represents an instance in which three unique POINT instances exist 
 * (and such that each one of those three POINT instances represents a unique coordinate pair within the tuple of three objects 
 *  which each represent exactle one two-dimensional point, POINT(X,Y), on a Cartesian grid).
 * 
 * A cyclic polygon's vertices (i.e. points) are each positioned on the edge of a circle
 * inside of which that polygon is inscribed.
 * 
 * Note that all regular polygons (i.e. polygon's whose side lengths are each the same length) 
 * are cyclic. Note that all non-degenerate triangles (i.e. triangles which have a positive area
 * instead of an area of zero due to the fact that a single line passes through all three points)
 * are cyclic.
 * 
 * The public keyword prefacing POLYGON in the class definition below specifies that
 * all the public members of the base class POLYGON will be public in the derived class QUADRILATERAL
 * and that all the protected members of the base class POLYGON will be protected in the derived class QUADRILATERAL.
 * 
 * If the access specifier prefacing POLYGON in the class definition below is protected instead of public, then
 * all the public members of the base class POLYGON will be protected in the derived class QUADRILATERAL
 * and all the protected members of the base class POLYGON will be protected in the derived class QUADRILATERAL.
 * 
 * If the access specifier prefacing POLYGON in the class definition below is private instead of public, then
 * all the public members of the base class POLYGON will be private in the derived class QUADRILATERAL
 * and all the protected members of the base class POLYGON will be private in the derived class QUADRILATERAL.
 * 
 * Note that the private members of a class cannot be accessed from outside of that class (even by derived classes).
 */

/**
 * QUADRILATERAL is a class which inherits the protected and public data
 * attributes and methods of POLYGON (and POLYGON is an abstract class).
 * 
 * A QUADRILATERAL object represents an instance in which four unique POINT instances exist 
 * (and such that each one of those four POINT instances represents a unique coordinate pair within the tuple of four objects 
 *  which each represent exactle one two-dimensional point, POINT(X,Y), on a Cartesian grid).
 * 
 * Each QUADRILATERAL object represents a specific four-sided polygon whose area is a positive real number.
 * 
 * Class members which are set to the protected access specifier
 * are accessible to the base class and to derived classes.
 * 
 * Class members which are set to the private access specifier
 * are only accessible to the base class.
 * 
 * Class members which are set to the public access specifier
 * are accessible to any scope within the program where
 * the base class and its derived classes are implemented.
 */
class QUADRILATERAL: public POLYGON
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a constant (i.e. immutable) string type value.
     */
    const std::string category = "POLYGON/QUADRILATERAL";

    /**
     * POINT type objects A, B, C, and D represent points on a Cartesian plane.
     * Each POINT type object has two int type variables for representing a two-dimensional whole number coordinate pair.
     * The X data attribute of a POINT object represents a whole number position on the horizontal axis (i.e. x-axis) of a Cartesian plane.
     * The Y data attribute of a POINT object represents a whole number position on the vertical axis (i.e. y-axis) of the same Cartesian plane.
     */
    POINT A, B, C, D;

    /**
     * If each of the four whole number coordinate pairs represented by the POINT type input values named _A, _B, _C, and _D each unique whole number coordinate pairs, 
     * return true. 
     * Otherwise, return false.
     */
    bool points_represent_unique_coordinate_pairs(POINT _A, POINT _B, POINT _C, POINT _D);

    /**
     * If sum of the interior angle measurements of the quadrilateral which the caller QUADRILATERAL object represents add up to approximately 360 degrees, 
     * return true.
     * Otherwise, return false.
     */
    bool interior_angles_add_up_to_360_degrees();

    /**
     * If the quadrilateral represented by the caller QUADRILATERAL object represents a polygon 
     * whose vertices _A, _B, _C, and _D each represent unique coordinate pairs and 
     * each connect with exactly two other vertices in that quadrilateral such that
     * the side of the quadrilateral labeled a is the line segment whose endpoints are _B and _C,
     * the side of the quadrilateral labeled b is the line segment whose endpoints are _C and _D,
     * the side of the quadrilateral labeled c is the line segment whose endpoints are _D and _A, and
     * the side of the quadrilateral labeled d is the line segment whose endpoints are _A and _B,
     * return true.
     * Otherwise, return false.
     */
    bool point_sequence_represents_non_hemipolytopes(POINT _A, POINT _B, POINT _C, POINT _D);
    
public:
    
    /**
     * The default constructor of the QUADRILATERAL calls the constructor of the POLYGON class
     * and sets the string type color of the QUADRILATERAL object returned by this funnction to "green" 
     * (which overrides the default color value "orange" which is specified by the POLYGON constructor) and
     * sets the POINT type data member of that quadrilateral named A to POINT(0,0), 
     * sets the POINT type data member of that quadrilateral named B to POINT(0,5), 
     * sets the POINT type data member of that quadrilateral named C to POINT(4,5), and
     * sets the POINT type data member of that quadrilateral named D to POINT(4,0).
     */
    QUADRILATERAL();
    
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
    QUADRILATERAL(std::string color, POINT A, POINT B, POINT C, POINT D);

    /**
     * The copy constructor method of the QUADRILATERAL class 
     * instantiates QUADRILATERAL type objects 
     * whose A value is set to the A value of the input QUADRILATERAL object,
     * whose B value is set to the B value of the input QUADRILATERAL object,
     * whose C value is set to the C value of the input QUADRILATERAL object, and
     * whose D value is set to the D value of the input QUADRILATERAL object.
     */
    QUADRILATERAL(QUADRILATERAL & quadrilateral);

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
    double get_area();

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
    double get_perimeter();
    
    /** 
     * This method overrides the POLYGON class's print method.
     * 
     * The descriptor method prints a description of the caller QUADRILATERAL instance to the output stream.

     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the QUADRILATERAL class,
     * but the friend function does have access to the private and protected members of the QUADRILATERAL class as though
     * the friend function was a member of the QUADRILATERAL class.
     */
    friend std::ostream & operator << (std::ostream & output, QUADRILATERAL & quadrilateral);
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.