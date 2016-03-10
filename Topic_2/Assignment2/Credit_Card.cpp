/*
 *Name        : Credit_Card.cpp
 *Author      : Russell Powell
 *Description : This is the implemtation for the 
 *              Credit_Card subClass.
 *
 *Links       :
 *
 *
 *
 */
 
 #include "Credit_Card.h"
//default constructor
Credit_Card::Credit_Card() : Accounts()
{
    interest_ = 16.00; 
}

//Overloaded constructor    
Credit_Card::Credit_Card(double balance, double deposit, double withdrawl)
    : Accounts(balance, deposit, withdrawl)
{

    interest_ = 16.00;
}
double Credit_Card::interest() const
{
    return interest_;
}

void Credit_Card::set_interest(double interest)
{
    interest_ = interest;
}



string Credit_Card::ToString() const{
    stringstream ss;   //create variable-least imaginative name, apologies
        ss.clear();        //clear the variable of existing flag pobably non necessary
        ss.str();          //define ss as a string-can be initialized, but not required
        ss.setf(std::ios::fixed);
        ss.setf(std::ios::showpoint);
        ss.setf(std::ios::right);
        ss.precision(2);
        ss << "Beginning Balance:     " << setw(8) << balance_ 
        <<  "\nMinus Payment:         " << setw(8) <<deposit_ 
        <<  "\nPlus Cash advance:     " << setw(8) << withdrawl_ 
        <<  "\nPlus monthly Interest: " << setw(8) << balance_ * ((interest_ / 100)/12)
        <<  "\nNew Balance:           " << setw(8) << balance_ - deposit_ + withdrawl_ +(balance_ *((interest_ / 100)/12))
        <<  "\n";
        
        return ss.str();
}
    
    