#include<iostream>
using namespace std;

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Heather Gill
//Compiler: g++
//-----------------------------------------

// Purpose: Uses Quick Sort’s Partition to divide the array around a pivot.
// Overall Algorithm/Design: Uses a function to compare the elements in the array around the pivot,  
// which is chosen by the user. The process involves comparing and swapping elements until the array is sorted.



// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition( int a[], int f, int r)
{
  int pivot = a[f];  // pivot is the first element
  int small = f; // small pointer from the left
  int large = r; // large pointer from the right 


  while (small <= large)//until they cross
    {
      // loop for finding out-of-place pairs and swap them
      //    until the small and large cross

      // you will be checking a[small] and a[large] against pivot
      //    if both are bad (and not crossed yet), swap and then move

      //    if a[small] is OK, move small
      if(a[small] <pivot )
        {
           small++;
        }
    //    if a[large] is OK, move large
    else if(a[large] >= pivot)
      {
           large--;
      }
  //swap
   else
      {
     int temp = a[small];
     a[small] = a[large];
     a[large] = temp;
      }
  
    }//end of while

   // return the partition point where
   // those smaller than pivot are before what is returned
   // there is a special cases (small is at the very beginning)
   //       and a regular case
   
   if(pivot == a[0])
     {
      return small +1;
     }
   else
    {
      return small;
    }
   
}//end of function

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }
  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;
  int part = partition(nums, 0, x-1);
  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
