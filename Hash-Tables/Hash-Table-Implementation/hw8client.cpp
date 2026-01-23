

//============================================
// HW#: HW8 hashing client
// Name: Heather Gill
// File type: client hw8client.cpp (tester)
//===========================================

#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//** Must add an explanation of what this App should be used for. 
int main()
{
  
  cout << "Keep track of your favorite songs" <<endl;// cout an explanation of what this App should be used for. 

  htable HT;
  string fname; // file name - get the file name here
            // in the client in case the way I get them is application dependent

  cout << "What is the input file? (.txt file)";
  cin >> fname;
  
  ifstream fin (fname.c_str(), ios::in);
  HT.fillTable(fin);
  // make sure some of elements collide. 
  HT.displayTable();
  cout << endl;
  fin.close();
  
  //I cannot open fout inside a case 
  ofstream fout ("newout.txt", ios::out);  


  int selection;
  do {

  cout << "MENU: ---- " << endl; 
  cout << "1 Add an element" << endl; 
  cout << "2 Find an element" << endl;
  cout << "3 Delete an element" << endl;
  cout << "4 Display the table" << endl;
  cout << "5 Save the table to a file at the end" << endl;    
  cout << "6 Quit" << endl;
  cin >> selection;

      int thekey;
      string theArist;
      string thesong;
      int theDate;
      el_t theelement;
      int s;
      
    switch (selection) {

    case 1:  // Add and indicate the slot
      cout << "What is the key to add?  ";
      cin >> thekey;
      cin.ignore();
      cout << "What is the artist name?  " ;
       getline(cin ,theArist);
      cout << "What is the song name?  " ;
      getline(cin ,thesong);
    cout << "When was the song realsed?  " ;
    cin >>theDate;
  //  Here get two more pieces of info
	//  Create the element with all the info using the 2nd constructor
      theelement = el_t(thekey,theArist,thesong,theDate);
      s = HT.add(theelement);
      cout << "Added the element in slot " << s << endl;
      break;

    case 2: // Find and indicate the element
      cout << "What is the key to find? ";
      cin >> thekey;
      theelement =  HT.find(thekey); // find based on thekey
      // if the element has -1 as the key, state "Not found!" else
      if(theelement.getkey() == -1)
      {
        cout << "Not found!" <<endl;
        break; 
      }
      else 
      {
      cout << "Found this:" << endl;
     cout << "[" << theelement<< "]" << endl;
      break;      
      }
    case 3: // Delete and indicate the slot
      cout << "What is the key to find and delete? ";
      cin >> thekey;
      s  =  HT.deleteIt(thekey); // find and delete it based on thekey
      if (s == -1) cout << "Not found!" << endl; else
      cout << "Found it and deleted it from slot:" << s << endl;
      break;      

    case 4: // Display the table
      cout << "The current contents are: " << endl;
      HT.displayTable();
      break;

    case 5: // Save in the same format as input file
      // the output file is newout.txt 
      HT.saveTable(fout);
      cout << "Saved the updated table in newout.txt" << endl;
      fout.close();
      break;

    default:
      cout << "bye" << endl;
    }
  }
  while (selection != 6);

 }
