/*
 * Name        : lab_7.cpp
 * Author      : Russell Powell
 * Description : Working with File I/O
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
#include "lab_7.h"


// CODE HERE -- FUNCTION DEFINITION FOR ProcessFile()
bool ProcessFile(string filename){
    bool open_file = false;
    //open file
    ifstream inputstream;
    inputstream.open(filename.c_str());
    if (inputstream.fail())
    {
        cout << "Opening " << filename << " failed! \n";
    }
    
    int next;
    while (!inputstream.eof())
    {
        while(inputstream>>next){
        switch (next)
        {
            case 10:
                OnTen();
                break;
                
            case 20:
                OnTwenty();
                break;
                
            case 30:
                OnThirty();
                break;
                
            case 40:
                OnForty();
                break;    
                
            case 50:
                OnFifty();
                break;
                
            default:
                OnError();
        }
        
    
    }
    inputstream.close(); 
    //if successful-return true
    //processArguments
    return open_file;
    }
}

void ProcessArguments(int argc, char* argv[])
{
/* main
 * params : argc ( No. of command line arguments )
 * argv[] : array of strings ( arguments )
 */
}