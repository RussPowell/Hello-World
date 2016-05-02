/*
 * Name        : lab_22.cpp
 * Author      : Russell Powell / Ciaran Flanagan
 *             : With an assist from Mike Harris 
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Recursive Functions
 */

//#include "lab_22.h"

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// CODE FUNCTION DEFINITIONS HERE

unsigned int Factorial(unsigned int value)
{
    if(value >= 1)                                  // If the initial value is value is less than 1 
    {
        if(value == 1)
        {
            return value;                                   // If the value is one, return one
        }                                           // This starts high and works down to one, which means this logic
        else                                        // Should never return anything but a one or a zero and therefore
        {                                           // it should fail.
        return (value * Factorial(value - 1));              // This works, but I do not understand why
        // int total = (value * Factorial(value - 1));      This Also works
        }    
    }
    else
    {
        return 1;                                   // Return 1
    }
}


unsigned int Fibonacci(unsigned int fib_value)
{  
    if (fib_value == 1)         
    {
        return 1;                                           // Return 1 for value of one
    }
    else if (fib_value == 0)
    {
        return 0;                                           // Return 0 for value of zero
    }
    else
    {
        return Fibonacci(fib_value - 1) + Fibonacci(fib_value - 2);     //call the function with new values
    }
    
}

bool WordIsPalindrome(string word)
{
    if(word.length() > 1)                                            // Test for word length greater than one
    {
        if(word[0] == word[word.length() - 1])                       // Test for match of first and last letter
        {                                                            
            string new_word = word.substr(1, word.length() - 2);     // Create new substring of the original
            WordIsPalindrome(new_word);                              // Call the function using the new word
        }
        
        else
        {
            return false;                                            // If letter do not match at any time, skip the above
        }                                                            // and return false
    }
    return true;                                                    // Return true if word length of 1 or 0
}

string ArrayForwardsAsString(int array[], unsigned int start, unsigned int size)
{
    stringstream ss;                                                // Create a string stream variable
    if (start == size)
    {
        return "";                                                  // Test against size return nothing if they are the same
    }
    else
    {
        ss << array[start] << " ";                                  // Capture the data
        if((start + 1) < size)                                      // Test for next start less than size
        {
            ss << ArrayForwardsAsString(array, start +1, size);     // capture the next data if appropriate
        }
        return ss.str();                                            // Return the string with all data
    }
}

string ArrayBackwardsAsString(int array[], int start,
                             unsigned int size)
{
    stringstream ss;                                // Create a string stream variable
    if (start < 0)                                  // check for start smaller than the index of the array
    {
        return "";                                  // handle if not
    }                       //******** The instructions call for unsigned int for start, but the test case passes
                            //******** a negative 'start' which does not work.  Once fixed, had to handle a negative index
    ss << array[start] << " ";                      // feed the current number into the string 
    
    if(start > 0)                                   // if the   current 'start' is greater than 0, 
    {
        ss << ArrayBackwardsAsString(array, start -1, size);    //call function and decrement start 
    }
    return ss.str();
}