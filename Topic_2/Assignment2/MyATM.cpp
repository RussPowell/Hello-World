/*
 * Name        : MyATM.cpp, assignment 2
 * Author      : Russell Powell
 * Description : This is the access point to all the Bank and,
 *               all accounts therein.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
 //****These had to be commented out for the make file to work
 //****with this file
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include "BankAccounts.h"
#include "Checking.h"
#include "Savings.h"
#include "Credit_Card.h"
using std::cout;
using std::ios;
using std::cin;
                     // This checking function is designed to get specifics of todays activity.
                     // Naming is consistent with what we have been using with exceptions.
                     // There is a second function, called savings, and a third called credit_card.
                     // Credit cards do not accept deposits, they accept payments.  If an effort
                     // to streamline a bit, the variables withdraw and deposit have been left in
                     // place in credit card, but the verbage in the print out is correct.
void checking()
{
    Checking Today;
    int choice = 0;
    double amount = 0;
    double current_balance = 1500;
    double withdraw = 0;
    double deposit = 0;
     //The above variables are necessary for passing to the class.
     //The next few lines of code are to get specifics on transaction 
     //and amount, with default in place.
    cout << "Select a transaction,\n 1 for deposit, or 2 for withdrawl:\n Default is deposit.\n";
    cin >> choice;
    cout << "Enter an amount:\n";
    cin >> amount;
    if (choice == 2)
    {
        Today.set_deposit(deposit);
        Today.set_withdrawl(amount);         // If a withdrawl is called for, amount is used
        Today.set_balance(current_balance);  // instead of 'withdrawl'.
        cout << Today.ToString();
    }
    else
    {
        Today.set_deposit(amount);
        Today.set_withdrawl(withdraw);       //If any other selection for transaction is made,
        Today.set_balance(current_balance);  //amount is used instead of 'deposit'.
        cout << Today.ToString();
    }
}
                         // The following two functions are nearly identicle in verbage,
                         // though the call other classes
void savings()
{
    Savings Today;
    int choice = 0;
    double amount = 0;
    double current_balance = 1500; 
    double withdraw = 0;
    double deposit = 0;
    cout << "Select a transaction,\n 1 for deposit, or 2 for withdrawl:\n Default is payment.\n";
    cin >> choice;
    cout << "Enter an amount:\n";
    cin >> amount;
    if (choice == 2)
    {
        Today.set_deposit(deposit);
        Today.set_withdrawl(amount);
        Today.set_balance(current_balance);
        cout << Today.ToString();
    }
    else
    {
        Today.set_deposit(amount);
        Today.set_withdrawl(withdraw);
        Today.set_balance(current_balance);
        cout << Today.ToString();
    }
}

void credit_card()
{
    Credit_Card Today;
    int choice = 0;
    double amount = 0;
    double current_balance = 1500;
    double withdraw = 0;
    double deposit = 0;
    cout << "Select a transaction,\n 1 for payment, or 2 for cash advance:\n Default is deposit.\n";
    cin >> choice;
    cout << "Enter an amount:\n";
    cin >> amount;
    if (choice == 2)
    {
        Today.set_deposit(deposit);
        Today.set_withdrawl(amount);
        Today.set_balance(current_balance);
        cout << Today.ToString();
    }
    else
    {
        Today.set_deposit(amount);
        Today.set_withdrawl(withdraw);
        Today.set_balance(current_balance);
        cout << Today.ToString();
    }
}

int main()
{
 
 int choice;
 cout << "Select account:\n";
 cout << "1 for Checking, 2 for Savings or 3 for Credit Card./n";
 cout << "default is Checking.\n";
 cin >> choice;
 
 switch (choice)
 {
     case 2:
     savings();
     break;
     
     case 3:
     credit_card();
     break;
     
     default:
     checking();
     break;
 }
 return 0;
}