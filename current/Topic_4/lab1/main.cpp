/*
 * Name        : Mmin.cpp
 * Author      : Russell Powell
 * Description : Main for lab1, topic 4
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
 
 #include "lab1.h"
 
 int main()
 {
     for (int i = 5; i < 21; i++)
     {  
       decToBin(i);
       cout << i;
     }
    
     return 0;
 }