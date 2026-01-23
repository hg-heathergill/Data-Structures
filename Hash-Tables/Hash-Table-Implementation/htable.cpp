

// ============================================
// HW#: HW8 Hash Table
// Name: Heather Gill
// File Type: implementation htable.cpp
// =============================================

#include <iostream>
#include "htable.h"
#include <fstream>
using namespace std;


htable::htable()
{}

htable::~htable()
{}

//PURPOSE: utility hash function
//PARAMETER: Takes in an int. Returns int.  
// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ return key % TSIZE;  }  // for EC, string key has to be converted to int first

//PURPOSE: adds the element and returns the slot number
//PARAMETER: Takes in an element. Returns int.
int htable::add(el_t element )
{
  int slot = hash(element.getkey());  // hash with the key part
  table[slot].addRear(element); //put element in hashed slot
  return slot;
   // Note that this means adding the element to a slist in the slot (call addRear)
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
//PURPOSE: finds the element based on the key and returns it
//PARAMETER: Takes in an int. Returns el_t.
el_t htable::find(int skey)
{ 
int location;
int temp;
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 location=table[slot].search(selement); // call slist's search with selement which returns the location.
 table[slot].getIth(location,selement);// you can use llist's getIth to get the element.
 if(location >=0)
 {
    return selement;
 }
  // return the found element from here or a blank element
    // if search had returned 0 
  else
  {
    return el_t();
  }
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
//PURPOSE: deletes the element based on the key and returns the slot number
//PARAMETER: Takes in an int. Returns int.
int htable::deleteIt(int skey)
{
  int location;
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); //  initialize selement with just the skey
 location=table[slot].search(selement); //  call slist's search which gives you the location I and then call deleteIth 
 table[slot].deleteIth(location,selement);
 if(location >=0)
 {
    return slot;
 }
  // return the found element from here or a blank element
    // if search had returned 0 
  else
  {
    return -1;
  }
 //return -1; //  return the slot number or -1
}

// fills the table using the specified input file 
//PURPOSE:fills the table by reading data from the istream
//PARAMETER: Takes in istream. Returns nothing.
void htable::fillTable(istream& fin)
{ int akey;
  string anArtist;
  string aSong;
  int aDate;
  //  Model this after HW6 to get data from the file the user specified
  //  Which elem and slist functions do you call? List them here first.
  while (fin >> akey){ 
    fin.ignore();
    getline(fin,anArtist, ',');
    getline(fin,aSong, ',');
    fin >>aDate;

    // fin other parts and create an element object
    el_t element(akey,anArtist,aSong,aDate);
    // You can call the add function to add the created element to the table
    add(element);
  }
}

// displays the entire table with slot#s too
//PURPOSE: displays the table including slot numbers
//PARAMETER: No argument. Returns nothing.
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
       table[i].displayAll();// call slist's displayAll 
   }

}

// saves into the specified file in the same format as the input file
//PURPOSE: saves into a file in the same format as the input file
//PARAMETER: Takes in an ostream. Returns nothing.
void htable::saveTable(ostream& fout)
{
for (int i = 0; i < TSIZE; i++) {
     el_t temp;
     
        while (!table[i].isEmpty()) 
        { table[i].deleteFront(temp);
          fout <<temp<<  endl;
        }
  
}
        }
  










