


// ================================================
// HW#: HW6 dgraph client 
// Name: Heather Gill
// File type: .cpp (tester)
// ================================================

#include <iostream>
#include "dgraphHW6.h"
#include <stdlib.h>
using namespace std;
 // includes

// comments
int main()
{ 
    //0.Declare dgraph object
  dgraph G;
    //1.fillTable()
        G.fillTable();
    //2.displayGraph()
    G.displayGraph();
   
   char choice;
   char answer = 'Y'; 
  int degree;

    //while (the user does not want to stop)
while (answer == 'Y') {
    try {
        cout << "Which vertex? ";
        cin >> choice;


    degree=G.findOutDegree(choice);
    cout << degree << " edges comes out to:"<<endl;

      slist l1 = G.findAdjacency(choice);  
    l1.displayAll();
    

        cout << "Again? (Y/N)" << endl;
        cin >> answer;
    }
    catch (dgraph::BadVertex) { // Assuming BadVertex is a defined exception
        cout << "Error: Does not exist " << endl;
        cout << "Again? (Y/N)" << endl;
        cin >> answer;
    }
  
}
 
}   
    //a.the user will specify which vertex     
    //b.findOutDegree of the vertex and display the result
    //b.findAdjacency of the vertex and display the result (see Hint)
    //c.catch exception to display error mesg but do not exit
    //end of while

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
