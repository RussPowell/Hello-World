/*
 * Name        : bs_treet.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a tree
 */
#ifndef BS_TREET_H
#define BS_TREET_H
 
#include "bs_nodet.h"


template<class TT>
class BSTreeT
{
    public:
        BSTreeT();
        
         ~BSTreeT();
        
        bool Insert(TT contents);
        
        bool Exists(TT incontents);
        
        bool Remove(TT contents);
        
        TT FindWord();
        
        void Clear();
        
        unsigned int GetSize() const;    
        
        string ToStringForwards();
        
        string ToStringBackwards();
        
    private:
        bool Insert(TT contents, BSTNodeT<TT>*& newRoot);
        
        void Clear(BSTNodeT<TT>*& newRoot);
        
        bool Exists(BSTNodeT<TT>*& tempRoot, TT contents);
        
        string ToStringForwards(BSTNodeT<TT>*& output);
        
        string ToStringBackwards(BSTNodeT<TT>*& output);
        
        bool Remove(TT contents, BSTNodeT<TT>*& newRoot);
        
        TT FindWord(BSTNodeT<TT> *node ) const;
        
        BSTNodeT<TT> *root_;
        
        unsigned int size_;
};



template<class TT>
BSTreeT<TT>::BSTreeT()
{
    root_ = NULL;
    size_ = 0;
}

template<class TT>
BSTreeT<TT>::~BSTreeT()
{
    Clear();
}

template<class TT>
bool BSTreeT<TT>::Insert(TT contents)
{
    return Insert(contents, root_);
}

template<class TT>
bool BSTreeT<TT>::Remove(TT contents)
{
    return Remove(contents, root_);   
}

template<class TT>
TT BSTreeT<TT>::FindWord()
{
    if (root_ == NULL)
    {
        return 0;
    }
    else
    {
        FindWord(root_);
        
    }
}

template<class TT>
void BSTreeT<TT>::Clear()
{
    Clear(root_);
}

template<class TT>
unsigned int BSTreeT<TT>::GetSize() const
{
    return size_;
}

template<class TT>
bool BSTreeT<TT>::Exists(TT contents)
{
    return Exists(root_, contents);
}

template<class TT>
string BSTreeT<TT>::ToStringForwards()
{
    return ToStringForwards(root_);
}

template<class TT>
string BSTreeT<TT>::ToStringBackwards()
{
    return ToStringBackwards(root_);
}

template<class TT>
bool BSTreeT<TT>::Insert(TT inContents, BSTNodeT<TT>*& newRoot)
{   
    if(newRoot == NULL)                             //check for empty list->new root if null
    {
        BSTNodeT<TT>* temp_ = new BSTNodeT<TT>(inContents);
        newRoot=temp_;
        size_ ++;                                    //increase size
        return true;     
 
    }
    
    if(Exists(inContents) == true)           // check for duplicates->teminate if found
    {
        return false;
    }
    
    else if(inContents < newRoot->GetContents())       //check for new contents less than root contents
    {                                                   //moving left if smaller
         if(newRoot->GetLeft() != NULL)          //check for left child->calls Insert and moves to left
        {                                               //child for next call
            return Insert(inContents, newRoot->GetLeft());   
        }                                              
                                                        
        if(newRoot->GetLeft() == NULL)           
        {
            BSTNodeT<TT>* temp_ = new BSTNodeT<TT>(inContents);   //place new node in null location
            newRoot->SetLeft(temp_);             //this will create a node and left/right pointers
            size_ ++;                                   //which will point to null
            return true;
        }
    }
    
    else if (inContents > newRoot->GetContents())                                        //if new contents are larger,
    {
        if(newRoot->GetRight() != NULL)
        {
            return Insert(inContents, newRoot->GetRight());
        }//check for null on right->if null 
        else if (newRoot->GetRight() == NULL)
        {                                                  
            //child->place new node and new contents
            BSTNodeT<TT>* temp_ = new BSTNodeT<TT>(inContents);       //in right child
            newRoot->SetRight(temp_);
            size_ ++;
            return true;
        }
        else                                    //or
        {
             return Insert(inContents, newRoot->GetRight());  //call insert, moving root to the right
        }
    }
}

template<class TT>
void BSTreeT<TT>::Clear(BSTNodeT<TT>*& root)
{
    //root = root_;
    if (root_ != NULL)                              //base case, root is null
    {                                               
        if(root->GetLeft() != NULL)              //if the left node is not null
        {                                           
            return Clear(root->GetLeft());       //call clear and move left
        }                                           
        if(root->GetRight() != NULL)             //if the left is null, check the right
        {
            return Clear(root->GetRight());      //call clear and move right
        }
        delete root;                                //when both left and right are null, delete root contents
        root = NULL;                                //point to null
        size_--;                                    //decrement size
        return Clear(root_);                        //call the clear(root_)
    }
}

