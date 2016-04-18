/*
 * Name        : DLList.h
 * Author      : Russell Powell
 * Description : Declare class DLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Mike Harris 
 *
 * to contain all of the functionality of a doubly-linked list: push front, push back, pop front, pop back, insert (sorted), remove, retrieve, overloaded operator <<, constructor, destructor, clear, size
data members:
 */
 
#ifndef DLList_H
#define DLList_h
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class DLList
{
    public:
        DLList ();                                      // initialize count to zero, head and tail to NULL
        
        ~DLList ();                                     // call clear function
        
        unsigned int getSize () const;                  // return count
        
        void pushFront (int newContents);               // create new DLNode with newContents and attach at head
        
        void pushBack (int newContents);                //create new DLNode with newContents and attach at tail
        
        void insert (int newContents);                  //create new DLNode with newContents and insert in ascending (based on newContents) order
        
        int getFront () const;                          //return the value of the contents of the head node
                                                        //throw an exception (throw "LIST EMPTY") if the list is empty
        
        int getBack () const;                           //return the value of the contents of the tail node
                                                        //throw an exception (throw "LIST EMPTY") if the list is empty
        
        bool get (int target) const;                    //return true if target is in list, else return false
        
        void popFront ();                               //remove current head node; do nothing if list is empty
        
        void popBack ()                                 //remove current tail node; do nothing if list is empty
        
        bool removeFirst (int target);                  //remove the first instance of a DLNode containing target; do nothing if target is not found
        
        bool removeAll (int target);                    //remove all instances of DLNode containing target; do nothing if target is not found
        
        void clear ();                                  //clear all nodes from list, reset count to zero, set head and tail to NULL
        
        friend ostream& operator<< (ostream& out, const DLList& src);
                                                        //display the contents of each node in the list, formatted per the program specification ("NUM1,NUM2,NUM3,...,NUMX"), to the output stream out

    private:
        int NodeCount_;
        DLNode* head_;
        DLNode* tail_;
};
#endif
         