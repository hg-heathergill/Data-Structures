

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Heather Gill
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  //  add the job j at the rear (and update count)
  //  if impossible display error message and exit. 
if(count >= MAX)
{
  cout <<"..cannot add..Full!"<<endl;
}

else
{
Q[count]=j;
count++;
}

trickleup(); // moves the job to the right place}
}
// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] << endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
      cout << "[";
      for (int i = 0; i <= count-1; i++)
	{ 
      cout <<Q[i] << " ";
  }
      cout << "]" << endl;   
    }  


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  //  simply swap the values in these locations in Q
    int temp = Q[loc1];
    Q[loc1] = Q[loc2];
  Q[loc2] = temp;
}

// Purpose: to make the very last job trickle up to the right location.
// Never do X--!!!! 
void pqueue::trickleup()
{ 

  int x = count-1;  // the very last job's location
   //  While x is > 0   
  while(x>0)
{
    // (*) Call getParent to get the location of the parent
  //based on the child's location.
  int P= getParent(x);

 //compare Q[x] with the parent value (*)
//and if the parent value is bigger call swap & update x 

if (Q[P]> Q[x])
{
  swap(P,x);
  x=P;
}
//Otherwise stop the loop.
else
{
  break;
}

}
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  //  return the parent location based on the child loc
  if(even(childloc))
  {
    return (childloc-2)/2;
  }
else
{
  return  (childloc-1)/2;
}

}


// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++!!!
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  //  Start X at 0 (the root)
  X=0;
    //  While X is within the array (the used portion):
  while(X<count)
  {
      //  Find the location of the smaller child by calling getSmallerchild.
   int S= getSmallerchild(X);
      //(if the location of both children are off the tree, stop the loop).
    if (S == -1 || Q[S] >= Q[X])
    {
      break;
    }
   // If the smaller child is smaller than the parent value,
  //call swap and X becomes the smaller child's location.
    else
    {
      swap(S, X);
      X=S;
    }
  }

  //       else no swaps so stop to loop.
  
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{ int LC, RC; // locations of children

   // set LC and RC first.
LC=  2*i+1;
RC= 2*i+2;

    //    If both are beyond count-1, you want to return a special value.
    if (LC >= count -1) // leaf
    {
      return -1;
    }
    if (RC >= count-1) 
    {
      return LC;
    } 
   //    return the location of the smaller child 
   
  if (Q[LC] < Q[RC]) 
    {
      return LC;
    }

    else
    {
      return RC;
    }

    //    Be careful because one or both of them may be
    //    beyond count-1 or just the RC is beyond count-1.
    //    Check LC and RC against boundaries before you 
    //    compare Q contents!!!!
    
}

// NEVER GO TO UNUSED PART OF THE ARRAY 
