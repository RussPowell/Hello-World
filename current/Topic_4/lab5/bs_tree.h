/*
 * Name        : BST_node.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a tree
 */
#ifndef BSTREE_H
#define BSTREE_F
 
#include "bst_node.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;
using std::ios_base;

class BSTree
{

    public:
        BSTree();
            //Default Constructor
            //sets root_ to NULL
            //sets size_ to 0
        
        ~BSTree();
            //Destructor
            //calls Clear()
        
        bool Insert(int newRoot);
            //calls private function Insert(int, root)
            
         bool Remove(int);
            //(*NEW*)
            //returns value returned by private function Remove(int, root)
        
        int FindMin();
            //(*NEW*)
            //if the tree is empty return 0
            //otherwise return the value returned by private function
            //FindMin(root)
        
        void Clear();
            //calls private function Clear(root)
        
        unsigned int size() const;
            //Accessor for size_
        
        string InOrder();
    
    private:
    
        bool Insert(int contents, BSTNode*& newRoot);
            //creates a new BSTNode, inserts it into the tree, and returns true
            //if the integer is already in the tree, does not insert, and returns false
        
        void Clear(BSTNode*& clears);
            //clears the entire contents of the tree,
            //freeing all memory associated with all nodes
        
        string InOrder(BSTNode*& output);
            //creates a string of the data in all nodes in the tree, in ascending order
            //separate by spaces (there should be a space after the last output value)
        
         bool Remove(int, BSTNode*&);
        //(*NEW*)
        //traverses the tree and removes the node containing the target
        //integer if present and returns true
        //return false if target integer is not in tree (or the tree is
        //empty)
    
        int FindMin(BSTNode*) const;
            //(*NEW*)
            //returns the value of the smallest node in the tree
            //helper function for private Remove()
        
        BSTNode* root_;
            //points to the root node of a binary search tree
        
        unsigned int size_;
            //holds the number of nodes in the tree
};
#endif