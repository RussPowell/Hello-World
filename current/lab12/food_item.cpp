/*
 * Name        : food_item.cpp
 * Author      : Russell Powell
 * Description : Utilizing inheritance
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */

#include "food_item.h"

FoodItem::FoodItem() : Item("fooditem",0)
{
//set_name("fooditem"); 
//set_value(0); 
calories_ = 0;
unit_of_measure_ = "nounits"; 
units_ = 0;
}

FoodItem::FoodItem(string name, unsigned int value,unsigned int calories, string unit_of_measure, double units)
        : Item(name, value)
{
calories_ = calories;
unit_of_measure_ = unit_of_measure; 
units_ = units;
}
        //--five parameters, one for each private member variable and two for the base class
        //--defaults name_ to "fooditem"
        //--defaults value_ to 0
        //--defaults calories_ to 0
        //--defaults unit_of_measure_ to "nounits"
        //--defaults units_ to 0
//Destructor
//virtual ~FoodItem();
//--does nothing
//--must be virtual (add virtual keyword before the destructor)
//Accessors and Mutators for the 3 private varaibles
void FoodItem::set_calories(unsigned int calories)
{
    calories_ = calories;
}
void FoodItem::set_unit_of_measure(string unit_of_measure)
{
    unit_of_measure_ = unit_of_measure;
}
void FoodItem::set_units(double units)
{
    units_ = units;
}
//--use the naming scheme we have been using all semester
unsigned int FoodItem::calories() const
{
    return calories_;
}
string FoodItem::unit_of_measure() const
{
    return unit_of_measure_;
}
double FoodItem::units() const
{
    return units_;
}
string FoodItem::ToString()
{
    stringstream ss;   //create variable-least imaginative name, apologies
ss.clear();        //clear the variable of existing flag pobably non necessary
ss.str();          //define ss as a string-can be initialized, but not required
ss.setf(ios::fixed);
ss.precision(2);
    ss << name() <<", $" << value() << ", " << units_ << " " << unit_of_measure_ <<  ", " << calories_ << " calories";
    return ss.str();
}
//--returns a string containing name_, value_, units_, unit_of_measure_, and calories_
//(uses Item::ToString in its implementation)
//units_ formatted to exactly two decimal places
//Format -- name_, $value_, units_ unit_of_measure_, calories_ calories
//EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories