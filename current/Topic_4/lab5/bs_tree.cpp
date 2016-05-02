/*
 * Name        : BST_node.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *                https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a tree
 */
 #include "BST_node.h"
 #include "bs_tree.h"
 
 
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
        size_ ++;                                   //increase size
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
bool BSTree::Remove(int contents, BSTNode*& tempRoot){
    if(tempRoot == NULL)
    { 
        return false;
    }
    if (tempRoot->contents() == contents)//Base Node
    {
        BSTNode* hold = new BSTNode(contents);

        FindMin(tempRoot->right_child());
        hold-> contents() = tempRoot->contents();
        hold = NULL;
        delete hold;
        tempRoot = NULL;
        delete tempRoot;
        size_--;
        
        
        return true;
    }
    else if (tempRoot->contents() > contents)
    {
        if (tempRoot->right_child() != NULL)
        {
            return Remove(contents, tempRoot->right_child());
        }
        else 
        {
            return false;
        }
    }
    else
    {
        if (tempRoot->left_child() != NULL)
        {
            return Remove(contents, tempRoot->left_child());
        }
        else
        {
            return false;
        }
    }
    
     
}
    
int BSTree::FindMin(BSTNode* find) const{
       if (find == NULL)
       {
           return 0;
       }
       if (find->left_child() != NULL)
       {
           return FindMin(find->left_child());
       }
       else if (find->right_child() != NULL)
       {
           return FindMin(find->right_child());
       }
       else
       {
           return Remove(find->contents(),find);
       }
}

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
        
        
        
        