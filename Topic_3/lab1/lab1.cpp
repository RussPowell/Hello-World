/*
 * Name        : lab_12.cpp
 * Author      : FILL IN
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include "lab1.h"

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
 
 
int* MakeDynoIntArray(unsigned int size)
{
    int* my_array = new int[size];
    return my_array;
}

/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */ 
int Sum(int* the_array, unsigned int array_size)
{
    int* my_array = the_array;
    unsigned int my_array_size = array_size;
    int total = 0;
    if (the_array != NULL)
    {
        for (int i = 0; i < array_size; i++)
        {
            total = total + the_array[i];
        }
    }
    else
    {
        throw "NULL ARRAY REFERENCE";
    }
    return total;
}

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size)
{
    int* my_array = the_array;
    unsigned int my_array_size = array_size;
    int greater = 0;
    if (the_array != NULL)
    {
        for (int i = 0; i < array_size; i++)
        {
            if ( my_array[i] > greater)
            {
                greater = my_array[i];
            }
        }
    }
    else
    {
        throw "NULL ARRAY REFERENCE";
    }
    return greater;
}

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size)
{
int* my_array = the_array;
    unsigned int my_array_size = array_size;
    int minimum = 100000;
    if (the_array != NULL)
    {
        for (int i = 0; i < array_size; i++)
        {
            if ( my_array[i] < minimum)
            {
                minimum = my_array[i];
            }
        }
    }
    else
    {
        throw "NULL ARRAY REFERENCE";
    }
    return minimum;    
}
