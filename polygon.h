/**
 * file: polygon.h
 * type: C++ (header file)
 * date: 21_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

// If polygon.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef POLYGON_H 
#define POLYGON_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.
#include "point.h" 

/**
 * POLYGON is an abstract class whose members are the essential components of objects 
 * whose classes are TRILATERAL, RIGHT_TRILATERAL, QUADRILATERAL, TRAPEZOID, RECTANGLE, and SQUARE.
 * 
 * (An abstract class has at least one virtual function).
 * 
 * The POLYGON class includes the POINT class via composition and not via inheritance.
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
class POLYGON
{
protected:
    
    /**
     * category is a description of the POLYGON instance.
     * category is set to a constant (i.e. immutable) string type value.
     */
    const std::string category = "POLYGON";
    
    /**
     * color is an arbitrary string type value.
     * color is used to demonstrate how abstract constructors work.
     */
    std::string color;
    
public:
    
    /**
     * The default POLYGON constructor sets the color value to "orange".
     * 
     * Note that POLYGON type objects cannot be instantiated (i.e. occupy space in memory)
     * because the POLYGON class is abstract. 
     * 
     * (pointer-to-POLYGON type variables can be instantiated, however, and used to store the memory addresses
     * of objects whose classes are derived from the POLYGON).
     * 
     * POLYGON polygon; // This command does not work because POLYGON is an abstract class.
     * POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
     * pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of during program compile time).
     * pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method and not the QUADRILATERAL print method.
     * 
     * The POLYGON constructor is implemented only by classes which are
     * descendents of the POLYGON class.
     */
    POLYGON();
    
    /**
     * The virtual methods get_area() and get_perimeter() 
     * must be defined by classes which are derived from the POLYGON class.
     */
    virtual double get_area() = 0;
    virtual double get_perimeter() = 0;

    /**
     * The descriptor method prints a description of the caller POLYGON instance to the output stream.
     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);

    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the POLYGON class,
     * but that friend function does have access to the private and protected members of the POLYGON class
     * as though that friend function was a member of the POLYGON class.
     */
    friend std::ostream & operator << (std::ostream & output, POLYGON & polygon);
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.