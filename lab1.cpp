/* 
* Name : lab_1.cpp 
* Author : Russell Powell 
* Date : 1/27/2016 
* Description : Our First Lab of the Semester! */ 

#include <iostream> 
using std::cout; 
using std::cin; 
using std::endl; 
using std::string;

/* 
* Create a program based on the comments below 
* @param none * @return none */
string checkExperience (char hasExperience) { 
        //CODE HERE
        if (hasExperience == 'y'){
        cout << "Welcome back!" << endl;
        } else {
            cout<< "Get ready to have some fun!!" << endl;
        }
        return string("");
    }
void FirstLab() { 
        // (1) Declare a string variable named first_name 
    string first_name;
        // (2) Declare a character variable named programmed_before and another named 
        // my_character. Initialize both of them to the value 'z'
    char programmed_before = 'z';
        // (3) Display a welcome message to standard output
    cout << "Welcome to Programming and Algorythms II! \n";
        // (4) Prompt the user for their first name 
    cout << "Please enter your first name:\n";
        // (5) Read the name from standard input and store in the variable first_name 
    cin >> first_name;
        // (6) Display the message "Nice to meet you, NAME" where NAME is replaced 
        // with the value of first_name 
    cout << "Nice to meet you, " << first_name <<".\n";
        // (7) Ask the user if they have programmed before. Make sure you inform them 
        // that you want the answer as a single character (y/n)
    cout << first_name << ", have you programmed before? Please answer with a \'y\' or an \'n\'. \n";
        // (8): Read in the answer from standard input and store in the variable 
        // programmed_before 
    cin >> programmed_before;
        // (9): Call the function checkExperience appropriately so that the message will display 
        checkExperience(programmed_before);
    } 
    
    /* 
    * Create a string message based upon whether or not a user has 
    * programming experience. 
    * @param hasExperience a char ('y'es or 'n'o) representing whether 
    * or not a user has programming experience 
    * @return "Welcome back" when hasExperience is 'y', else "Get ready to 
    * have some fun" */
    
    
        int main() { 
            FirstLab();
            return 0; 
         }