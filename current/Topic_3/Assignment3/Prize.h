/*
 * Name        : Prize.h
 * Author      : Russell Powell
 * Description : Declare class Prize
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */

#ifndef PRIZE_H
#define PRIZE_H

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
#include <sstream>
using std::stringstream;

class Prize
{

    public: 
        Prize();
            //default constructor: initial values itemName ("NO NAME"), itemValue (0)
        Prize(string prize, unsigned int value);
            //overloaded constructor: parameters for all data members
        ~Prize();
            //destructor: empty
        string getPrizeName ();
        void setPrizeName(string Prize);
        
        unsigned int getPrizeValue ();
            //accessors/gets 
        void setPrizeValue(unsigned int value);
            //mutators/sets for all data members
        
       friend bool operator==(const Prize& p1, const Prize& p2);
      
            //returns true if the prizeName and prizeValue of the two Prizes being compared are equivalent, else return false
    
    private: 
        string prizeName_; 
        unsigned int prizeValue_; 
};

#endif