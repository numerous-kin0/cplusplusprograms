//Created: 23-11-2023
//Author: Mabo Giqwa
//Purpose: Converts roman numerals between 1- 1500 to positive
//integers.
//Constraint 1: The romanType class needs functions that
//will validate input, for example, the program converts
//the input LIXIX even though it is not a roman numeral.
//Constraint 2: The romanType class needs a second constructor
//so it will be easier to initialize the member variable romanN
//instead of using input_roman_numeral().

#include <iostream>
#include "roman_to_int.h"

int main()
{
    romanType roman_numeral_1;

    roman_numeral_1.input_roman_numeral();

    roman_numeral_1.convert_roman_numeral_to_number();

    roman_numeral_1.print_converted_roman_numeral();

    return 0;
}
