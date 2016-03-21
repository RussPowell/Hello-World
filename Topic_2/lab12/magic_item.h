/*
 * Name        : magic_item.h
 * Author      : Russell Powell
 * Description : Utilizing inheritance
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
 
#ifndef MAGIC_ITEM_H
#define MAGIC_ITEM_H

#include "item.h"
#include <iostream> 
#include <cstdlib>
#include <string>
#include <sstream>
using std::cout;
using std::string;
using std::stringstream;
using std::endl;
using std::ios;

//Filenames: magic_item.h/magic_item.cpp


class MagicItem : public Item
{
        //DERIVED Class Name: MagicItem (base Item)
    public:
            //Public Members:
            //Constructor
        MagicItem();
        MagicItem(string, unsigned int, string, unsigned int);
            //--four parameters, one for each private member variable and two for the base class
            //--defaults name_ to "magicitem"
            //--defaults value_ to 0
            //--defaults description_ to "no description"
            //--defaults mana_required_ to 0
            //Destructor
            //--does nothing
        //virtual ~MagicItem();
            //--must be virtual (add virtual keyword before the destructor)
        void set_description(string description);
        void set_mana_required(unsigned int mana_required);
        
        string description() const;
        unsigned int mana_required() const;
            //Accessors and Mutators for the 2 private varaibles
            //--use the naming scheme we have been using all semester
        string ToString();
            //--returns a string containing name_, value_, desciption_, and mana_required_
            //(uses Item::ToString in its implementation)
            //Format -- name_, $value_, description_, requires mana_required_ mana
            //EXAMPLE -- hat, $10, made of felt, requires 2 mana
            
    private:
            //Private Members:
        string description_;
            //--holds a description of the magic item
        unsigned int mana_required_;
            //--holds the amount of mana required to use the magic item
};
#endif