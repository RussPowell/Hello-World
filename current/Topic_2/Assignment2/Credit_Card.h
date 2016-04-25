/*
 * Name        : Credit_ard.h
 * Author      : Russell Powell
 * Description : This is the base class for all Credit_card 
 *               tranactions. This is the Interface for the 
 *               Credit_card subClass.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io 
 */
 #ifndef CREDIT_CARD_H
 #define CREDIT_CARD_H
 
 #include "BankAccounts.h"
 
    class Credit_Card : public Accounts
     {
         public:
             Credit_Card();
             
             Credit_Card(const double, const double, const double);
             
             double interest() const;
             
             void set_interest(double interest);
             
             
             string ToString() const;
             
         private:
            double interest_;
            
     };

#endif 