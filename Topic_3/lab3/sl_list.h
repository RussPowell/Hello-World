/*
 * Name        : sl_node.h
 * Author      : Russell Powell
 * Description : Declare class SLList
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef SL_LIST_H
#define SL_LIST_H
#include "sl_node.h"
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
#include <sstream>
using std::stringstream;

class SLList
{
    public:
        SLList();
            //sets head_ to NULL
            //sets size_ to 0
        ~SLList();
            //Destructor
            //calls Clear()
        
        void InsertHead(int contents);
            //creates a new dynamic SLNode with the contents of 
            //the parameter and attaches as the new head of the list
        
        void RemoveHead();
            //removes the head node from the list,
            //does nothing if the list is empty
        
        void Clear();
            //clears the entire contents of the list
            //freeing all memory associated with all nodes
            
        unsigned int size() const;
            //accessor for size_
        
        string ToString() const;
            //returns a string representation of the contents
            //of all nodes in the list, in the format
            //NUM1, NUM2, ..., LASTNUM
            //returns the empty string on an empty list (i.e. returns "")
            
    private:
        SLNode* head_;
            //points to the first node in a singly-linked list
        unsigned int size_;
            //stores the count of the number of nodes in the list

};

#endif