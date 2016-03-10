 /*
 * Name        : BankAccounts.cpp
 * Author      : Russell Powell 
 * Description : This is the implentation of
 *               the BankAccounts Class
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
 
#include "BankAccounts.h"
using std::cout;
        // default constructor-3 protected variables defaulted to 0
    Accounts::Accounts()
    {
        balance_ = 0;
        deposit_ = 0;
        withdrawl_ = 0;
    }
        // Overloaded constructor-3 protected variables take value from parameters 
    Accounts::Accounts(double balance, double deposit, double withdrawl)
    {
        balance_ = balance;
        deposit_ = deposit;
        withdrawl_ = withdrawl;
    }
        // "setting and getting"
    double Accounts::balance() const
    {
        return balance_;
    }
    double Accounts::deposit() const
    {
        return deposit_;
    }
    double Accounts::withdrawl() const
    {
        return withdrawl_;
    }
    
    void Accounts::set_balance(double balance)
    {
        balance_ = balance;
    }
    void Accounts::set_deposit(double deposit)
    {
        deposit_ = deposit;
    }
    void Accounts::set_withdrawl(unsigned int withdrawl)
    {
        withdrawl_ = withdrawl;
    }
    string Accounts::ToString() const
    {   
        //double updated_balance = balance_ + deposit_ - withdrawl_;
        stringstream ss;   //create variable-least imaginative name, apologies
        ss.clear();        //clear the variable of existing flag pobably non necessary
        ss.str();          //define ss as a string-can be initialized, but not required
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Beginning Balance:     " << setw(8) << balance_ 
         << "\nPlus Deposit:          " << setw(8) << deposit_ 
         << "\nMinus Withdrawls:      " << setw(8) << withdrawl_
         << "\nNew Balance:           " << setw(8) << balance_ + deposit_ - withdrawl_
         << "\n";
        
        return ss.str();
    }