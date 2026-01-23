
//=============================================================

#include "slistHW8.h"

const int TSIZE = 37;  // prime number 

class htable
{
 private:
  slist table[TSIZE];   // each node is a key and name
  
  //HOW TO CALL: Takes in an int. Returns int.  
  //PURPOSE: utility hash function
  int hash(int);   // utility hash function
  
 public:
  htable();
  ~htable();

  //HOW TO CALL: Takes in istream. Returns nothing.
  //PURPOSE:fills the table by reading data from the istream
  void fillTable(istream&);

  //HOW TO CALL: Takes in an element. Returns int.
  //PURPOSE: adds the element and returns the slot number
  int add(el_t);
  
  //HOW TO CALL: Takes in an int. Returns el_t.
  //PURPOSE: finds the element based on the key and returns it
  el_t find(int);
  
  //HOW TO CALL: Takes in an int. Returns int.
  //PURPOSE: deletes the element based on the key and returns the slot number
  int deleteIt(int);  
  
  //HOW TO CALL: No argument. Returns nothing.
  //PURPOSE: displays the table including slot numbers
  void displayTable();
  
  //HOW TO CALL: Takes in an ostream. Returns nothing.
  //PURPOSE: saves into a file in the same format as the input file
  void saveTable(ostream&); 

};
