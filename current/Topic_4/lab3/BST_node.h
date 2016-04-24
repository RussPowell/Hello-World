/*
 * Author       :Russell Powell
 * title        :lab3.h
 * description  :Roots if Tree
 * Links        :https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */        
 
#ifndef LAB3_H
#define LAB3_H

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


class BSTNode
{
public:

BSTNode();
    //sets left_child_ to NULL
    //sets right_child_ to NULL
    //sets contents_ to 0

BSTNode(int contents);
    //has one int parameter for contents
    //sets left_child_ to NULL
    //sets right_child_ to NULL
    //sets contents_ to the value of the parameter

~BSTNode();
    //sets left_child_ to NULL
    //sets right_child_ to NULL

void set_contents(int);
    //mutator for contents_

int contents() const;

int& contents();
    //accessors for contents_

void set_left_child(BSTNode*);
    //mutator for left_child_
void set_right_child(BSTNode*);
    //mutator for right_child_

BSTNode* left_child() const;

BSTNode*& left_child();
    //accessors for left_child_

BSTNode* right_child() const;
BSTNode*& right_child();
    //accessors for right_child_

private:

    BSTNode* left_child_;
        //points to a left child
    BSTNode* right_child_;
        //points to a right child
    int contents_;
        //used to store the data contents of a BSTNode
};
#endif