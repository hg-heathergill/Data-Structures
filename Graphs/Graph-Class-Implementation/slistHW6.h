
//=================================================
// HW#: HW3P2 slist
// Name: Heather Gill
// File: Slist.h header file
//=================================================

#include"llistHW6.h"    
// for includes

class slist: public llist
{

 public:
  
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

//HOW TO CALL: Provide the element to be found as an argument. 
// PURPOSE: Goes through the linked list to find the element from the user to return at the position  
// If found, it will return the position; otherwise, it will return 0.  
  int search(el_t );
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.
    

  //HOW TO CALL: Provide the element to be replaced as an argument
  // PURPOSE: Checks if the value is illegal; if so, calls moveTo to replace the element.  
// Otherwise, throws an exception.  
  void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
//Overloading of ==  (returns a reference to a slist)
  bool operator==(const slist&);
    // checks to see of the two lists look the same
    

};
