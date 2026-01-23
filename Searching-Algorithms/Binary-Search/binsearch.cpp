#include <iostream>
#include <cmath> 
using namespace std;

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Heather Gill
// Compiler: g++
// --------------------------------------------


// Purpose: Uses binary search to find the users element.
// Overall Algorithm/Design: Uses a function that starts from the middle and evaluates which side would be more beneficial. 
//It continues this process until the element is found, with a case for when the element is not found.


// x is what we are looking for in L; first and last are slot numbers 
// This recursive function returns the slot number in which x was found
// or -1
int binarySearch(int L[], int x, int first, int last) 
{
  //  Be sure to check for first > last and
  //   first == last cases to
  //   end the recursion now
 
int middle;
middle= floor((first+last)/2);

if(first - last == 1) //checking if theres no element found
{
  return -1;
}
 // the mid is found... 
    cout << "comparing against an element in slot " << middle << endl;

if (x == L[middle]) 
{ 
   return middle;
}  // found x at location middle, so return the location
   else if (x < L[middle]) 
   {
      last  = middle - 1;  	// go to first half
   }
   else if (x > L[middle]) 
   {
      first = middle + 1; 	// go to second half
   }
  
   return binarySearch(L, x, first, last); 		// recursive call

}// end of function


int main()
{ 
  
int const MAX =10;
int A[MAX];
int myfirst= 0;
int mylast=MAX-1;
int e;  // to look for this


  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A,e,myfirst,mylast);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}//end of main
