/*
 * Name        : Savings.h
 * Author      : Russell Powell
 * Description : This is the base class for all Savings 
 *               tranactions. This is the Interface for the 
 *               Savings subClass.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io *
 */
 #ifndef SAVINGS_H
 #define SAVINGS_H
 
 #include "BankAccounts.h"
 
    class Savings : public Accounts
     {
         public:
             Savings();
             
             Savings(const double, const double, const double);
             
             double interest() const;
             
             void set_interest(double interest);
             
             
             string ToString() const;
             
         private:
            double interest_;
            
     };

#endif 