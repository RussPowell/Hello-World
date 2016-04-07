/*
 * Name        : sl_node.cpp
 * Author      : Russell Powell
 * Description : Define class SLNode
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
 #include "sl_list.h"
 #include "sl_node.h"
        SLList::SLList()
        {
            head_ = NULL;
            size_ = 0;
        }
        
            //sets head_ to NULL
            //sets size_ to 0
        SLList::~SLList()
        {
            Clear();
        }
            //Destructor
            //calls Clear()
        
        void SLList::InsertHead(int contents)
        {
                SLNode* new_node = new SLNode(contents);  //create new node
                new_node->set_next_node(head_);           //points new_node at head's next node
                head_ = new_node;                         //point head at new_node
                size_ = size_ + 1;                        //increment size
        }
            //creates a new dynamic SLNode with the contents of 
            //the parameter and attaches as the new head of the list
        
        void SLList::RemoveHead()
        {
            if (head_ != NULL)
            {
                SLNode* temp;              //create temporary node
                temp = head_;              //point temp at head
                head_ = temp->next_node(); //
                delete temp;               //delete contents of temp(formerly head)
                temp = NULL;               //assign NULL to temp
                size_--;                   //decrement size
            }
        }
            //removes the head node from the list,
            //does nothing if the list is empty  
        void SLList::Clear()
        {
            while (head_ != NULL)
            {
                RemoveHead();             //removes head only if head exists
            }
        }
        reate stringstream variable list
            if (size_ == 0)  
            {
                return "";                  //if size is 0, return and empty string   
            }
            SLNode* temp = head_;
            while(temp != NULL)
            {                                     
                list<<temp -> contents();        //send contents of temp to list
                if(temp -> next_node() != NULL)  //check next node
                {    
                    list << ", ";                //send a (,) to list
                }
                temp = temp -> next_node();      //move temp to next node
            }                                    //loop exits when temp is null                                
                return list.str();               //return contents of list
            //returns a string representation of the contents
            //of all nodes in the list, in the format
            //NUM1, NUM2, ..., LASTNUM
            //returns the empty string on an empty list (i.e. returns "")
        }    