/*
 * Name        : BST_node.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *                https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a tree
 */ 
 #include "bst_node.h"
 #include "bs_tree.h"
 
//public           everything between here and 'private' below is commented in the .h file 
BSTree::BSTree()
{
    root_ = NULL;
    size_ = 0;
}

BSTree::~BSTree()
{
    Clear();
}

bool BSTree::Insert(int contents)
{
    return Insert (contents, root_);
}

bool BSTree::Remove(int contents){
    return Remove(contents, root_);
}

int BSTree::FindMin(){
    if (root_ == NULL){
        return 0;
    }
    else{
        return FindMin(root_);
    }
}
    
void BSTree::Clear()
{
    Clear(root_);
}

unsigned int BSTree::size() const
{
    return size_;
}

string BSTree::InOrder()
{
    return InOrder(root_);
}
//private
bool BSTree::Insert(int inContents, BSTNode*& newRoot)
{
    if(newRoot == NULL)                             //check for empty list->new root if null
    {
        BSTNode* temp_ = new BSTNode(inContents);
        newRoot=temp_;
        size_ ++;                                    //increase size
        return true;     
 
    }
    
    if(newRoot->contents() == inContents)           // check for duplicates->teminate if found
    {
        return false;
    }
    
    else if(inContents < newRoot->contents())       //check for new contents less than root contents
    {                                                   //moving left if smaller
         if(newRoot->left_child() != NULL)          //check for left child->calls Insert and moves to left
        {                                               //child for next call
            return Insert(inContents, newRoot->left_child());   
        }                                              
                                                        
        if(newRoot->left_child() == NULL)           
        {
            BSTNode* temp_ = new BSTNode(inContents);   //place new node in null location
            newRoot->set_left_child(temp_);             //this will create a node and left/right pointers
            size_ ++;                                   //which will point to null
            return true;
        }
    }
    
    else                                        //if new contents are larger,
    {
        if(newRoot->right_child() == NULL)                  //check for null on right->if null 
        {                                                   //child->place new node and new contents
            BSTNode* temp_ = new BSTNode(inContents);       //in right child
            newRoot->set_right_child(temp_);
            size_ ++;
            return true;
        }
        else                                    //or
        {
            return Insert(inContents, newRoot->right_child());  //call insert, moving root to the right
        }
    }
}

void BSTree::Clear(BSTNode*& root)
{
    //root = root_;
    if (root_ != NULL)                              //base case, root is null
    {                                               
        if(root->left_child() != NULL)              //if the left node is not null
        {                                           
            return Clear(root->left_child());       //call clear and move left
        }                                           
        if(root->right_child() != NULL)             //if the left is null, check the right
        {
            return Clear(root->right_child());      //call clear and move right
        }
        delete root;                                //when both left and right are null, delete root contents
        root = NULL;                                //point to null
        size_--;                                    //decrement size
        return Clear(root_);                        //call the clear(root_)
    }//this function will continue to run until all nodes are cleared including THE root
    
} 

string BSTree::InOrder(BSTNode*& output)
{
    stringstream ss;
    if (output != NULL)
    {
        if(output->left_child() != NULL)
        {
            ss << InOrder(output->left_child());
        }
        ss << output->contents() << " ";        //each check captures contents and calls the 
                                                //the function on the next child
        if(output->right_child() != NULL)       //This will output the entire node in order
        {                                       //small to large
            ss << InOrder(output->right_child());   //Below, commented out, is a function that  
        }                                           //will do the exact same thing, in reverse
        return ss.str();                            //large to small
    }
    else
    {    
    return "";
    }
}
                
    
    
    
                
                                //Recieves contents and root_
bool BSTree::Remove(int contents, BSTNode*& tempRoot)
{
    
    if(tempRoot == NULL)                                    //check for empty list
    { 
        return false;                                       //does nothing
    }
    if (tempRoot -> contents() > contents)                  //checking contents for inequalities
    {                                                       //working through the list till it finds
        Remove(contents, tempRoot->left_child());           //the target, or finishes the list
    }
    else if (tempRoot -> contents() < contents)
    {
        Remove(contents, tempRoot->right_child());
    }
    else if (tempRoot -> contents() == contents)                                         //Base Node
    { 
        //no children
        if(tempRoot->left_child() == NULL && tempRoot->right_child() == NULL)
        {
            delete tempRoot;
            tempRoot = NULL;
            size_--;                        //This will handle any node with no children, including root_ 
            return true;
        }
        //two children
        else if (tempRoot -> left_child() != NULL && tempRoot -> right_child() != NULL)
        {
            int toReplace = FindMin(tempRoot->right_child());       //create and fill a variable to contain the result
            tempRoot -> set_contents(toReplace);                    //of FindMin
            return Remove(toReplace, tempRoot->right_child());      //use the new variable in the subsequent call of Remove
        }
        //one child, to the right
        else if(tempRoot->left_child() == NULL && tempRoot->right_child() != NULL)
        {   
             BSTNode* temp = tempRoot;
            tempRoot = tempRoot->right_child();
            delete temp;                                //point root at tempRoots left child
            temp = NULL;
            size_--;                                        //decrement size
            return true;
            // int toReplace = FindMin(tempRoot->right_child());   //enters Findmin at the rightchild node, findmin will track left from 
            // tempRoot -> set_contents(toReplace);                //there to find the smallest large contents and replace the deleted node
            // return Remove(toReplace, tempRoot -> right_child());//with those contents
        }
        //one child to the left
        else if (tempRoot->right_child() == NULL && tempRoot->left_child() != NULL)
        {
            BSTNode* temp = tempRoot;
            tempRoot = tempRoot->left_child();
            delete temp;                                //point root at tempRoots left child
            temp = NULL;
            
            size_--;                                        //decrement size
            return true;                                    //return true
        }//this feels like a lot is left leaking. however, everything I tried to do to avoid that resulted in 
    }    //a segfault or a sigabrt as well as multiple failed assertions
    else
    {
        return false;
    }
}
    
int BSTree::FindMin(BSTNode* find) const
{
     
       if(find->left_child() != NULL)
       {
      return FindMin(find->left_child());          //follows the string of nodes left until it reaches the smallest large node
       }
       else //does not work for one child, left. will return the smallest small value available
       {
           return find->contents();                 //returns it via the contents function
       }
}     
     
/*     
int BSTree::FindMax(BSTNode* find) const
{
     
       if(find->rightt_child() != NULL)
       {                                                    //this is unrequired code
       return FindMin(find->rightt_child());                //However in the event that the node to be replaced
       }                                                    //has one child on the left, this will search out the 
       else                                                 //largest small node available and use it to fill the void
       {                                                    //in the removed node
           return find->contents();
       }
}
*/




//also unnecessary, this will print 
//the contents in reverse order

/*
 if(output->right_child() != NULL)
        {
            ss << InOrder(output->right_child());
        }
        ss << output->contents() << " ";
        if(output->left_child() != NULL)
        {
            ss << InOrder(output->left_child());
        }
        return ss.str();
*/       
        
        
        
        