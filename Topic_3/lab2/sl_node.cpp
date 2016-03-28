/*
 * Name        : sl_node.cpp
 * Author      : Russell Powell
 * Description : Define class SLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#include "sl_node.h"
SLNode::SLNode()
{
    next_node_ = NULL;
    contents_ = 0;
}
    //sets next_node_ to NULL
    //sets contents_ to 0

SLNode::SLNode(int contents)
{
    next_node_ = NULL;
    contents_ = contents;
}
    //int parameter assigned to contents_
    //sets next_node to NULL

SLNode::~SLNode(){}
    //does nothing

void SLNode::set_contents(int contents)
{
    contents_ = contents;
}
    //mutator for contents_

int SLNode::contents() const
{
   return contents_; 
}
    //accessor for contents_

void SLNode::set_next_node(SLNode* next_node)
{
    next_node_ = next_node;
}
    //mutator for next_node_

SLNode* SLNode::next_node() const
{
    return next_node_;
    
}
    //accessor for next_node_ 