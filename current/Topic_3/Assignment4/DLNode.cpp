        /*
 * Name        : DLNode.h
 * Author      : Russell Powell
 * Description : Declare class DLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
 
#include DLNode.h

DLNode::DLNode ()
{ 
    contents = 0;
    previous_node = NULL;                       //initialize contents to zero, next and previous to NULL
    next_node = NULL;
}

DLNode::DLNode (int newContents)
{
    contents = newContents;
    previous_node = NULL;                       //initialize contents to newContents, next and previous to NULL
    next_node = NULL;
}

virtual DLNode:: ~DLNode()
{
    //nothing to be done    
}

void DLNode::setContents (int newContents)
{
    contents = newContents;
}

void DLNode::setNext (DLNode* newNext)
{
    next_node = newNext;
}

void DLNode::setPrevious (DLNode* newPrevious)
{
    previous_node = newPrevious;
}

int DLNode::getContents () const
{
    return contents;
}

DLNode::DLNode* getNext () const
{
    return = next_node;
}

DLNode::DLNode* getPrevious () const
{
    return previous_node;
}