/*
 * Name        : DLList.cpp
 * Author      : Russell Powell
 * Description : Define class DLList.cpp
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : 
 */        
 #include "DLList.h"       
        DLList::DLList ()
        {
            NodeCount_ = 0;
            head_ = NULL;   // initialize count to zero, head and tail to NULL
            tail_ = NULL;
        }
        
        
        DLList::~DLList()
        {
            clear();        // call clear function
        }
        
        unsigned int getSize ()
        {
            return NodeCount_;   // return count
        }
        
        void DLList::pushFront (int newContents)
        {
            DLNode* new_node = new DLNode(newContents); //create new node
            new_node->next_node(head_);           //points new_node at head's next node
            head_ = new_node;
            head_ ->previous_node(tail_);//point head at new_node
            NodeCount_++;                        //increment size
            if (head_->next_node() == NULL)
            {
                tail_ = new_node;
            }// create new DLNode with newContents and attach at head   
        }
        
        void DLList::pushBack (int newContents)
        {
            //create new DLNode with newContents and attach at tail
            DLNode* new_node = new DLNode(newContents);
            if (tail_ == NULL)
            {
                tail_ = new_node;
                head_ = new_node;
                tail_->set_next_node(head_);
                head_->set_previous_node(tail_);
                NodeCount_++;
            }
            else
            {
                //create new node;
                new_node->set_previous_node(tail_);
                           //points new_node at head's next node
                tail_ = new_node;                         //point head at new_node
                tail_->set_next_node(head_);
                NodeCount_++;
            }
        }
        
        void DLList::insert (int newContents)
        {
            //create new DLNode with newContents and insert in ascending (based on newContents) order
            DLNode* temp = head_                                        //create test node temp
            DLNode* assist;                                             //create a trailing node
            if ( temp == NULL)
            {
                InsertHead(newContents);                                   //test for empty head-insert if NULL
            }
            else if (newContents <= temp->contents())  //originally used an 'or' symbol and combined these test-got a seg fault so they are seperate
            {
                InsertHead(newContents);                                   //test against size of existing head-insert if appropriate
            }
            else if (newContents >= tail_->contents())                     
            {
                InsertTail(newContents);                                   //test against tail size-add to end if appropriate
            }
            else
            {
                while (temp->contents() <= newContents  )                  //loop to test against each node
                {
                    assist = temp;                                      //cannot go backwards-used assist to trail temp through the loop
                    temp = temp->next_node();
                }
                DLNode* toAdd = new DLNode(newContents);                   //assign contents to new node
                toAdd->set_next_node(temp);                             //point new node to temp(this is where we stop in the loop)
                assist->set_next_node(toAdd);                           //point assist at the new node setting the new node into the list
                NodeCount_++;                                                //increase size
            }
             
             temp = NULL;                                               //clean up
             delete temp;
            
        }
        
        int DLList::getFront () const
        {
            //return the value of the contents of the head node
            //throw an exception (throw "LIST EMPTY") if the list is empty
            if (head_ != NULL)              //check for contents
            {
                return head_->contents();                                       //get them if available
            }
            else
            {                               
                throw "List Empty";                   
                return 0 ;
            }
        }
        
        int DLList::getBack () const;     
        {
            //return the value of the contents of the tail node
            //throw an exception (throw "LIST EMPTY") if the list is empty
            if (tail_ != NULL)
            {
                return tail_->contents();
            }
            else
            {
                throw "List Empty";
            }
        }
        
        bool DLList::get (int target) const
        {                 
            DLNode* toFind = new DLNode(target);
            DLNode* temp = head_;                                               //new pointers, yay
            if (head_ == NULL)
            {
                return false;                                                   //test against empty head, return false if empty
            }
            
            else if (head_->contents() == contents)
            {                                                                   //test against contents of an existing head 
                return true;                                                    //return true
            }
            
            else if(tail_->contents() == contents)
            {
                return true;                                                    //test against tail return true if match
            }
            
            else
            {
                while(temp->next_node() != tail_)                               //tested tail, so loop goes to just before tail
                {
                    temp = temp->next_node();
                    if (temp->contents() == contents )                          //when a match is made
                    {
                        return true;
                    }
                    else if (temp->next_node() == tail_)                        //failing all other cases, the test did not match any contents
                    {
                        return false;                                           //so, return falsee
                    }
                }    
            }
        }
        void DLList::popFront ()
        {
            //remove current head node; do nothing if list is empty
            if (head_ != NULL)
            {
                 
                DLNode* temp;              //create temporary node
                temp = head_;              //point temp at head
                head_ = temp->next_node();
                head_->set_previous_node(tail_);//
                delete temp;               //delete contents of temp(formerly head)
                temp = NULL;               //assign NULL to temp
                NodeCount_--;                   //decrement size
                if (head_ == 0)
                {
                    tail_ = NULL;
                }
               
            }
        }
        void DLList::popBack ()                                 //remove current tail node; do nothing if list is empty
        {
            if (head_ != NULL)
            //checks if the list is null
            {
                if(head_ -> next_node() == NULL)
                //checks if head is the only node
                {
                    popFront();
                }
                
                else
                {
                    DLNode *temp = NULL;
                    //creates temp node and makes it equal to NULL
                    DLNode *iterator = head_;
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
                    tail_->set_previous_node(iterator);
                    tail_->set_next_node(head_);
                    //tail_ points at temp node
                    delete iterator;
                    //iterator node is deleted
                    iterator = NULL;
                    //iterator points at null
                    NodeCount_--;
                    //the size of the list decreases
                }
            }
        }
        bool DLList::removeFirst (int target)
        {
            //remove the first instance of a DLNode containing target; do nothing if target is not found
            DLNode* toDelete = new DLNode(target);
            DLNode* temp = head_;                                               //new pointers, yay
            DLNode* t;
            
            if (head_ == NULL)
            {
                return false;                                                   //test against empty head, return false if empty
            }
            
            else if (head_->contents() == target)
            {
                popFront();                                                   //test against contents of an existing head, remove if 
                return true;                                                    //exists and return true
            
            }
            
            else
            {
                while(temp->next_node() != tail_)                               //tested tail, so loop goes to just before tail
                {
                    t = temp;                                                   //trailer for temp-makes removal easy
                    temp = temp->next_node();
                    if (temp->contents() == target )                          //when a match is made
                    {
                        toDelete = temp;                                        //assign the test node to temp
                        temp = temp->next_node();                               //assign temp to next node
                        t-> set_next_node(temp);                                //assign t (which was trailing temp) to point at temp
                        temp = NULL;                                       
                        delete toDelete;
                        toDelete = NULL;                                        //clean up pointers
                        NodeCount_--;                                                //decrement size and return true
                        return true;
                    }
                    else if (temp->next_node() == tail_)                        //failing all other cases, the test did not match any contents
                    {
                        if(tail_->contents() == target)
                        {
                            popBack();                                                   //test against tail
                            return true;                                                    //remove and return true if match
                        }
                        else
                        {
                            return false;                                           //so, return falsee
                        }
                    }
                }    
            }
            
        }
        
        bool DLList::removeAll (int target) //remove all instances of DLNode containing target; do nothing if target is not found
        {
        DLNode* toDelete = new DLNode(target);
        DLNode* temp = head_;                                               //new pointers, yay
        temp->set_previous_node(head_);
        
        if (head_ == NULL)
        {
            return false;                                                   //test against empty head, return false if empty
        }
        
        else if (head_->contents() == target)
        {
            while (head_->contents() == target)
            {
            popFront();                                                   //test against contents of an existing head, remove if 
            }                                                               // continue removing head while contents match
        }
        
        else if(tail_->contents() == target)
        {
            while(tail_->contents() == target)
            {                                                                //test against tail
            popBack();                                                    //remove 
            }
        }
        
        else
        {
            while(temp->next_node() != tail_)                               //tested tail, so loop goes to just before tail
            {
                temp->set_previous_node(temp);                                                   //trailer for temp-makes removal easy
                temp = temp->next_node();
                if (temp->contents() == target )                          //when a match is made
                {
                    toDelete = temp;
                    temp->set_previous_node(temp)//assign the test node to temp
                    temp = temp->next_node();                               //assign temp to next node
                    delete todelete;
                    todelete = NULL;
                    size_--;                                                //decrement size and return true
                    
                }
                else if (temp->next_node() == tail_)                        //failing all other cases, the test did not match any contents
                {
                    return false;                                           //so, return falsee
                }
            }    
        }
            
        void DLList::clear ()                                  //clear all nodes from list, reset count to zero, set head and tail to NULL
        {
            while (head_ != NULL)           //checks for head contents in a loop-continues until list is empty
            {
                popFront();               //removes head only if head exists
            }    
            tail_ = NULL;                   //handles tail
            // (*MODIFY*)
            //clears the entire contents of the list,
            //  freeing all memory associated with all nodes
            //  (*NEW*) - sets tail_ to NULL
        }
        
        ostream& DLList::operator<< (ostream& out, const DLList& src)
        {
             
            stringstream list;
            //create stringstream variable list
            if (head_ == NULL)  
            {
                return "";                  //if size is 0, return and empty string   
            }
            DLNode* temp = head_;
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
            
                                                        //display the contents of each node in the list, formatted per the program specification ("NUM1,NUM2,NUM3,...,NUMX"), to the output stream out
        }