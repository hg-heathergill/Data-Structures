

// =======================================================
// HW#: HW6 dgraph
// Name: Heather Gill
// File Type: Header File
// ==================================================

#include <iostream>
#include "slistHW7.h"
using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 26;   // for the size of the graph table for A-Z

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex {};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.
// HOW TO CALL: No argument. Returns nothing.
 // PURPOSE:read from the input file and fill GTable
  void fillTable();  

// HOW TO CALL: No argument. Returns nothing.
 //PURPOSE: displays in an easy to read table format 
  void displayGraph(); 

// HOW TO CALL: Take in a char element. Returns an integer of the degree.
//PURPOSE: returns the out degree of a given vertex - may throw BadVertex
  int findOutDegree(char);  
// HOW TO CALL : Take in a char element. Returns the link list of adjacency
// PURPOSE:returns the adjacency list of a given vertex - may throw BadVertexx
  slist findAdjacency(char);  

//HOW TO CALL : Take in a char and int element. Returns nothing
// PURPOSE:will enter the given visit number for a given vertex - may throw BadVertexx
  void visit(int ,char);

// HOW TO CALL : Take in a char element. Returns bool
// PURPOSE:will which returns true if a given vertex was already visited - may throw BadVertexx
  bool ismarked(char); 

};


