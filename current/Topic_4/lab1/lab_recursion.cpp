/*
 * Name        : lab_recursion.cpp
 * Author      : YOUR NAME
 * Description : Recursive Functions
 */

#include "lab_recursion.h"

// CODE FUNCTION DEFINITIONS HERE

/*
 * UPDATE!!!! to match the requirements
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
 string decToBin(int num)
{
    stringstream ss;
	if (num > 1) //note this makes the base case num = 0
	{
	    
	    
	    ss << decToBin(num/2); //recursive call
	}
    ss << (num%2);//outputs in correct order 
	return ss.str();
}

unsigned int binToDec(int num)
{
	
	unsigned int total = 0;
	unsigned int base = 1;
	if (num > 0)
	{													
		if(num%2 != 0)
		{										
			total = total + base;
			base *= 2;
			return  total + binToDec(num/10);
		}
			
		else
		{										
			base *= 2;
			return  total + binToDec(num/10);
		}
	}
	return total;
}	
   