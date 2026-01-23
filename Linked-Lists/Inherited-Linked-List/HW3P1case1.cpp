
//=========================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  g++
//File type: client program (tester) HW3P1case1.cpp
//===========================================================

#include <iostream>
#include <stdlib.h>
#include "llist.h"
using namespace std;


void caseOne()
{
  cout << "CASE 1: Basic --------------- " << endl;
  llist L;   // this is my list
  int x;     // to hold a removed element

  //1 check empty and report the result  
  cout << "Step " << 1 << endl;
  if (L.isEmpty()) cout << "It is empty" << endl;
  else cout << "It is not empty" << endl;

  //2 display the list  
  cout << "Step " << 2 << endl;
  L.displayAll();

  //3 add 4 integers to rear 1,2, 3,4    
  cout << "Step " << 3 << " adding  1 2 3 4" << endl;
  L.addRear(1); L.addRear(2);
  L.addRear(3); L.addRear(4);

  //4 display the list  
  cout << "Step " << 4 << endl;
  L.displayAll();  // should come out 1 2 3 4

  //5 remove from front twice using x (and display the elements removed)
  cout << "Step " << 5 << " deleteFront twice" << endl;
  L.deleteFront(x);
  cout << "Removed: " << x << endl;
   L.deleteFront(x);
  cout << "Removed: " << x << endl;

  //6 display the list
  cout << "Step " << 6 << endl;
  L.displayAll();

  //7 check empty and report the result 
   cout << "Step " << 7 << endl;
  if (L.isEmpty()) cout << "It is empty" << endl;
  else cout << "It is not empty" << endl;

  //8 remove from the rear twice using x (display the elements removed)
  cout << "Step " << 8 << " deleteRear twice" << endl;
    L.deleteRear(x);
  cout << "Removed: " << x << endl;
  L.displayAll();  // this is needed to make sure your end is NULL
    L.deleteRear(x);
  cout << "Removed: " << x << endl;

  //9 check empty again and report the result
   cout << "Step " << 9 << endl; 
  if (L.isEmpty()) cout << "It is empty" << endl;
  else cout << "It is not empty" << endl;

   // 10 add to front 4 times (elements 9, 8, 6, 5)
     // and display the 3rd element using getIth
   cout << "Step " << 10 << endl; 
   L.addFront(9);
   L.addFront(8);
   L.addFront(6);
   L.addFront(5);
   L.getIth(3,x);
     cout << "The 3rd element is :" << x << endl;

     
   // 11.display the list
   cout << "Step " << 11 << endl; 
  L.displayAll(); 

  // 12.remove from the rear 4 times (display the elements removed)
     cout << "Step " << 12 << " deleteRear all" << endl;
     L.deleteRear(x);
     cout << "Removed: " << x << endl;
     L.deleteRear(x);
     cout << "Removed: " << x << endl;
         L.deleteRear(x);

     cout << "Removed: " << x << endl;
     L.deleteRear(x);
     cout << "Removed: " << x << endl;
  
  //  13.display the list again
   cout << "Step " << 13 << endl; 
   L.displayAll(); 

}//end of case 1 

//PURPOSE of the Program: to test llist thoroughly
//Algorithm/Design: test case1
int main()
{

  caseOne(); // tests adding and deleting from front and rear

}// end of main

