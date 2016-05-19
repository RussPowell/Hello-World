/*
 * Name        : lab_27.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Helpful     : Mike, Phillip, and Walter
 * Reference   : Cplusplus.com
 * Description : Using the STL
 */

#include "lab_27.h"

// CLASS (and regular) FUNCTION DEFINITIONS GO HERE

/*
  * Add an item to the end of the chest.
  * @param Item& item_to_add - The item to be added to the end of the chest
  */
  void TreasureChest::AddItem(const Item& item_to_add)
  {
  
      chest_.push_back(item_to_add);
  }

  /*
   * Insert an item at the specified zero-indexed position in the chest. If
   * position is not valid for the chest, add the item to the end of the chest.
   * Note this function inserts, not replaces.
   * @param Item& item_to_add - The item to be inserted into the chest
   * @param u-int position    - The zero-indexed position where the insertion is
   *                            to take place.
  */
  void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position)
  {
    if (position >= chest_.size())
    {
      chest_.push_back(item_to_add);
    }
    else
    {
      chest_.insert(chest_.begin()+position, item_to_add);
    }
  }


  /*
   * Get a pointer to an item at a specified zero-indexed position in the chest.
   * @param u-int position - The zero-indexed position of the item
   * @return const Item* - A pointer to the item if position is valid, else NULL
   */
  const Item* TreasureChest::GetItem(unsigned int position) const
  {
      if (!chest_.empty())
      {
        if (position >=chest_.size())
        {
          return NULL; // nothing at this position
        }
        else
        {
          return (&chest_[position]);
        }
      }
      else
      {
        return NULL;
      }
  }

  /*
   * Remove an item from the chest at a specified zero-indexed position.
   * @param u-int position - The zero-indexed position of the item
   * @return Item          - A copy of the Item removed from the chest
   * @throw string("ERROR: Remove at invalid position") if position is not valid
   */
  Item TreasureChest::RemoveItem(unsigned int position)
  {
    Item temp;
    if (position < chest_.size())
    {
      temp = chest_[position];
      
      chest_.erase(chest_.begin() + position);
      
      std::cout << temp ;
    }
    else
    {
      throw string ("ERROR: Remove at invalid position");
    }
  return temp;
  }

  /*
   * Clear the chest of all items.
   */
  void TreasureChest::Clear()
  {
    for (unsigned int i = 0; i < chest_.size(); i++)
    {
      chest_.clear();
    }
  }

  /*
   * Check to see if the chest is empty.
   * @return bool - True if the chest is empty, else false
   */
  bool TreasureChest::Empty() const
  {
    if (chest_.empty())
    {return true;}
    else
    {return false;}
  }
  /*
   * Get the size/number of items currently in the chest.
   * @return u-int - The current size of the chest
   */
  unsigned int TreasureChest::GetSize() const
  {
      return chest_.size();
  }

  /*
   * Sort the items in the chest by name, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByName()
  {
    sort (chest_.begin(), chest_.end(), CompareItemsByName);
  }

  /*
   * Sort the items in the chest by value, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByValue()
  {
    sort (chest_.begin(), chest_.end(), CompareItemsByValue);
  }

  /*
   * Sort the items in the chest by quantity, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByQuantity()
  {
    sort (chest_.begin(), chest_.end(), CompareItemsByQuantity);
  }

  /*
   * Place the names of the items in the chest on the specified stream,
   * formatted as ITEM_NAME, ITEM_NAME, ..., ITEM_NAME
   * Places "Chest Empty!" on the stream if the chest is empty
   */
  ostream& operator<<(ostream& outs, const TreasureChest& src)
  {
    if (!src.Empty())
    {
      for (unsigned int i = 0; i < src.GetSize(); i++)
      {
        if ( i == 0)
        {
        outs << *src.GetItem(i);
        }
        else 
        {
          outs << ", " << *src.GetItem(i);
        }
      }
      return outs;
    }
    else
    {
      outs << "Chest Empty!";
      return outs;
    }
    
}
  /*
   * Returns a string representation of what the overloaded << operator would
   * output. Remember: 'this' is a keyword that points to the current object
   * @uses Overloaded << Operator
   * @return string - A string in the format ITEM_NAME, ... or "Chest Empty!"
   */
  string TreasureChest::ToString()
  {
    stringstream output;
      output << *this;  
    return output.str();
  }

//  private:
//   vector<Item> chest_;
// };

/*
  * Compare two items by name.
  * @return true if lsrc.name_ < rsrc.name_, else false
  */
bool CompareItemsByName(const Item& lsrc, const Item& rsrc)
{
  if (lsrc.name_[0] < rsrc.name_[0])
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
  * Compare two items by value.
  * @return true if lsrc.value_ < rsrc.value_, else false
  */
bool CompareItemsByValue(const Item& lsrc, const Item& rsrc)
{
  if (lsrc.value_ < rsrc.value_)
  {return true;}
  else
  {return false;}
}

/*
  * Compare two items by quantity.
  * @return true if lsrc.quantity_ < rsrc.quantity_, else false
  */
bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc)
{
  if (lsrc.quantity_ < rsrc.quantity_)
  {return true;}
  else
  {return false;}
}
