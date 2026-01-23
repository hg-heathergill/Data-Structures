

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Heather Gill
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph and stack
#include "dgraphHW7.h"
#include "stackHW7.h"
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
char A = 'A';  
char temp;
  int visted=1;
  dgraph G;
  stack S;
  
  try{
    G.fillTable();
   G.displayGraph();

cout << "Removed "<<A <<" from stack" <<endl;
G.visit(visted, A);  // pass in the visit number
  cout << "Vist " << A << " as " << visted<< endl;

   int convert= A - 'A';

slist l1 = G.findAdjacency(A);  
    cout << "...Pushing";
    l1.displayAll();
while(!l1.isEmpty())
    {
  
    l1.deleteRear(A);
    S.push(A);

  }   
S.displayAll();

while (!S.isEmpty())
{
 S.pop(temp);
cout << "Removed "<<temp <<" from stack" <<endl;

if(!G.ismarked(temp))

{
    visted++;
  G.visit(visted, temp);  
  cout << "Vist " << temp << " as " << visted<< endl;
slist l1= G.findAdjacency(temp);
  if(l1.isEmpty()) 
  {
    cout << "Deadend reached- backup"<<endl;
    
  }
  else
  {
  slist l1= G.findAdjacency(temp);
  cout << "...Pushing";
    l1.displayAll();
while(!l1.isEmpty())
    {
  
    l1.deleteRear(temp);
    S.push(temp);

  }
  }
}
else
cout << temp << " had been visted already -backup" <<endl;
S.displayAll();
}
G.displayGraph();
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 
  // Make sure all couts are included and that they look nice.
  
}
catch (dgraph::BadVertex) { // Assuming BadVertex is a defined exception
        cout << "Error: Does not exist " << endl;
}
}