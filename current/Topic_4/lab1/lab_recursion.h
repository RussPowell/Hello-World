/*
 * Name        : lab_recursion.h
 * Author      : April Browne
 * Description : Header File for Lab Recursion. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::cin;

/*
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
string decToBin(int num);

/*
 * Convert a binary number to decimal
 * @param number to be converted
 * @return an unsigned int
 */
unsigned int binToDec(int num);


#endif
