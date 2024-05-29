//Created: 06-04-2024
//Author: Mabo Giqwa
//Program Description: Stores the contents polynomial cstring
//in a FIFO data structure
//Constraint: Include a space before and after each - character. 
//N.B There is something wrong with this algorithm, printing terms
//twice.
//A node for the same term is being created twice.
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

const int MAXSIZE = 100;

struct Node
{
   double coefficient;
   double exponent;
   Node *link;
};
typedef Node* NodePtr;

void add_node_to_list(NodePtr& currentNode, double c, double exp);
//Postcondition: Add a node to a linked list that is a FIFO data structure

Node* store_in_linked_list(NodePtr &head, NodePtr &currentNode, char polynomial[MAXSIZE]);
//Postcondition: Processes the polynomial stored in the cstring and stores its coefficient
//and exponent in a linked list FIFO data structure.

int compute_num_of_x_variables(char polynomial[MAXSIZE]);
//Postcondition: Returns the number of x variables in the polynomial cstring.

bool check_if_character_exists(char someChar);
//Precondition: The actual value passed must be of type char.
//Postcondition: Returns a true value if the following character are in the
//cstring: ' ', '+', '-', '\0'. Or else it returns false.

std::string input_string_polynomial(char polynomial[MAXSIZE]);
//Precondition: We pass an polynomial empty cstring as a formal parameter
//Postcondition: Retrieves the polynomial input from the user.

void print_linked_list(NodePtr head);
//Precondition: The list must not be empty
//Postcondition: Prints the contents of each node in the linked list

void deallocate_linked_list(NodePtr &head);
//Precondition: The linked list must be not empty.
//Postcondition: Deallocates the memory used for each node.

int main()
{
    NodePtr head = new Node;
    NodePtr currentPtr;
    char polynomial[MAXSIZE];

    input_string_polynomial(polynomial);

    head = store_in_linked_list(head, currentPtr, polynomial);

    print_linked_list(head);

    std::cout << "Program ended" << std::endl;
}

std::string input_string_polynomial(char polynomial[MAXSIZE])
{
    if (polynomial[0] = '\0') { //Checks if polynomial cstring is empty
        std::cout << "Enter the polynomial: " << std::endl;
        std::cin.getline(polynomial, MAXSIZE);
    } else {
        polynomial[0] = '\0'; //empties polynomial cstring
        std::cout << "Enter the polynomial: " << std::endl;
        std::cin.getline(polynomial, MAXSIZE);
    }

}

int compute_num_of_x_variables(char polynomial[MAXSIZE])
{
    int index = 0;
    int numOfXVariables = 0;

    while (polynomial[index] != '\0')
    {
        if (polynomial[index] == 'x')
            numOfXVariables++;

        index++;
    }

    return numOfXVariables;
}

bool check_if_character_exists(char someChar)
{
    if (someChar == ' ')
        return true;
    else if (someChar == '+')
        return true;
    else if (someChar == '-')
        return true;
    else if (someChar == '\0')
        return true;
    else
        return false;
}


Node* store_in_linked_list(NodePtr &head, NodePtr &currentNode, char polynomial[MAXSIZE])
{
    int currentSign, numOfIterations = 0;
    double numOfXVariables, coefficient_d, exponent_d;
    int lengthOfString = strlen(polynomial);
    int index;

    numOfXVariables = compute_num_of_x_variables(polynomial);

    index = 0;
    while (polynomial[index] != '\0')
    {
        //First iteration
        double value, currentSign; 
        std::string coeff_string = "";
        numOfIterations++;

        if (polynomial[index] == '-') {  
            currentSign = -1;
            index = index + 1; 
        } else {
            currentSign = 1;
        }

        if (polynomial[index] == '+' || polynomial[index] == ' ') {
            index = index + 1; 
        }

        if (isdigit(polynomial[index]))
        {
            if (numOfXVariables > 0)
            {
                while (polynomial[index] != 'x') 
                {
                    coeff_string += polynomial[index];
                    index++;
                } 
            } else {
                while (polynomial[index] != '\0')
                {
                    coeff_string += polynomial[index];
                    exponent_d = 0;
                    index++;
                }
            }
                
            coefficient_d = std::stod(coeff_string);
    
            if (polynomial[index] == 'x') { 
                numOfXVariables--;
                index = index + 1; 

                if (polynomial[index] == '^')
                {
                    index = index + 1;
                    if (isdigit(polynomial[index])) {
                        std::string char_str(1, polynomial[index]);
                        exponent_d = std::stod(char_str);
                    }
                    index = index + 1;
                } else if (polynomial[index] == ' ') {
                    exponent_d = 1;
                    index = index + 1;
                }
            }
        } else if (polynomial[index] == 'x')
        {
            numOfXVariables--;
            coefficient_d = 1;
            index = index + 1;
            if (polynomial[index] == '^') 
            {
                index = index + 1;
                if (isdigit(polynomial[index])) {
                    std::string char_str(1, polynomial[index]);
                    exponent_d = std::stod(char_str);
                }
                index = index + 1; 
            } else if (check_if_character_exists(polynomial[index]))
            {
                exponent_d = 1;
                index = index + 1;
            }
        }

        if (numOfIterations == 1)
        {
            head->coefficient = (coefficient_d*currentSign);
            head->exponent = exponent_d;
            head->link = nullptr;
            currentNode = head;
        } else {
            double c = (coefficient_d*currentSign);
            add_node_to_list(currentNode, c, exponent_d);
        }

        if (polynomial[index] == ' ') {
            index = index + 1;
        }
    }

    return head;
}

void add_node_to_list(NodePtr &currentNode, double c, double exp)
{
    //This creates a FIFO data structure
    NodePtr tempPtr = new Node;
    tempPtr->coefficient = c;
    tempPtr->exponent = exp;
    currentNode->link = tempPtr;
    currentNode = tempPtr;
    tempPtr->link = nullptr;
}
       
void print_linked_list(NodePtr head)
{
    NodePtr iter;

    int i = 1;
    for (iter = head; iter != nullptr; iter = iter->link)
    {
        std::cout << "Term " << i << ": ";
        std::cout << iter->coefficient << " " << iter->exponent << std::endl;
        i++;
    }
}
