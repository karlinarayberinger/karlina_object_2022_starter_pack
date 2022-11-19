/**
 * file: point.h
 * type: C++ (header file)
 * author: Karlina Ray Beringer
 * date: 19_NOVEMBER_2022
 * license: PUBLIC_DOMAIN
 */

// If point.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef POINT_H 
#define POINT_H

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#define MINIMUM_X -999 // constant which represents minimum X value
#define MAXIMUM_X 999 // constant which represents maximum X value
#define MINIMUM_Y -999 // constant which represents minimum Y value
#define MAXIMUM_Y 999 // constant which represents maximum Y value

/**
 * Define a class which is used to instantiate POINT type objects.
 * 
 * (An object is a variable whose data type is user defined rather than native to the C++ programming language).
 * 
 * A POINT object represents a whole number coordinate pair in the form (X,Y).
 * 
 * X represents a specific whole number position along the x-axis (i.e. horizontal dimension) of a two-dimensional Cartesian grid.
 * Y represents a specific whole number position along the y-axis (i.e. vertical dimension) of the same two-dimensional Cartesian grid.
 * 
 * X stores one integer value at a time which is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 * Y stores one integer value at a time which is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 */
class POINT
{
private:
    int X, Y; // data attributes
public:
    POINT(); // default constructor
    POINT(int X, int Y); // normal constructor
    POINT(const POINT & point); // copy constructor
    int get_X(); // getter method
    int get_Y(); // getter method
    bool set_X(int X); // setter method
    bool set_Y(int Y); // setter method
    double get_distance_from(POINT & point); // getter method
    double get_slope_of_line_to(POINT & point); // getter method
    void print(std::ostream & output = std::cout); // descriptor method
    friend std::ostream & operator << (std::ostream & output, POINT & point); // descriptor method
    ~POINT(); // destructor
};

// end of header file
#endif