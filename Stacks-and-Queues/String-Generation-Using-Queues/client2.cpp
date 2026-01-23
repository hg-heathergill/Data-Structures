
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Heather Gill
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"
using namespace std;

//Purpose of the program: generate all strings using A, B, and C as the letters
//Algorithm: This program will push A-C to the queue, then go through an infinite while loop,
// using the remove and add functions to generate all strings using A-C. 
//It will also try to catch exceptions.
queue Q; 
string item;
int main()
{ //  place "A", "B", "C" in the queue
  Q.add("A");
  Q.add("B");
  Q.add("C");  
  while(true) //  while loop -- indefinitely while(true)
    {
      try
	{ 
    Q.remove(item);
    cout << item<<endl;
    Q.add(item + "A");
    Q.add(item + "B");
    Q.add(item + "C");
    // do the steps noted in the notes 
	 }
    
//Catch exceptions
catch (queue::Overflow) 
	      { cerr << "Cannot add"<<endl;  exit(1);}
catch (queue::Underflow)
	      {cerr << "Error: You have caused the queue to underflow.:";  exit(1); }
    }// end of loop

}// end of main

