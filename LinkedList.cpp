//The implementation file of class LinkedList
//Contains the implementation of the class's constructors and
//function prototypes in the header file.
//Written by M.Giqwa
//19-07-2023
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::LinkedList(int value)
{
    head = new Node; //creates a new Node
    head->data = value; //assigns a value to the new node
    head->link = nullptr;
}

LinkedList::~LinkedList()
{
    NodePtr currPtr;

    currPtr = head;

    if (currPtr != nullptr) {

        while (currPtr != nullptr)
        {
            NodePtr prevPtr = new Node; //creates a dynamic NodePtr variable
            prevPtr = currPtr;          //so it does not delete a pointer that is already
            currPtr = currPtr->link;    //deallocates
            delete prevPtr;             //The line currPtr = currPtr->link points onto the next
        }                               //node to be deleted.
    }
    else
        delete currPtr;
}                                       //The dynamic pointer prevPtr moves on node before currPtr on a linked list
void LinkedList::addElementToList(int value)
{
    NodePtr tempPtr;

    tempPtr = new Node;
    tempPtr->data = value;
    tempPtr->link = head; //This line of code links the
                          //the new node to the existing linked list
    head = tempPtr; //The head of the node is set to the newly create node
}
Node* LinkedList::buildListForward(int num)
{
    NodePtr first, newNode;
    NodePtr last;

    first = nullptr;

    cout << "Enter -999 to terminate the loop" << endl;
    while(num != -999)
    {
        newNode = new Node;
        newNode->data = num;
        newNode->link = nullptr;

        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
        cout << "Enter another value:" << endl;
        cin >> num;
    }

    return first;
}
void LinkedList::destroyLinkedList()
{
    NodePtr currPtr;

    currPtr = head;

    if (currPtr != nullptr) {

        while (currPtr != nullptr)
        {
            NodePtr prevPtr = new Node; //creates a dynamic NodePtr variable
            prevPtr = currPtr;          //so it does not delete a pointer that is already
            currPtr = currPtr->link;    //deallocates
            delete prevPtr;             //The line currPtr = currPtr->link points onto the next
        }
                                //node to be deleted.
    }
    head = nullptr;
}
int LinkedList::getLength() const
{
    NodePtr iter;
    int num;

    num = 0;
    for(iter = head; iter != nullptr; iter = iter->link)
    {
        num++;
    }

    return num;
}
Node* LinkedList::getHead()
{
    return head;
}
void LinkedList::discardNode(int valueToBeDeleted)
{
    int sentinel = 0;
    int count_iter = 0;

    NodePtr before = head;
    NodePtr discard = head;


    while(sentinel != -1)
    {
        count_iter++;

        if(count_iter > 2)
            before = before->link;
        //The node before of type NodePtr starts traversing the list
        //when the node discard of type NodePtr has moved past two
        //nodes

        if (discard->data == valueToBeDeleted && count_iter == 1)
        {
            before = before->link;
            head = before;
            sentinel = -1;
            delete discard;
        }
        //The if statement executes when the first node contains the
        //value to be deleted.
        else if (discard->data == valueToBeDeleted && discard->link == nullptr)
        {
            before->link = nullptr;
            sentinel = -1;
            delete discard;
        }
       //The else if will execute when the node to be deleted is the last node
       else if (discard->data == valueToBeDeleted)
        {
            cout << "The middle node is about to be deleted" << endl;
            before->link = discard->link;
            sentinel = -1;
            delete discard;
        }
        //the else if execute when the node to be deleted is situated
        //somewhere in the middle of the linked list
        else if(discard->data != valueToBeDeleted && discard->link == nullptr) {
            cout << "The value " << valueToBeDeleted << " is not in the list" << endl << endl;
            sentinel = -1;
        }
        //This else if is executed when the value is not found


        if(before->link != nullptr)
            discard = discard->link;
        //The if statement will ensure that discard will not iterate when it is
        //deallocated
    }
}

void LinkedList::divideList(LinkedList& dividedList)
{
     NodePtr first = dividedList.getHead();
     NodePtr second;

     NodePtr middle;
     NodePtr current;

     if (first == nullptr) //if list is empty
         second = nullptr;
     else if (first->link == nullptr)
	 second = nullptr;
     else
     {
         middle = first;
         current = first->link;

         if (current != nullptr)  //list has more than two nodes
            current = current->link;

         while (current != nullptr)
         {
            middle = middle->link;
            current = current->link;
            if (current != nullptr)
                 current = current->link;
         }

         second = middle->link;  //second points to the first
                                //node of the second sublist
         middle->link = nullptr; //set the link of the last node
     				 //of the first sublist to nullptr
	} //end else
	head = second;
} //end divideList
void LinkedList::mergeList(LinkedList list_1, LinkedList list_2)
{
     NodePtr lastSmall, first;
     NodePtr newHead, second;

     first = list_1.getHead();
     second = list_2.getHead();

     if (first == nullptr)
	    cout << "First list is empty" << endl;
     else if (second == nullptr)
        cout << "Second list is empty" << endl;
     else
     {
          if (first->data < second->data)
          {
               newHead = first;
               first = first->link;
               lastSmall = newHead;
          }
          else
          {
               newHead = second;
               second = second->link;
               lastSmall = newHead;
          }

          while (first != nullptr && second != nullptr)
          {
                if (first->data < second->data)
                {
                    lastSmall->link = first;
                    lastSmall = lastSmall->link;
                    first = first->link;
                }
                else
                {
                    lastSmall->link = second;
                    lastSmall = lastSmall->link;
                    second = second->link;
                }
          }  //end while

          if (first == nullptr)
              lastSmall->link = second;
          else
              lastSmall->link = first;

	  head = newHead;
     }
}//end mergeList
void LinkedList::printLinkedList()
{
    NodePtr iter;

    cout << "Elements of the linked list:" << endl;
    for(iter = head; iter != nullptr; iter = iter->link)
    {
        cout << iter->data << " ";
    } //prints the linked list
    cout << endl;
}
