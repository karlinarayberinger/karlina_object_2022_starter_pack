/**
 * file: polygon.cpp
 * type: C++ (source file)
 * date: 21_NOVEMBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "polygon.h" 

/**
 * The default POLYGON constructor sets the color value to "orange".
 * 
 * Note that POLYGON type objects cannot be instantiated (i.e. occupy space in memory)
 * because the POLYGON class is abstract. 
 * 
 * (pointer-to-POLYGON type variables can be instantiated, however, and used to store the memory addresses
 * of objects whose classes are derived from the POLYGON).
 * 
 * POLYGON * pointer_to_polygon; // The pointer_to_polygon variable can point to instances of non-abstract derived classes of POLYGON such as QUADRILATERAL.
 * pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of during program compile time).
 * pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method and not the QUADRILATERAL print method.
 * 
 * The POLYGON constructor is implemented only by classes which are
 * descendents of the POLYGON class.
 */
POLYGON::POLYGON()
{
    color = "orange";
}

/**
 * The virtual methods get_area() and get_perimeter() must be defined by 
 * classes which are derived from POLYGON.
 */
double POLYGON::get_area() { return 0.0; }
double POLYGON::get_perimeter() { return 0.0; }

/**
 * The descriptor method prints a description of the caller POLYGON instance 
 * (or pointer-to-POLYGON type variable)
 * to the output stream.
 * If no parameter is supplied, output is set to the command line terminal.
 */
void POLYGON::print(std::ostream & output)
{
    output << "\nmemory_address := " << this << ".";
    output << "\ncategory := " << category << ".";
    output << "\ncolor := " << color << ".";
}

/**
 * The descriptor method prints a description of the caller POLYGON instance 
 * (or pointer-to-POLYGON type variable)
 * to the output stream.
 * If no parameter is supplied, output is set to the command line terminal.
 */
std::ostream & operator << (std::ostream & output, POLYGON & polygon)
{
    polygon.print(output);
    return output;
}