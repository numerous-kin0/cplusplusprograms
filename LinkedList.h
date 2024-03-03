//The header file of class LinkedList
//Contains the class's constructors, function
//prototypes and private pointers.
//Written by M.Giqwa
//19-07-2023
//A lot of syntax errors
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    Node* link;
};
typedef Node* NodePtr;

class LinkedList
{
public:
    LinkedList();
    //Default constructor
    LinkedList(int);
    //Constructor
    ~LinkedList();
    //Destructor
    //Postcondition: Deallocates all the pointers pointing to nodes
    //in a linked list when out of scope
    bool isListEmpty();
    //Postconditiion: The function returns a boolean value
    //true if the linked list is empty and false if not.
    //Method checks if the LinkedList object is empty
    void addElementToList(int);
    //Adds a element to a linked list object
    //Precondition: The formal parameter must be of type NodePtr
    //and a formal parameter of type int
    //Postcondition: The function adds a element of type int
    //to a linked list.
    void discardNode(int);
    //Removes a node containing the specified element from the
    //linked list
    Node searchForValue(int) const;
    //Method that searches for a value in a linked list
    //PostCondition: The method will return the pointer that is pointing the node
    //containing the value and if the value is not found, a statement indicating the
    //latter will be printed
    void divideList(LinkedList& list1);
    //Postcondition: Divides a linked list into two sublists
    void mergeList(LinkedList list_1, LinkedList list_2);
    //Precondition: Both the linked lists must be objects of 'LinkedList'
    //Postcondition: The function will return a combined linked list
    //I will later overload the + operator to enable a more neater
    //syntax and execution of the function to combine linked list.
    void destroyLinkedList();
    //Precondition: The object calling the method must be of type LinkedList
    //Postcondition: Deallocates the memory allocated
    int getLength() const;
    //Postcondition: Returns the length of the linked list.
    Node* getHead();
    //Postcondition: Returns the head pointer.
    Node* buildListForward(int);
    //Postcondition: The elements in the linked list are added forward
    bool equal(LinkedList& list) const;
    //Postcondition: Method checks if two linked list share the same values
    void mergeSort();
    //Postcondition: Sorts the linked list from smallest to largest values
    void sortToSmallest();
    //Postcondition: Sorts the linked list from the largest to the smallest values.
    void printLinkedList();
    //Prints the data contained in the nodes of a linked list
private:
    NodePtr head;
};

//I need to create a copy constructor for the class.
//So I need to overload the assignment operator
//I need to add a method that will search for a value
//I need a method that will combine list, so I will
//overload the plus operator
//I need a method that will sort the linked list
//Method that will destroy a list
//Determine the length of the list

#endif // LINKEDLIST_H
