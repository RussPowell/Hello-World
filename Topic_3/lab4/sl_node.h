/*
 * Name        : sl_node.h
 * Author      : Russell Powell
 * Description : Declare class SLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef SL_NODE_H
#define SL_NODE_H

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class SLNode
{
    public:
        SLNode();
            //sets next_node_ to NULL
            //sets contents_ to 0
            
        SLNode(int contents);
            //int parameter assigned to contents_
            //sets next_node to NULL
        
        ~SLNode();
            //does nothing
        
        void set_contents(int contents);
            //mutator for contents_
        
        int contents() const;
            //accessor for contents_
        
        void set_next_node(SLNode*);
            //mutator for next_node_
        
        SLNode* next_node() const;
            //accessor for next_node_
            
    private:
        SLNode* next_node_;
            //points to the next node in a singly-linked list
        int contents_;
            //stores the data contents of a SLNode
};

#endif