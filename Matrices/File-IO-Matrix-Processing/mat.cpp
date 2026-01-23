
//---------------------------------------
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix 
// Compiler: g++
// Your name: Heather Gill
//--------------------------------------

//Purpose:Demonstrates the uses of 3x4 vector matrix
//Overall Algorithm/Design:Takes a file from user and sort the data in a nice and correct order in a 3x4 vector  matrix then saves it into another file


// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VL = 3; // table entry vector length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{ 
  // use a formula to convert a to 0, b to 1, c to 2 etc.
 x= x - 'a';
  return x;

}// end of convert 
// this reads the input file into the matrix table
void readTable()
{  int row, col;
   char col_c; // column name 
   ifstream fin ("lines.txt", ios::in);

   // Read in the file into T
   while (fin >> row)  // per row
     { vector<char> V;
       fin >> col_c; col = convert(col_c);  // to a slot number
       char c; // one char from the file
       
for (int i = 0; i < VL; i++)  // Reads the chars into the vector
      {
    {
      fin >> c;
      V.push_back(c); 
    }
 //  Put the vector in T[row][col]
    T[row][col]= V;
  
     }//end of while

}// end of readTable

}

// display the vector nicely to the outstream
void showVector(vector<char> v, ostream& ost)
{if (v.size() == 0)  // empty entry will be dashes
    for (int i = 1; i <= VL; i++) ost << "- ";
  else
    { 
      // show the content of v separated by blanks
      for(int i=0; i <v.size(); i++)
      {
        ost << v[i] << " ";
      }
    }
}// end of showVector


// display the matrix
void displayTable()
{
  // display T nicely labeled with row numbers
  //    by calling showVector with cout
  //    for each column
  for (int r = 0; r < R; r++)
    {    cout << r << ":";
      for (int c = 0; c < C; c++)
	{ showVector(T[r][c], cout);
	  cout << "|"; }
      cout << endl;
    }   
}// end of displayTable

// save the matrix to the output file
void saveTable()
{
   ofstream fout ("table.txt", ios::out);
  //    output T nicely labeled with row numbers
  //    by calling showVector with fout
  //    for each column
 for (int r = 0; r < R; r++)
    {    fout << r << ":";
      for (int c = 0; c < C; c++)
	{ showVector(T[r][c], fout);
	  fout << "|"; }
      fout << endl;
    }   
}//end of saveTable

int main()
{
  cout << "reading from lines.txt" << endl;
  readTable(); 
  displayTable();
  cout << "saving the table in table.txt" << endl;
  saveTable();

}//the end
