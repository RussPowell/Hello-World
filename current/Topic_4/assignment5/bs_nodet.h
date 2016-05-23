/*
 * Name        : bs_nodet.h
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a template for use with a binary tree
 */
#ifndef BS_NODET_H
#define BS_NODET_H
 
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <istream>
using std::ifstream;
using std::ofstream;
using namespace std;

template<class T>
class BSTNodeT
{
    public:
    BSTNodeT(T newData = T());
                // overloaded constructor – NULLs out both pointers
                // assigns value to data
     void SetContents(T);
    
    T GetContents() const;
                // gets and sets as appropriate
    
    T& GetContents();
    //accessors for contents_       
    void SetLeft(BSTNodeT<T>*);
    //mutator for left_child_

    void SetRight(BSTNodeT<T>*);
    //mutator for right_child_

    BSTNodeT<T>* GetLeft() const;
    BSTNodeT<T>*& GetLeft();
    //accessors for left_child_

    BSTNodeT<T>* GetRight() const;
    BSTNodeT<T>*& GetRight();
    //accessors for right_child_

    protected:
    T data_;
                // - a template data type
    BSTNodeT<T>* left_child_;
                // – a pointer to another search tree node
    BSTNodeT<T>* right_child_;
                //  – a pointer to another search tree node
};

template<class T>
BSTNodeT<T>::BSTNodeT(T newData )
{
    data_ = newData;
    left_child_ = NULL;
    right_child_ = NULL;
}
 template<class T>
    void BSTNodeT<T>::SetContents(T newData)
    {
        data_ = newData;
    }
    
    template<class T>
    T BSTNodeT<T>::GetContents() const
    {
        return data_;
    }
    
    template<class T>
    T& BSTNodeT<T>::GetContents()
    {
        return data_;
    }
    template<class T>
    void BSTNodeT<T>::SetLeft(BSTNodeT<T>* newLeft)
    {
        left_child_ = newLeft;
    }
    
    template<class T>
    void BSTNodeT<T>::SetRight(BSTNodeT<T>* newRight)
    {
        right_child_ = newRight;
    }
    
    template<class T>
    BSTNodeT<T>* BSTNodeT<T>::GetLeft() const
    {
        return left_child_;
    }
    
    template<class T>
    BSTNodeT<T>*& BSTNodeT<T>::GetLeft()
    {
        return left_child_;
    }
    
    template<class T>
    BSTNodeT<T>* BSTNodeT<T>::GetRight() const
    {
        return right_child_;
    }
    
    template<class T>
    BSTNodeT<T>*& BSTNodeT<T>::GetRight()
    {
        return right_child_;
    }
#endif
    
    