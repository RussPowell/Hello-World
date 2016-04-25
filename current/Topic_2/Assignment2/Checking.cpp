/*
 *Name        : checking.cpp
 *Author      : Russell Powell
 *Description : This is the implemtation for the 
 *              Checking subClass.
 *Links       : https://github.com/RussPowell/Hello-World.git
 *              https://hello-world-russpowell.c9users.io *
 *
 */
 
 #include "Checking.h"
//default constructor
Checking::Checking() : Accounts()
{
    fees_ = 3.00; 
}

//Overloaded constructor    
Checking::Checking(double balance, double deposit, double withdrawl)
    : Accounts(balance, deposit, withdrawl)
{

    fees_ = 3.00;  //fees are unique to Checking-can be transaction fees, or monthly account fees
}
double Checking::fees() const
{
    return fees_;
}

void Checking::set_fees(double fees)
{
    fees_ = fees;
}

string Checking::ToString() const
{
    stringstream ss;   //create variable-least imaginative name, apologies
        ss.clear();        //clear the variable of existing flag pobably non necessary
        ss.str();          //define ss as a string-can be initialized, but not required
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Beginning Balance:      " << setw(8) << balance_ 
         << "\nPlus Deposit:           " << setw(8) << deposit_ 
         << "\nMinus Withdrawls:       " << setw(8) << withdrawl_ 
         << "\nMinus Transaction Fees: " << setw(8) << fees_
         << "\nUpdated Balance:        " << setw(8) << balance_ + deposit_ - withdrawl_ - fees_
         << "\n";
        
        return ss.str();
}
    
    