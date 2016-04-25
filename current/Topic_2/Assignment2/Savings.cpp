/*
 *Name        : Savings.cpp
 *Author      : Russell Powell
 *Description : This is the implemtation for the 
 *              Savings subClass.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io *
 *
 *
 */
 
 #include "Savings.h"
//default constructor
Savings::Savings() : Accounts()
{
    interest_ = 2.00; 
}

//Overloaded constructor    
Savings::Savings(double balance, double deposit, double withdrawl)
    : Accounts(balance, deposit, withdrawl)
{

    interest_ = 2.00;
}
double Savings::interest() const
{
    return interest_;
}

void Savings::set_interest(double interest)
{
    interest_ = interest;
}



string Savings::ToString() const
{
    stringstream ss;   //create variable-least imaginative name, apologies
        ss.clear();        //clear the variable of existing flag pobably non necessary
        ss.str();          //define ss as a string-can be initialized, but not required
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Beginning balance:      " << setw(8) << balance_ 
         << "\nPlus deposit:           " << setw(8) << deposit_ 
         << "\nMinus withdrawl:        " << setw(8) << withdrawl_
         << "\nPlus Monthly Interest:  " << setw(8) << balance_ * ((interest_ / 100)/12)
         << "\nNew Balance:            " << setw(8) << balance_ + deposit_ - withdrawl_ + (balance_ * ((interest_ / 100)/12))
         << "\n";
        
        return ss.str();
}
    
    