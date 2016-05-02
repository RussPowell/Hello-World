/*
 * Name        : BST_node.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a tree
 */

#include "bst_node.h"
#include "bs_tree.h"


BSTNode::BSTNode()
{
     left_child_ = NULL;
     right_child_ = NULL;
     contents_ = 0;
}

BSTNode::BSTNode(int newContents)
{
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = newContents;
}

BSTNode::~BSTNode()
{
    left_child_ = NULL;
    right_child_ = NULL;
}

void BSTNode::set_contents(int newContents)
{
    contents_ = newContents;
}

int BSTNode::contents() const
{
    return contents_;
}

int& BSTNode::contents()
{
    return contents_;
}


void BSTNode::set_left_child(BSTNode* newLeft)
{
    left_child_ = newLeft;
}

void BSTNode::set_right_child(BSTNode* newRight)
{
    right_child_ = newRight;
}

BSTNode* BSTNode::left_child() const
{
    return left_child_;
}

BSTNode*& BSTNode::left_child()
{
    return left_child_;
}

BSTNode* BSTNode::right_child() const
{
    return right_child_;
}

BSTNode*& BSTNode::right_child()
{
    return right_child_;
}