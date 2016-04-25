/*
 * Name        : lab_10.cpp
 * Author      : Russell Powell
 * Description : Manipulation and output of Money
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

/*
   * Overload of binary - operator. This is a friend function.
   * @param Money amount1 - The object to subtract from
   * @param Money amount2 - The object to be subtracted
   * @return Money - The result of the subtraction
   */
const Money operator -(const Money& amount1, const Money& amount2){
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // subtract all_cents2 from all_cents1
  // declare a new variable, dif_all_cents with the correct
  // operator, -
  int dif_all_cents = all_cents1 - all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(dif_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (dif_all_cents < 0) {
  final_dollars = -final_dollars;
  final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}
 
  /*
   * Overload of == operator. This is a friend function.
   * @param Money amount1 - The first object to compare
   * @param Money amount2 - The second object to compare
   * @return bool - True if the objects have the same values, otherwise false
   */
 //bool operator ==(const Money &amount1, const Money &amount2){
  bool operator ==(const Money &amount1, const Money &amount2)
  {
    return  
           ((amount1.dollars() == amount2.dollars()) &&
           (amount1.cents() == amount2.cents()));
  }
  
  /*
   * Overload of unary - operator. This is a friend function.
   * @param Money amount - The object to negate
   * @return Money - The result of the negation of the two member variables
   */
const Money operator -(const Money &amount)
{
    //Money(amount) = -Money(amount);
    //This came directly from the Savitch book, pg 346
    return Money(-amount.dollars(), -amount.cents());
    //Tried this, with no success 
    // amount = -amount;
    //return Money(amount);
    
}  
/*
   * Overload of << operator.
   * Outputs the money values to the output stream.
   * Should be in the form $x.xx
   * @uses setw()
   * @uses setfill()
   * @param ostream &out - The ostream object to output to
   * @param Money amount - The Money object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
   
// Achieved the goal, but did not use setw() or setfill()-realized my mistake at the end

ostream& operator <<(ostream &out, const Money &amount){
  const int absDollars = abs(amount.dollars());
  const int absCents = abs(amount.cents());
  //to handle amounts less than zero (negative dollar amounts).
  if (amount.dollars() < 0 || amount.cents() < 0){
      out << "$-";
  }
  else{
      out << "$";
  }
  //adds the absolute value of dollars to the stream
  out << absDollars;
  
  if (absCents >= 10)
  {
      //adds the absolute value of cents to stream, if it is 10 or more
      out << "." << absCents;
  }
  else
  {
      //adds a leading 0 and absoulte cents is absolute cents is less than 10
      out << "." << "0" << absCents;
  }
  return out;
}

