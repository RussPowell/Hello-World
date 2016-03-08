/*
 * Name        : item.h
 * Author      : Russell Powell
 * Description : Manipulation and output of Money
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::endl;

class Item
{
    public:
    
       Item();    
    
       Item(const string, const unsigned int);
          //two parameters, one for each private member variable
          //defaults name_ to "item"
          //defaults value_ to 0
          //Destructor
       //virtual ~Item();
          //does nothing
          //must be virtual (add virtual keyword before the destructor)
          //Accessors and Mutators for the 2 private varaibles
       void set_name(string name);
       void set_value(unsigned value);
       
       string name() const;
       unsigned int value() const;
       //use the naming scheme we have been using all semester
       
       string ToString() const;
       //returns a string containing name_ and value_
       //Format -- 
       //string name_;
       //unsigned int value_;
       
    private:
       string name_;
       //holds the name of the item
       unsigned int value_;
       //holds the value of the item
};
#endif