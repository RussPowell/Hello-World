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
            tail_ = NULL;
            size_ = 0;
                // Default Constructor (*MODIFY*)
                // sets head_ to NULL
                // sets tail_ to NULL (*NEW*)
                // sets size_ to 0
        }
        
        SLList::~SLList()
        {
            Clear();
        }
            //Destructor
            //calls Clear()
        
       void SLList::InsertHead(int contents)
        {
            SLNode* new_node = new SLNode(contents);   //create new node
            new_node->set_next_node(head_);           //points new_node at head's next node
            head_ = new_node;                         //point head at new_node
            size_ = size_ + 1;                        //increment size
            if (head_->next_node() == NULL)
            {
                tail_ = new_node;
            }
        
            // (*MODIFY*)
            // creates a new dynamic SLNode with the contents of 
            // the parameter and attaches as the new head of the list
            // (*NEW*) - Handle tail_ when the first node in the list is added
        }
            
        void SLList::InsertTail(int contents)
        {
            SLNode* new_node = new SLNode(contents);
            if (tail_ == NULL)
            {
                tail_ = new_node;
                tail_->set_next_node(NULL);
                head_ = new_node;
                size_++;
            }
            else
            {
                //create new node;
                tail_->set_next_node(new_node);           //points new_node at head's next node
                tail_ = new_node;                         //point head at new_node
                size_++;
            }
            // (*NEW*)
            // creates a new dynamic SLNode with the contents of 
            // the parameter and attaches as the last node (tail) of the list
        }
        
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
                if (size_ == 0)
                {
                    tail_ = NULL;
                }
               
            }
            // (*MODIFY*)
            // removes the head node from the list,
            // or does nothing if the list is empty
            // (*NEW*) - Handle tail_ when the last remaining node in the list is removed
        }
        
        void SLList::RemoveTail()
        {
            if (head_ != NULL)
            //checks if the list is null
            {
                if(head_ -> next_node() == NULL)
                //checks if head is the only node
                {
                    RemoveHead();
                }
                
                else
                {
                    SLNode *temp = NULL;
                    //creates temp node and makes it equal to NULL
                    SLNode *iterator = head_;
                    //creates an iterator and makes it equal to head_
                    
                    while((iterator -> next_node()) != NULL)
                    //makes sure iterator stops at tail_
                    {
                        temp = iterator;
                        //temp is set to iterator before it moves on to the next node
                        iterator = iterator -> next_node();
                        //iterator moves on and points to the next node in the list
                    }
                    //iterator should now point at tail_ and temp points to the node before the tail_ node
                    
                    temp -> set_next_node(NULL);
                    //temp is set to point at NULL
                    tail_ = temp;
                    //tail_ points at temp node
                    delete iterator;
                    //iterator node is deleted
                    iterator = NULL;
                    //iterator points at null
                    size_--;
                    //the size of the list decreases
                }
            }
        }
            
        int SLList::GetHead() const
        {
            if (head_ != NULL)              //check for contents
            {
                return head_->contents();   //get them if available
            }
            else
            {                               
                return 0;                   //return 0 if not
            }
            // (*NEW*)
            // Returns the contents of the head node
            // (The node head_ is pointing to)
            // Returns 0 if the list is empty
        }
        
        int SLList::GetTail() const
        {
            if (tail_ != NULL)              //check for contents
            {
                return tail_->contents();   //get them is available
            }
            else
            {
                return 0;                   //return 0 if not
            }
            // (*NEW*)
            // Returns the contents of the tail node
            // (The node tail_ is pointing to)
            // Returns 0 if the list is empty
        }
       void SLList::Clear()
        {
            while (head_ != NULL)           //checks for head contents in a loop-continues until list is empty
            {
                RemoveHead();               //removes head only if head exists
            }    
            tail_ = NULL;                   //handles tail
            // (*MODIFY*)
            //clears the entire contents of the list,
            //  freeing all memory associated with all nodes
            //  (*NEW*) - sets tail_ to NULL
        }
            
        unsigned int SLList::size() const
        {
            return size_;                   //returns size
        }
            //accessor for size_
        
        string SLList::ToString() const
        {
             
            stringstream list;
            //create stringstream variable list
            if (head_ == NULL)  
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
            }   
                                                 //loop exits when temp is null                                
                return list.str();               //return contents of list
                                                //returns a string representation of the contents
                                                //of all nodes in the list, in the format
                                                //NUM1, NUM2, ..., LASTNUM
                                                //returns the empty string on an empty list (i.e. returns "")
        }    