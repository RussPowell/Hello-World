/*
 * Name        : Checking.h
 * Author      : Russell Powell
 * Description : This is the base class for all checking 
 *               tranactions. This is the Interface for the 
 *               Checking subClass.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io *
 */
 #ifndef CHECKING_H
 #define CHECKING_H
 
 #include "BankAccounts.h"
 
    class Checking : public Accounts
     {
         public:
             Checking();
             
             Checking(const double, const double, const double);
             
             double fees() const;
             
             void set_fees(double fees);
             
             
             string ToString() const;
             
         private:
            double fees_;
            
     };

#endif 