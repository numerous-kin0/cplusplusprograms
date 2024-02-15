#include "roman_to_int.h"

romanType::romanType() : romanN(""), iter(0), positive_integer(0)
{

}

void romanType::input_roman_numeral()
{
    //Gets input from the user.
    std::cout << "Enter a roman numeral between (1-1500): ";
    std::cin.getline(romanN, MAX_SIZE);
}

int romanType::process_roman_numeral_m()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'M')
    {
        total = total + 1000;
        iter = iter + 1;

        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'M') {
                total = total + 1000;
                iter = iter + 1;
            }
            if (romanN[iter] == 'C') {
                subtotal = process_roman_numeral_c();
                total = total + subtotal;
            }
            if (romanN[iter] == 'D') {
                subtotal = process_roman_numeral_d();
                total = total + subtotal;
            }
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x();
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l();
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i();
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v();
                total = total + subtotal;
            }
        }
    }

    return total;
}

int romanType::process_roman_numeral_d()
{
    int total = 0;
    int sentinel = 0;
    int subtotal;
    if (romanN[iter] == 'D')
    {
        total = total + 500;
        iter = iter + 1;
        
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'C') {
                subtotal = process_roman_numeral_c();
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l();
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i();
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v();
                total = total + subtotal;
            }
        }
    }

    return total;
}

int romanType::process_roman_numeral_c()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'C')
    {
        total = total + 100;
        iter++;
    
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'C') {
                total = total + 100;
                iter = iter + 1;
            }
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x();
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l();
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i();
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v();
                total = total + subtotal;
            }
            if (romanN[iter] == 'D') {
                total = 400;
                iter = iter + 1;
            }
            if (romanN[iter] == 'M') {
                total = 900;
                iter = iter + 1;
            }
        }
    }

    return total;
}

int romanType::process_roman_numeral_l()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'L')
    {
        total = total + 50;
        iter++;
        
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x();
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i();
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v();
                total = total + subtotal;
            }
        }
    }

    return total;
    //At this point in time, this function returns the total of whatever
    //segment of the roman numeral it processed and 'leaves' the cstring
    //index position of the next character in the cstring.
}

int romanType::process_roman_numeral_x()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'X')
    {
        total = total + 10;
        iter++;
        
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') 
            {
                total = total + 10;
                iter = iter + 1;
            }
            if (romanN[iter] == 'L')
            {
                total = 40;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'C') {
                total = 90;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i();
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v();
                total = total + subtotal;
            }
        }
    }

    return total;
    //At this point in time, this function returns the total of whatever
    //segment of the roman numeral it processed and 'leaves' the cstring
    //index position of the next character in the cstring.
}

int romanType::process_roman_numeral_i()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'I')
    {
        total = total + 1;
        iter = iter + 1;

        while (sentinel != -1)
        {
            //Ensures that the while loop
            //terminates when the end of the
            //cstring is reached.
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'I') {
                total = total + 1;
                iter = iter + 1;
            }
            if (romanN[iter] == 'V') {
                total = 4;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'X') {
                total = 9;
                iter = iter + 1;
                sentinel = -1;
            }
        }
    }

    return total;
}

int romanType::process_roman_numeral_v()
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'V')
    {
        total = total + 5;
        iter = iter + 1;

        while (sentinel != -1)
        {
            //Ensures that the while loop
            //terminates when the end of the
            //cstring is reached.
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'I') {
                total = total + 1;
                iter = iter + 1;
            }
        }
    }

    return total;
}

void romanType::print_converted_roman_numeral() const
{
    std::string roman_numeral;

    roman_numeral = "";
    for (int i = 0; i < strlen(romanN); i++)
        roman_numeral = roman_numeral + romanN[i];

    std::cout << "The positive integer value for " << roman_numeral;
    std::cout << " is: " << positive_integer << std::endl;
}

int romanType::convert_roman_numeral_to_number()
{
    if (romanN[0] == 'M')
        positive_integer = process_roman_numeral_m();
    if (romanN[0] == 'D')
        positive_integer = process_roman_numeral_d();
    if (romanN[0] == 'C')
        positive_integer = process_roman_numeral_c();
    if (romanN[0] == 'L')
        positive_integer = process_roman_numeral_l();
    if (romanN[0] == 'X')
        positive_integer = process_roman_numeral_x();
    if (romanN[0] == 'I')
        positive_integer = process_roman_numeral_i();
    if (romanN[0] == 'V')
        positive_integer = process_roman_numeral_v();
}