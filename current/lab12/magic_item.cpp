 /*
 * Name        : magic_item.cpp
 * Author      : Russell Powell
 * Description : Utilizing inheritance
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */

#include "magic_item.h"

MagicItem::MagicItem() : Item("magicitem", 0)
{
    description_ = "no description";
    mana_required_ = 0;
}
    MagicItem::MagicItem(string name, unsigned int value, string description, unsigned int mana_required)
            : Item(name, value)
            {
                description_ = description;
                mana_required_ = mana_required;
            }
            //--four parameters, one for each private member variable and two for the base class
            //--defaults name_ to "magicitem"
            //--defaults value_ to 0
            //--defaults description_ to "no description"
            //--defaults mana_required_ to 0
            //Destructor
            //--does nothing
            //virtual ~MagicItem{};
            //--must be virtual (add virtual keyword before the destructor)
        void MagicItem::set_description(string description)
        {
            description_ = description;
        }
        void MagicItem::set_mana_required(unsigned int mana_required)
        {
            mana_required_ = mana_required;
        }
        
        string MagicItem::description() const
        {
            return description_;
        }
        unsigned int MagicItem::mana_required() const
        {
            return mana_required_;
        }
            //Accessors and Mutators for the 2 private varaibles
            //--use the naming scheme we have been using all semester
        string MagicItem::ToString()
        {
    stringstream ss;   //create variable-least imaginative name, apologies
ss.clear();        //clear the variable of existing flag pobably non necessary
ss.str();          //define ss as a string-can be initialized, but not required
ss.setf(ios::fixed);
ss.precision(2);
    ss << name() <<", $" << value() << ", " << description_ << ", requires " << mana_required_ <<  " mana";
    return ss.str();
}
            //--returns a string containing name_, value_, desciption_, and mana_required_
            //(uses Item::ToString in its implementation)
            //Format -- name_, $value_, description_, requires mana_required_ mana
            //EXAMPLE -- hat, $10, made of felt, requires 2 mana
          