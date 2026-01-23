#include <iostream>
#include <vector>
using namespace std;  

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Heather Gill
//Compiler: g++
//--------------------------------------------

// Purpose: To combine two vectors into another one.  
// Overall Algorithm/Design: Uses a function that takes user input in a vector and sorts the elements  
// from lowest to highest into another vector.


// combines two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
 int ia=0;
 int ib=0;

while (ia < A.size() && ib < B.size()) 
  {
    cout << "comparison" << endl;
      // Add the smaller element to R
      if (A[ia] < B[ib]) 
        {
         R.push_back(A[ia]);
            ia++;
        } 
      else 
        {
            R.push_back(B[ib]);
            ib++;           
        }
  }
// Adding the elements that are left
while (ia < A.size())
 {
        R.push_back(A[ia]);
        ia++;
    }
    while (ib < B.size())
     {
        R.push_back(B[ib]);
        ib++;
    }
  
}
     // you can find out the size of A using the
    // size function. Treat A and B like arrays. 
     // be careful -- R comes in as an empty vector with no slots 
     //so you have to use push_back

// end of function


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1,L2,L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
