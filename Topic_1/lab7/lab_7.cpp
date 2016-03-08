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
    int i;
    
    for ( i = 1; i < argc; i++ )
    {
        int ivalue = 0;
        stringstream converter(argv[i]);            // declare converter, a variable of type stringstream converter 
        converter.exceptions(ios_base::failbit);  // checking for exceptions
        try 
        {
        converter >> ivalue;                    //convert to ivalue
        }
        catch (ios_base::failure f) {             //catch exceptions
        }
   
   
        if (ivalue == 10)
        {
            OnTen();
        }
        else if (ivalue == 20)
        {
            OnTwenty();
        }
        else if (ivalue ==30)
        {
            OnThirty();
        }
        else if (ivalue == 40)
        {
            OnForty();
        }
        else if (ivalue == 50)
        {
            OnFifty();
        }
        else
        {
        OnError();
        }
    }
}   