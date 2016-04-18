/*
 * Name        : Box.cpp
 * Author      : Russell Powell
 * Description : Implement class Box
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
*/
#include "Box.h"
#include "Prize.h"

        Box::Box()
        {
            //initial values 
            boxNumber_ = 0; 
            boxColor_ = "NO COLOR"; 
            prizeCapacity_ = 5; 
            prizeCount_ = 0;
            
            //in the definition, prizes array must be initialized to match prizeCapacity
            prizes = new Prize[prizeCapacity_];
        }
        
        Box::Box(unsigned int boxNumber, string boxColor, unsigned int prizeCapacity )
        {
            boxNumber_ = boxNumber;
            boxColor_ = boxColor;
            prizeCapacity_ = prizeCapacity;
            prizeCount_ = 0;
            prizes = new Prize[prizeCapacity_];    
            //parameters for boxNumber, 
            //boxColor, 
            //prizeCapacity; 
            //in the definition, prizes array must be initialized to match prizeCapacity
        }
        
        Box::~Box()
        {
           
                delete[] prizes;
           
            //free memory associated with prizes
        }
        
        void Box::setBoxNumber(unsigned int boxNumber)
        {
            boxNumber_ = boxNumber;
        }
            //mutators/sets for boxNumber
            
        unsigned int Box::getBoxNumber()
        {
            
            return boxNumber_;
        }
            //accessors/gets boxNumber 
            
            
            
        
        string Box::getBoxColor()
        {
            //cout << boxColor_ << " get ";
            return boxColor_;
        }
            //accessors/gets boxColor
            
        void Box::setBoxColor(string boxColor)
        {
            boxColor_ = boxColor;
            //cout << boxColor_ << " set ";
        }
            //mutators/sets for boxColor
            




        unsigned int Box::getPrizeCapacity()
        {
            return prizeCapacity_;
        }
            //accessor/get ONLY for data prizeCapacity
            
        unsigned int Box::getPrizeCount()
        {
            return prizeCount_;
        }
            //accessor/get ONLY for data prizeCount
        
        bool Box::addPrize(const Prize& prize) 
        {
            if (prizeCount_ < prizeCapacity_) {
                prizes[prizeCount_] = prize;
                prizeCount_ += 1;
                return true;
            }
            else
            {
                return false;
            }
            //parameters prize (Prize), 
            //return value (bool); 
            //place prize in prizes array 
            //if there is space and return true
            //else return false
        }
        
        Prize Box::getPrize(unsigned int index)
        {
            if(index >= prizeCount_)
            {
                return scratch_;
            }
            else 
            {
                return prizes[index];
            }
            return scratch_;
        }
            //parameters index (unsigned int), 
            //return value Prize&; 
            //return a Prize if index is valid, 
            //else return scratch (data member declared in class header)
            
        Prize Box::removePrize(unsigned int index)
         {
            if(index < prizeCount_ )
            {
                Prize temp = prizes[index];
                for (unsigned int p = index; p < prizeCount_-1; p++)
                {
                    prizes[p] = prizes[p+1];
                }
                prizeCount_--;
                return temp;            
            }
            else
            {
                return scratch_;
            }
            
            
        }
            //parameters index (unsigned int), 
            //return value Prize; 
            //remove and return Prize if index is valid, 
            //else return scratch (data member declared in class header)
    