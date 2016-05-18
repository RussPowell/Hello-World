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
	stringstream num_String;
	num_String << num;
	string num_string = num_String.str();
	int total;
	int i = 1;
	if(i < num_string.length())
	{
		if(num_string[i-1] == '1')
		{
			total = pow(2, i);
		}
		i++;
		return total + binToDec(0);
	}
	return total;
}