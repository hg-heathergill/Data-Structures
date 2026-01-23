#include <iostream>
#include <vector>
using namespace std;  

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: **
//Compiler: g++
//--------------------------------------------

// combines two sorted lists A and B into R
// displays comparison every time it is done
#include <iostream>
#include <vector>
using namespace std;

void combine(vector<int>& A, vector<int>& B, vector<int>& R) {
    cout << "enter" << endl;
    int ia = 0, ib = 0;

    // Compare elements from A and B
    while (ia < A.size() && ib < B.size()) {
        cout << "comparison" << endl;
        cout << "size ia: " << ia << endl;
        cout << "size ib: " << ib << endl;

        // Add the smaller value to the new array, no matter which array it comes from
        if (A[ia] < B[ib]) {
            R.push_back(A[ia]);
            ia++;
        } else {
            R.push_back(B[ib]);
            ib++;
        }
    }

    // If there are remaining elements in A, add them
    while (ia < A.size()) {
        R.push_back(A[ia]);
        ia++;
    }

    // If there are remaining elements in B, add them
    while (ib < B.size()) {
        R.push_back(B[ib]);
        ib++;
    }
}


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
  cout << "main" <<endl;

  

  combine(L1,L2,L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main