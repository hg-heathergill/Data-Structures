
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Heather Gill
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

#include<iostream>
#include"slistHW6.h" 
using namespace std;


// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ //cout << "slist constructor:" << endl; 
}

// positions always start at 1

// don't forget to return the position (>=1) or 0 if not found
// PURPOSE: Goes through the linked list to find the element from the user to return at the position  
// If found, it will return the position; otherwise, it will return 0.
//PARAMETER: The elem of node 
int slist::search(el_t key)
{
   bool found = false;
   Node* temp = Front; ;
  for (int K = 1; found == false && K <= Count; K++) 
{
  if(temp->Elem == key)
  {
    found = true;
    return K;
  }
  temp = temp->Next; 
}
return 0;

}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos

// PURPOSE: Checks if the value is illegal; if so, calls moveTo to replace the element.  
// Otherwise, throws an exception.  
//PARAMETER: The elem of node and elem to be returned by value
void slist::replace(el_t element, int pos)
{
  if(pos >= 1 && pos<= Count)
  {
  Node* temp;
  moveTo(pos, temp);
  temp->Elem = element;
  }

  else
  {
    throw OutOfRange(); 
  }
}

//PURPOSE: Is to overload the '==' operator to checks to see of the two lists look the same
//PARAMETER: Pass of the llist object by pass by reference
bool slist::operator==(const slist& OtherOne)
{
  int pElem;
int p2Elem;

  if ( Count != OtherOne.Count)
  {
    return false;
  }

else
  {
    Node* P;
    Node* P2;
    P = Front; // start at front
    P2=OtherOne.Front;

for (int K = 1; K <= Count; K++)   
{

if (P->Elem != P2->Elem)
  {
  return false;
  }
 P = P->Next; 
P2 =P2->Next;
}

return true;



  }
  // if not the same length, return false immediately
  // if the same lengths,
  //  check each node to see if the elements are the same
}
