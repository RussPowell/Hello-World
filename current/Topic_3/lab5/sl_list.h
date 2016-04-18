/*
 * Name        : sl_list.h
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
            // Default Constructor (*MODIFY*)
            // sets head_ to NULL
            // sets tail_ to NULL (*NEW*)
            // sets size_ to 0
            
        ~SLList();
            //Destructor
            //calls Clear()
            
        void Insert(int newContents);
            /*(*NEW*)
            --creates a new SLNode with the contents of the parameter and
            inserts it into the correct position in the list. The list
            will be sorted with the lowest values in the front (head) and the
            largest values in the back (tail).
            */
        
        bool RemoveFirstOccurence(int deletion);
            /*(*NEW*)
            --remove the first occurence of the supplied parameter
            found as the data of a node. Return true on successful
            removal or false if the list is empty or if the value
            is not found.
            */

        int GetHead() const;
            // (*NEW*)
            // Returns the contents of the head node
            // (The node head_ is pointing to)
            // Returns 0 if the list is empty
            
        int GetTail() const;
            // (*NEW*)
            // Returns the contents of the tail node
            // (The node tail_ is pointing to)
            // Returns 0 if the list is empty
            
        void Clear(); 
            // (*MODIFY*)
            //clears the entire contents of the list,
            //  freeing all memory associated with all nodes
            //  (*NEW*) - sets tail_ to NULL
            
        unsigned int size() const;
            //accessor for size_
        
        string ToString() const;
            //returns a string representation of the contents
            //of all nodes in the list, in the format
            //NUM1, NUM2, ..., LASTNUM
            //returns the empty string on an empty list (i.e. returns "")
            
    private:
        void InsertHead(int contents);
            // (*MODIFY*)
            // creates a new dynamic SLNode with the contents of 
            // the parameter and attaches as the new head of the list
            // (*NEW*) - Handle tail_ when the first node in the list is added
        
        void InsertTail(int contents);
            // (*NEW*)
            // creates a new dynamic SLNode with the contents of 
            // the parameter and attaches as the last node (tail) of the list
        
        void RemoveHead();
            // (*MODIFY*)
            // removes the head node from the list,
            // or does nothing if the list is empty
            // (*NEW*) - Handle tail_ when the last remaining node in the list is removed
            
        void RemoveTail(); 
            // (*NEW*)
            // removes the last node (tail) from the list,
            // or does nothing if the list is empty
            
        SLNode* head_;  //points to the first node in a singly-linked list
        SLNode* tail_; // (*NEW*)points to the last node in a singly-linked list
        unsigned int size_;//stores the count of the number of nodes in the list

};

#endif