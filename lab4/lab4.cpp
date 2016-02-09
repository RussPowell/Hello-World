/*
 * Name        : lab_4.cpp
 * Author      : Russell Powell
 * Description : Use branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include "lab_4.h"

/*
 * Return a string comprised of a label, followed by a space, followed by a
 * separator character, followed by a space, followed by a floating-point value.
 * For example, label="Temperature", value=41.7, separator=':' will return
 * "Temperature : 41.7".
 * @uses stringstream.
 * @param string label - The label for the value
 * @param double value - The value associated with the label
 * @param char separator - The character that separates the label and the value
 * @return string - Comprised of a label, followed by a space, followed by a
 *                  separator character, followed by a space, followed by a
 *                  floating-point value
 */
string MakeString(string label, double value, char separator) {
  stringstream ss;   //create variable-least imaginative name, apologies
  ss.clear();        //clear the variable of existing junk
  ss.str();          //define ss as a string-can be initialized, but not required
  ss << label << " " << separator << " " << value;  //arrange then format the ss variable 
 // string NewString;  //create 'return' variable
  //NewString = ss.str();  //assign the contents of ss.str into the 'return' variable
  return ss.str();  //
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param string value - The expected single character
 * @return char - The first character of the string or null character ('\0')
 *                when value is length 0 or value is length > 1
 */
char StringToChar(string value) {
  int size = value.length();        //create variable to hold the length of 'value'
  char cvalue;                      //create variable of type 'char'
  stringstream converter(value);    //I am unsure how to define what this does
  if( size == 1){                   //loop through value-if length is only 1, then
     try {                          
     converter >> cvalue;           // convert value to cvalue, which is type 'char'
     }
     catch (ios_base::failure f) {  //if converter fail, throw 'f' exception
     }
  }
  else{
    cvalue = '\0';                   //Based on the logic of the if statement,
  }                                  //the 'try' will only be called if 'size' is
  return cvalue; // output           //equal to one (1).  'Else' will be called under
}                                    //every other circumstance.  In this case, 'else'
/*                                   // sets cvalue to null.
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected integer value (such as a string
 * captured from stdin) into an integer. If value is not valid as an integer,
 * return 0.
 * @uses stringstream
 * @param string value - The expected integer value
 * @return int - An integer representing the value, or 0 on failure
 */
int StringToInt(string value) {
  int ivalue = 0;                           // create int variable-the string will eventually end up here
  stringstream converter(value);            // declare converter, a variable of type stringstream converter 
  converter.exceptions(ios_base::failbit);  // checking for exceptions
  try {
    converter >> ivalue;                    //convert to ivalue
    }
  catch (ios_base::failure f) {             //catch exceptions
    }
  return ivalue;
}
/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected floating-point value (such as a
 * string captured from stdin) into a double. If value is not valid as a double
 * return 0.
 * @uses stringstream
 * @param string value - The expected floating-point value
 * @return double - A double representing the value, or 0 on failure
 */
double StringToDouble(string value) {
  double dvalue = 0.0;                    //Basic repeat of above notes 
  stringstream converter(value);          //variables, objects
  converter.exceptions(ios_base::failbit);//define how to deal with exceptions
  try {
    converter >> dvalue;                  // convert content
    }
    catch (ios_base::failure f){          //catch exception
    }
    return dvalue;                        //return converted value
}
/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an boolean value (such as a string captured from
 * stdin) into a bool. Return true if the first character is 'T'
 * (case-insensitive), false if the first character is 'F' (case-insensitive),
 * and false on anything else.
 * @param string value - The expected string to start with either 'T' or 'F'
 * @return bool - If the first character is 'T' (case-insensitive) return true.
 *                If the first character is 'F' (case-insensitive) return false.
 *                Return false on anything else.
 */
bool StringToBool(string value) {
  bool bvalue = false;                  //declare bvalue as boolean-
  for (int i = 0; i<value.length(); i++)
  {
    value[i] = tolower(value[i]);
  }
  stringstream converter(value);
  converter.exceptions(ios_base::failbit);
  try {
    converter >> std::boolalpha >> bvalue;
    }
    catch (ios_base::failure f){
    }
    return bvalue;
}
  
/*
int main(){
     string label = "Temperature";
     double value = 41.7;
     char separator = ':';
     string STCtest = "temperature";
     cout << MakeString(label, value, separator);
     cout << StringToInt(STCtest) << "\n";
     STCtest = "909";                        //run 2X to show result for non-integer input
     cout << StringToInt(STCtest) << "\n";
     STCtest = "gR";
     cout << StringToChar(STCtest) << "\n";
     STCtest = "Q";
     cout << StringToChar(STCtest) << "\n";
     STCtest = "34.5";
     cout << StringToDouble(STCtest) << "\n"; 
     STCtest = "a";
     cout << StringToDouble(STCtest) << "\n"; 
     STCtest = "TruE";
     cout << StringToBool(STCtest) << "\n";
     STCtest = "FaLse";
     cout << StringToBool(STCtest) << "\n";
     
     
     return 0;
 }*/
