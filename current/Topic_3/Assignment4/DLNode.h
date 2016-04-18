/*
 * Name        : DLNode.h
 * Author      : Russell Powell
 * Description : Declare class DLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class DLNode
{
    public:
        DLNode ();                                      //initialize contents to zero, next and previous to NULL
        DLNode (int newContents);                       //initialize contents to newContents, next and previous to NULL
        virtual ~DLNode();                              //nothing to be done
        void setContents (int newContents);
        void setNext (DLNode* newNext);
        void setPrevious (DLNode* newPrevious);
        int getContents () const;
        DLNode* getNext () const;
        DLNode* getPrevious () const;

    private:
        int contents;
        DLNode* previous_node; 
        DLNode* next_node;
    
};
#endif