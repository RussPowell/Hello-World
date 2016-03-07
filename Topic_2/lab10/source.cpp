



/*Author:      Russell Powell
Description: Converts temperature from Fahrenheit to Celcius and Kelvin
Input is temperature in Fahrenheit
using a class, Temperature, and two "Functions"
CSCI 20

#include <iostream>
#include <cstdlib>
#include "TemperatureConversion.h"

using namespace std;

int main()
{
	for (int i = 0; i < 4; i++)//loop not included in assignment, 
							   //but is easier to get screen shot 
							   //of all four at once.
	{
		double TempFahrenheit = 0;
		double TempCelcius = 0;
		double TempKelvin = 0;

		// seeking user input
		cout << "Please input a temperature for conversion: \n\t ";
		cin >> TempFahrenheit;
		Temperature today(TempFahrenheit);

		cout.setf(ios::fixed);      // "fixed" tells the computer to output the float, or double, numbers in fixed point notation, not e-notation 
		cout.setf(ios::showpoint);  // "showpoint" tells the computer to alway show a decimal
		cout.precision(2);          // "precision(n)" tells the computer how many numbers aftert he decimal.

		//Printing the output
		cout << "Your temperature is " << today.getTempFahrenheit() << " degrees Fahrenheit, or \n";
		cout << "\t " << today.getTempCelcius() << " degrees Celcius, or \n";
		cout << "\t	" << today.getTempKelvin() << " degrees Kelvin";
		system("pause");//in visual studio only
	}
	return 0;
}*/