/*
 * Name        : item.cpp
 * Author      : Russell Powell
 * Description : Utilizing inheritance
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
#include "item.h"

Item::Item()
{
  name_ = "item";
  value_ = 0;
} 
Item::Item(string name, unsigned int value)
{
    name_ = name;
    value_ = value;
}
  //two parameters, one for each private member variable
  //defaults name_ to "item"
  //defaults value_ to 0
  //Destructor
  /*
Item::~Item()
{
    //does nothing
}*/
  //does nothing
  //must be virtual (add virtual keyword before the destructor)
  //Accessors and Mutators for the 2 private varaibles
void Item::set_name(string name)
{
    name_ = name;
}
void Item::set_value(unsigned value)
{
    value_ = value;
}

string Item::name() const
{
    return name_;
}
unsigned int Item::value() const
{
    return value_;
}
//use the naming scheme we have been using all semester

string Item::ToString() const
{
 stringstream ss;
 ss.str();
 ss << name_ << ", $" << value_;
 return ss.str();
}
 
//returns a string containing name_ and value_