template<class TT>
bool BSTreeT<TT>::Exists(BSTNodeT<TT>*& tempRoot, TT contents)
{
    if (tempRoot != NULL)
    {
        if (tempRoot->GetContents() != contents)
        {
            if (contents < tempRoot -> GetContents() )                  //checking contents for inequalities
            {                                                       //working through the list till it finds
            Exists(tempRoot->GetLeft(), contents);           //the target, or finishes the list
            }
            else if (contents > tempRoot -> GetContents() )
            {
            Exists(tempRoot->GetRight(), contents);
            }
            return false;
        }
        else
        {    
        return true;
        }
    }
    else
    {
        return false;
    }
}

template<class TT>
string BSTreeT<TT>::ToStringForwards(BSTNodeT<TT>*& output)
{
    stringstream ss;
    
    if (output != NULL)
    {
        if(output->GetLeft() != NULL)
        {
            ss << ToStringForwards(output->GetLeft()) << ", ";
        }
        ss <<  output->GetContents() ;                //each check captures contents and calls the 
                                                            //the function on the next child
        if(output->GetRight() != NULL)                      //This will output the entire node in order
        {                                                   //small to large
            ss << ", "<< ToStringForwards(output->GetRight());     //Below, commented out, is a function that  
        }                                                   //will do the exact same thing, in reverse
        return ss.str();                                    //large to small
    }
    else
    {    
    return "";
    }
}

template<class TT>
string BSTreeT<TT>::ToStringBackwards(BSTNodeT<TT>*& output)
{
    stringstream ss;
    
    if (output != NULL)
    {
        
        if(output->GetRight() != NULL)
        {
            ss  << ToStringBackwards(output->GetRight())<< ", ";
        }
        ss << output->GetContents()  ;        //each check captures contents and calls the 
                                                //the function on the next child
        if(output->GetLeft() != NULL)       //This will output the entire node in order
        {                                       //small to large
            ss << ", "<< ToStringBackwards(output->GetLeft()) ;   //Below, commented out, is a function that  
        }                                           //will do the exact same thing, in reverse
        return ss.str();                            //large to small
    }
    else
    {    
    return "";
    }
}

template<class TT>
TT BSTreeT<TT>::FindWord(BSTNodeT<TT> *word) const
{
     
      if(word->GetLeft() != NULL)
      {
      return FindWord(word->GetLeft());          //follows the string of nodes left until it reaches the smallest large node
      }
      else //does not work for one child, left. will return the smallest small value available
      {
          return word->GetContents();                 //returns it via the contents function
      }
}

template<class TT>
bool BSTreeT<TT>::Remove(TT contents, BSTNodeT<TT>*& tempRoot)
{
    if(tempRoot == NULL)                                    //check for empty list
    { 
        return false;                                       //does nothing
    }
    else if (contents < tempRoot -> GetContents() )                  //checking contents for inequalities
    {                                                       //working through the list till it finds
        Remove(contents, tempRoot->GetLeft());           //the target, or finishes the list
    }
    else if (contents > tempRoot -> GetContents() )
    {
        Remove(contents, tempRoot->GetRight());
    }
    else
    { 
        if(tempRoot->GetLeft() == NULL && tempRoot->GetRight() == NULL)
        {
            delete tempRoot;
            tempRoot = NULL;
            size_--;                        //This will handle any node with no children, including root_ 
            return true;
        }
        else if((tempRoot -> GetLeft() != NULL && tempRoot -> GetRight() != NULL) || (tempRoot->GetLeft() == NULL && tempRoot->GetRight() != NULL))
        {
            TT toReplace = FindWord(tempRoot->GetRight());       //create and fill a variable to contain the result
            tempRoot -> SetContents(toReplace);                    //of FindMin
            return Remove(toReplace, tempRoot->GetRight());      //use the new variable in the subsequent call of Remove
        }
        else if (tempRoot->GetLeft() != NULL && tempRoot->GetRight() == NULL)
        {
            BSTNodeT<TT>* temp = tempRoot;
            tempRoot = tempRoot->GetLeft();
            delete temp;                                //point root at tempRoots left child
            temp = NULL;
            size_--;                                    //decrement size
            return true;                                    //return true
        }
        else
        {
            TT toReplace = FindWord(tempRoot->GetLeft()); 
            tempRoot -> SetContents(toReplace);
            return Remove(toReplace, tempRoot->GetLeft());
        }
    }
}




#endif
  
      