/*
 * Name        : BankAccounts.h
 * Author      : Russell Powell
 * Description : This is the base class for all banking 
 *               tranactions. This is the Interface for the 
 *               Bankaccounts Class.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io *
 */
#ifndef BANKACCOUNTS_H
#define BANKACCOUNTS_H
#include <iomanip>     //needed for setting width
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::setw;
using std::setprecision;

// CODE HERE -- CLASS FUNCTION DEFINITIONS
class Accounts
{
    public:
        Accounts();
                   //Three common factors for the subclasses
        Accounts(const double, const double, const double);
        double balance() const;
        double deposit() const;
        double withdrawl() const;
        
        
        void set_balance(double balance);
        void set_deposit(double deposit);
        void set_withdrawl(unsigned int withdrawl);
        
        
        string ToString() const;
 
    protected:
        double balance_;
        double deposit_;
        double withdrawl_;
};

#endif 