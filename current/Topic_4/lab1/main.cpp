#include "lab_recursion.h"

int main()
{
    
   int btd;
	
    for (int i = 1; i < 11; i++)
    {
        cout << decToBin(i) << "\n";
    }
    
// btd =01;     //1
// cout << binToDec(btd) << "\n";

btd = 1010;     //2
cout << binToDec(btd) << "\n";
/*
btd = 0011;     //3
cout << binToDec(btd) << "\n";

btd = 0100;     //4
cout << binToDec(btd) << "\n";

btd = 0101;     //5
cout << binToDec(btd) << "\n";

btd = 0110;     //
cout << binToDec(btd) << "\n";
*/
}