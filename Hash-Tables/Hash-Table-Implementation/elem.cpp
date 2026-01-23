
#include "elem.h"

//PURPOSE: to create a blank object
// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
 // initialize other parts to be blanks
  artist = "";// can change this to title, etc.
  //** add 2 more pieces of info here based on your plan!!!
  songName = "";
  released = -1;
}

//PURPOSE: to create an initialized object
// initializing constructor to create an el_t object using arguments
el_t::el_t(int akey, string anArtist,string aSong,int aDate)
{
  key = akey;
  artist=anArtist;  //  initialize other parts to be the arguments
  songName=aSong;
  released= aDate;
}

// ONLY the key part should be available to the user of this class
// PURPOSE: to return the key part of the object
//PARAMETER: No argument. Returns int.
int el_t::getkey()
{
  return key;
}

// ONLY the key part should be available to the user of this class 
 // PURPOSE: to set the key part from the object
//PARAMETER: Take in a int element. Returns nothing.
void el_t::setkey(int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (this->key == OtherOne.key) return true; else return false;
}

// based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (this->key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "," << E.artist << ","  << E.songName << "," << E.released;// display other parts of E in a nice way
  return os;  
}  
// if you make it come out just like the input file, Saving to a file will
// be easier!
