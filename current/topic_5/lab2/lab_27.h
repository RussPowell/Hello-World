/*
 * Name        : lab_27.h
 * Author      : Luke Sathrum
 * Description : Header File for Lab #27. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <algorithm>  // for sort
#include <cstddef>  // for NULL
#include <iostream>  // for operator<<
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::ostream;
using std::vector;
using std::stringstream;
using std::sort;

struct Item {
  Item(string name = "noname", unsigned int value = 0,
       unsigned int quantity = 0)
      : name_(name),
        value_(value),
        quantity_(quantity) {
  }

  friend ostream& operator<<(ostream& outs, const Item& src) {
    outs << src.name_;
    return outs;
  }

  string name_;
  unsigned int value_;
  unsigned int quantity_;
};

class TreasureChest {
 public:
  void AddItem(const Item& item_to_add);
  void InsertItem(const Item& item_to_add, unsigned int position);
  const Item* GetItem(unsigned int position) const;
  Item RemoveItem(unsigned int position);
  void Clear();
  bool Empty() const;
  unsigned int GetSize() const;
  void SortByName();
  void SortByValue();
  void SortByQuantity();
  friend ostream& operator<<(ostream& outs, const TreasureChest& src);
  string ToString();

 private:
  vector<Item> chest_;
};
  bool CompareItemsByName(const Item& lsrc, const Item& rsrc);
  bool CompareItemsByValue(const Item& lsrc, const Item& rsrc);
  bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc);

#endif /* TREASURE_CHEST_H_ */
