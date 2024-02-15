#ifndef ROMAN_TO_INT_H
#define ROMAN_TO_INT_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 10;

class romanType
{
public:
    romanType();
    void input_roman_numeral();
    //Precondition: The input from the user must be
    //a roman numeral and less than 10 in length.
    //Postcondition: Stores user input into a cstring.
    void print_converted_roman_numeral() const;
    //Postcondition: Prints the integer value for the roman numeral
    int convert_roman_numeral_to_number();
    //Postcondition: Converts the roman numeral stored
    //in romanN into a positive integer.
private:
    char romanN[MAX_SIZE];
    int iter; //Stores index position of cstring
    int positive_integer;
    int process_roman_numeral_m(); 
    //Precondition: The value of romanN[index] must be 'M'
    //Postcondition: Returns the total of the roman numerals
    //succeeding M, including the character M itself. 
    //Ex. Returns 1500 for roman numeral MD
    int process_roman_numeral_d(); 
    //Precondition: The value of romanN[index] must be 'D'
    //Postcondition: Returns the total of the roman numerals
    //succeeding D, including the character D itself. 
    //Ex. Returns 515 for roman numeral DXV
    int process_roman_numeral_c(); 
    //Precondition: The value of romanN[index] must be 'C'
    //Postcondition: Returns the total of the roman numerals
    //succeeding C, including the character C itself. 
    //Ex. Returns 128 for roman numeral CXXVIII
    int process_roman_numeral_l();
    //Precondition: The value of romanN[index] must be 'L'
    //Postcondition: Returns the total of the roman numerals
    //succeeding L, including the character L itself. 
    //Ex. Returns 84 for roman numeral LXXXIV
    int process_roman_numeral_x();
    //Precondition: The value of romanN[index] must be 'X'
    //Postcondition: Returns the total of the roman numerals
    //succeeding X, including the character X itself. 
    //Ex. Returns 15 for roman numeral XV
    int process_roman_numeral_i();
    //Precondition: The value of romanN[index] must be 'I'
    //Postcondition: Returns the total of the roman numerals
    //succeeding I, including the character I itself. 
    //Ex. Returns 9 for roman numeral IX
    int process_roman_numeral_v();
    //Precondition: The value of romanN[index] must be 'V'
    //Postcondition: Returns the total of the roman numerals
    //succeeding V, including the character V itself. 
    //Ex. Returns 8 for roman numeral VIII
};

#endif