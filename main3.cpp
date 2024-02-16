//The lines in this program are represented in standard form Ax + By = C.
//Created: 2/16/2024
//Author: Mabo Giqwa
//Purpose: Solves linear systems with 2 equations and 2 variables.
//Main file
#include "linetype.h"

int main()
{
    lineType line1(9,3,5);
    lineType line2(9,3,12);
    double x;

    line1.print_intersection_of_lines(line2);

	return 0;
}
