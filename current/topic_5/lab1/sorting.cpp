/*
 * Name        : sorting.cpp
 * Author      : Russell Powell
 * Description : Working with Insertion and Shell Sort
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Resources   : Various online searches helped to direct, but 
 *               Thanks to Mike for helping to fill in some of th gaps
 *               Especially in the Shell Sort
 */
#include "sorting.h"

// CODE HERE -- FUNCTION DEFINITIONS

void SwapValues(int &value_1, int &value_2) 
{
  int temp = value_1;
  value_1 = value_2;
  value_2 = temp;
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) 
  {
    cout << value_1 << " " << value_2 << endl;
  }
}

int BubbleSort(int the_array[], unsigned int size)
{
  unsigned int i, j;
  int passes = 0;
  for (i = size - 1; i > 0; i--)
  {
    passes++;
    for (j = 0; j < i; j++)
    {
      if (the_array[j+1] < the_array[j])
      {
        SwapValues(the_array[j+1], the_array[j]);
      }
    }
  }
  return passes;
}

int OptimizedBubbleSort(int the_array[], unsigned int size)
{
  unsigned int i, j;
  int passes = 0;
  for(i=0; i < size; i++)
  {
    //DisplayArray(the_array);
    bool done = true;
    passes++;
    for(j=0; j< size ;j++)
    {
      if (!the_array[j+1])
      {}
      else if (the_array[j] > the_array[j+1])
      {
       SwapValues(the_array[j], the_array[j+1]);
       done = false;
       
      }
    }
    if (done)
    {
     return passes;  
    }
  }
  return passes;
}
 
int SelectionSort(int the_array[], unsigned int size)
{
  unsigned int i, j;
  int lsf;  //least so far
  int passes = 0;
  for (i = 0; i < size; i++)
  {
    lsf = i;
    passes++;
    for (j = (i + 1); j < size; j++)
    {
      if (the_array[j] < the_array[lsf])
      {
        lsf = j;
      }
    }
    if (the_array[i] != the_array[lsf])
    {
      SwapValues(the_array[lsf], the_array[i]);
    }
  }
  return passes;
}

int InsertionSort(int the_array[], unsigned int size)
{
  int i, j;
  int passes = 0;
  for (i = 0; i < size; i++) 
  {
    passes++;
    j = i;
    while ((j > 0) && (the_array[j] < the_array[j - 1]))
    {
      SwapValues(the_array[j-1], the_array[j]);
      j--;
    }//end of while loop
  }//end of for loop
  return passes;
}//end of insertion_sort.
 
// int ShellSort(int the_array[], unsigned int size)
// {
//   unsigned int i,j, increment;
//   int passes = 0;
//   for(increment = size/2; increment>0; increment /= 2)
//   {
//     passes++;
//     for(i=increment; i<size; i++)
//     {
//       int temp=the_array[i];
//       for(j=i; j>=increment; j -= increment)
//       {
//         if(temp < the_array[j-increment])
//         {
//           the_array[j] = the_array[j-increment];
//         }
//         else break;
//         }
//       the_array[j] = temp;
//     }
    
//   }
// }
//
int ShellSort(int the_array[], unsigned int size)
{
  unsigned int i,j;
  int increment = size/2;
  int passes = 0;
  while (increment > 0)
  {
    passes++;
    for(i = increment; i < size; i++)
    {
      int temp = the_array[i];
      j = i;
      while((j >= increment) && (the_array[j - increment] > temp))
      {
        the_array[j] = the_array[j-increment];
        j = j - increment;
      }
      the_array[j] = temp;
      DisplayArray(the_array);
      }
      increment = increment / 2;
    }
    return passes;
  }









