/*
 * Name        : Box.h
 * Author      : Russell Powell
 * Description : Declare class Box
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef BOX_H
#define BOX_H

#include "Prize.h"

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class Box

{
    public:
        Box();
        //initial values 
            //boxNumber (0), 
            //boxColor ("NO COLOR"), 
            //prizeCapacity (5), 
            //prizeCount(0); 
            //in the definition, prizes array must be initialized to match prizeCapacity
            
        Box(unsigned int boxNumber, string boxColor, 
                               unsigned int prizeCapacity); 
            //parameters for boxNumber, 
            //boxColor, 
            //prizeCapacity; 
            //in the definition, prizes array must be initialized to match prizeCapacity
            
        ~Box();
            //destructor;
            //free memory associated with prizes
        
        unsigned int getBoxNumber();
            //accessors/gets boxNumber
        
        void setBoxNumber(unsigned int boxNumber);
            //mutators/sets for boxNumber
               
        string getBoxColor();
            //accessors/gets boxColor
        
        void setBoxColor(string boxColor);
            //mutators/sets for boxColor
        
        unsigned int getPrizeCapacity();
            //accessor/get ONLY for data prizeCapacity
            
        unsigned int getPrizeCount();
            //accessor/get ONLY for data prizeCount
        
       
        bool addPrize(const Prize& prize); 
            //parameters prize (Prize), 
            //return value (bool); 
            //place prize in prizes array 
            //if there is space and return true
            //else return false
                
        Prize getPrize(unsigned int index); 
            //parameters index (unsigned int), 
            //return value Prize&; 
            //return a Prize if index is valid, 
            //else return scratch (data member declared in class header)
                
        Prize removePrize(unsigned int index); 
            //parameters index (unsigned int), 
            //return value Prize; 
            //remove and return Prize if index is valid, 
            //else return scratch (data member declared in class header)
    
    private:
        unsigned int boxNumber_;
        string boxColor_;
        Prize scratch_;
        Prize* prizes; 
        unsigned int prizeCapacity_; 
        unsigned int prizeCount_;
};
#endif