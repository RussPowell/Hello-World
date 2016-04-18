 /*
 * Name        : Prize.cpp
 * Author      : Russell Powell
 * Description : Define class Price
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
 
 #include "Prize.h"
 
        Prize::Prize()
        {
            prizeName_ = "NO NAME";
            prizeValue_ = 0;
            //default constructor: initial values itemName ("NO NAME"), itemValue (0)
        }
            
        Prize::Prize(string prize, unsigned int value)
        {
            prizeName_ = prize;
            prizeValue_ = value;
            //overloaded constructor: parameters for all data members
        
        }
        
        Prize::~Prize()
        {
            //destructor: empty
        }
        
        string Prize::getPrizeName ()
        {
            return prizeName_;
        }                                                   //accessors/gets
        unsigned int Prize::getPrizeValue () 
        {
            return prizeValue_;
        }
             
        void Prize::setPrizeName(string prize) 
        {
            prizeName_ = prize;
        }
                                                            //mutators/sets for all data members    
        void Prize::setPrizeValue(unsigned int value)
        {
            prizeValue_ = value;
        }
        
        bool operator==(const Prize& p1, const Prize& p2)
       {
           if (p1.prizeName_ == p2.prizeName_)
           {
               if (p1.prizeValue_ == p2.prizeValue_)
               {
               return true;
               }
           }
           else
           {
               return false;
           }
           
       }
       //return p1.prizeName_ == p2.prizeName_ && p1.prizeValue_ == p2.prizeValue_;
            
      /*  friend bool& Prize::operator==()
        {
            if (prize1 == prize2 && prize1value == prize1value)
            {
                return true;
            }
            else
            {
                return false;
            }
        }*/
            //returns true if the prizeName and prizeValue of the two Prizes being compared are equivalent, else return false
   
   
   
   
   