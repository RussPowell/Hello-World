/*
 * Name        : driver.cpp
 * Author      : Russell Powell
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 *
 * Description : Creating a template for use with a binary tree
 */

#include "bs_treet.h"

int main() {
    string filename;
    string read_in;
    
    cout << "Specify the filename to read in." << endl;
    cin >> filename;
    
    filename = filename + ".txt";
    
    // Initialize and open InputFile
    ifstream InputFile;
    InputFile.open(filename.c_str());
    BSTreeT<string>* tree;
    
    if(InputFile.is_open()) {
        while(!InputFile.eof()) {
            char read = InputFile.get();
            
            if (read == 35){
                getline(InputFile, read_in);
                //do nothing
                
            }
            else if(read == 'C' || read == 'c') {
                cout << "Creating new Tree!" << endl;
                tree = new BSTreeT<string>;
                cout << "        Tree Created, New Size = " << tree->GetSize() << endl;
            }
            else if(read == 'X' || read == 'x') {
                tree->Clear();
                cout << "Cleared ALL Trees!" << endl;
            }
            else if(read == 'D' || read == 'd') {
                cout << "Deleting ALL Trees...." << endl;
                tree->~BSTreeT();
                if(tree->GetSize() != 0) {
                    cout << "        Deletion was unsuccessful!\n        Size returned as: " << tree->GetSize() << ".\n        Expected ZERO(0)" << endl;
                } else {
                    cout << "        Deletion Success!\n        Size returned as: 0" << endl;
                }
            }
            else if(read == 'I' || read == 'i') {
                cout << "Inserting into trees!" << endl;
                getline(InputFile, read_in);
                cout << "Inserting: " << read_in << endl;
                tree->Insert(read_in);
                cout << "        Insertion Completed!\n        Size returned as: " << tree->GetSize() << endl;
            }
            else if(read == 'F' || read == 'f') {
                cout << "Searching for input!" << endl;
                getline(InputFile, read_in);
                cout << "Searching for: " << read_in << endl;
                if(tree->Exists(read_in)) {
                    cout << "        Search Term was found in the Tree!" << endl;
                }
                else {
                    cout << "        Search term was NOT found!" << endl;
                };
            }
            else if(read == 'R' || read == 'r') {
                cout << "Removing input from tree!" << endl;
                getline(InputFile, read_in);
                if(tree->Exists(read_in)) {
                    tree->Remove(read_in);
                    cout << "        Deletion was successful!\n        Size returned as: " << tree->GetSize() << endl;
                }
                else {
                    cout << "        Deletion was unsuccessful!\n        " << read_in << " was not found." << endl;
                }
            }
            else if(read == 'G' || read == 'g') {
                getline(InputFile, read_in);
                cout << "Retrieving: " << read_in << endl;
                if(tree->Exists(read_in)) {
                    cout << "        Successfully retrieved " << read_in << endl;
                }
                else {
                    cout << "        Unsuccessful." << endl;
                }
            }
            else if(read == 'N' || read == 'n') {
                cout << "Retrieving current Node count in tree!" << endl;
                cout << "        " << tree->GetSize() << endl;
            }
            else if(read == 'O' || read == 'o') {
                cout << "Reading out tree FORWARDS!" << endl;
                if(tree->GetSize() == 0) {
                    cout<< "        TREE EMPTY!!" << endl;
                }
                else { 
                    cout << "       " << tree->ToStringForwards() << endl;
                }
            }
            else if(read == 'E' || read == 'e') {
                cout << "Reading out tree BACKWARDS!" << endl;
                if(tree->GetSize() == 0) {
                    cout<< "        TREE EMPTY!!" << endl;
                }
                else { 
                    cout << "       " << tree->ToStringBackwards() << endl;
                }
            } else {
                
            }
        }
    }
    
    InputFile.close();
}