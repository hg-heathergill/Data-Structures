
//======================================================
// HW#: HW6 dgraph
// Name: Heather Gill
// File Type: .cpp
//========================================================

#include <iostream>
#include <fstream>
#include <string>
#include "dgraphHW7.h"
using namespace std;
 //PURPOSE: initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // - need a loop
 // initialize countUsed to be 0
dgraph::dgraph()

{
  for (int i = 0; i < SIZE; i++)
   {
            Gtable[i].vertexName = '\0';  // Blank
            Gtable[i].visit = 0;
  }
   countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// If we do not do this, will the llist destructor be called automatically? Try it.
{
}
 
 // PURPOSE:read from the input file and fill GTable
void dgraph::fillTable()  // Be sure to read from a specified file
{
    string fname;
    cout << "Enter a file name: ";
    cin >> fname;
    ifstream fin(fname.c_str(), ios::in); 
    char X;

    while (fin >> Gtable[countUsed].vertexName)  
    { 
        fin >> Gtable[countUsed].outDegree;

        for (int i = 0; i < Gtable[countUsed].outDegree; i++) 
        {
            fin >> X;
            (Gtable[countUsed].adjacentOnes).addRear(X);  
        }

        countUsed++; 
    }

}

 //PURPOSE: displays in an easy to read table format 
void dgraph::displayGraph() // be sure to display
// in a really nice table format -- all columns but no unused rows and include the total number of edges at the very top (you have to sum it up)
// Make use of countUsed
// you will have to use a linked list function displayAll.
  
{
    int total;
    {
      for (int i = 0; i < countUsed; i++)
      {
        total+=Gtable[i].outDegree;
      }
    }

//cout << "The number of edges is:  " << total<<endl;
//cout << "--------------------" <<endl;
cout << "Out Visit Adj" <<endl;
cout << "--------------------" <<endl;
    for (int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName<< " " << Gtable[i].outDegree << "\t" << Gtable[i].visit << " ";
        (Gtable[i].adjacentOnes).displayAll();
     
    }
}
//PARAMETER:The char V to find the degree. Returns integer.
//PURPOSE: returns the out degree of a given vertex - may throw BadVertex
int dgraph::findOutDegree(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
 // Make use of coutUsed
 int convert;
 convert= V - 'A';
 
 if 
 (convert < 0 || convert >= countUsed) 
 {
        throw BadVertex(); 
 }
else
{
  return Gtable[convert].outDegree;
}
}

//PARAMETER:The char V to find the adjacency. Returns link list.
// PURPOSE:returns the adjacency list of a given vertex - may throw BadVertexx
slist dgraph::findAdjacency(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
  // Make use of coutUsed
  
   int convert;
 convert= V - 'A';
 if 
 (convert < 0 || convert >= countUsed) 
 {
        throw BadVertex(); 
 }
else
{
 return Gtable[convert].adjacentOnes; 
}

}

//PARAMETER:The char V to find the vist and int number to assign . Returns nothing.
// PURPOSE:will enter the given visit number for a given vertex - may throw BadVertexx
  void dgraph::visit(int number ,char V)
  {
    int convert;
 convert= V - 'A';
 if 
 (convert < 0 || convert >= countUsed) 
 {
        throw BadVertex(); 
 }

 else 
 { 
  Gtable[convert].visit = number;

 }

  }
//PARAMETER:The char V to check if visted . Returns nothing.
// PURPOSE:will which returns true if a given vertex was already visited - may throw BadVertexx
  bool dgraph::ismarked(char V)
  {
    int convert;
 convert= V - 'A';

 if 
 (convert < 0 || convert >= countUsed) 
 {
        throw BadVertex(); 
 }
    else if(Gtable[convert].visit != 0)
    {
      return true; 
    }
    else 
    {
      return false;
    }
  }
