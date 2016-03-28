/*
 * Name        : food_item.h
 * Author      : Russell Powell
 * Description : Utilizing inheritance
 */
 
#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

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

//Filenames: food_item.h
//DERIVED Class Name: FoodItem (base Item)
class FoodItem : public Item
{
    public:
            //Public Members:
            //Constructor
        FoodItem();
        FoodItem(string, unsigned int, unsigned int, 
                    string, double);
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
        void set_calories(unsigned int calories);
        void set_unit_of_measure(string unit_of_measure);
        void set_units(double units);
        
        //--use the naming scheme we have been using all semester
        unsigned int calories() const;
        string unit_of_measure() const;
        double units() const;
        
        string ToString();
            //--returns a string containing name_, value_, units_, unit_of_measure_, and calories_
            //(uses Item::ToString in its implementation)
            //units_ formatted to exactly two decimal places
            //Format -- name_, $value_, units_ unit_of_measure_, calories_ calories
            //EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
    private:
            //Private Members:
        unsigned int calories_;
            //--holds a calorie count
        string unit_of_measure_;
            //--holds the unit of measure (such as "ounces")
        double units_;
            //--holds a count of how many units we have
            
};
#endif