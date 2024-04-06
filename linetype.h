//Interface file
#ifndef LINETYPE_H
#define LINETYPE_H

#include <iostream>
#include <cmath>

class lineType
{
public:
    double get_slope() const;
    //Postcondition: Returns the slope of a line of the form a_1x + b_1y = c_1
    bool check_equality(const lineType&) const;
    //Postcondition: Returns boolean value which indicates whether two equations
    //are equal or not.
    bool check_if_parallel(const lineType&) const;
    //Postcondition: Returns a boolean value which indicates whether two equations 
    //are parallel or not.
    bool check_if_perpendicular(const lineType&) const;
    //Postcondition: Returns a boolean value which indicates whether two equations are 
    //perpendicular or not.
    double get_a_in_explicit_form() const;
    //Postcondition: Returns the value of A in an explicit form y = C - Ax where A = a/b
    double get_c_in_explicit_form() const;
    //Postcondition: Returns the value of C in an explicit form y = C - Ax where C = c/b
    double get_x_intersection(const lineType&);
    //Precondition: The lines must not be parallel.
    //Postcondition: Returns the x intersection of two lines of the form y = mx + c
    double get_y_intersection(double);
    //Postcondition: Returns the y value of the intersection of two lines that are not
    //parallel.
    void print_intersection_of_lines(const lineType& line2);
    //Postcondition: Prints the intersection of two lines that are not parallel.
    lineType();
    //Default constructor
    lineType(double, double, double);
    //The values for the formal parameters are represented as Ax + By = C, in the standard
    //form.
private:
    double a;
    double b;
    double c;
};

#endif
