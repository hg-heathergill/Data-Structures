
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Heather Gill
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"
using namespace std;


//Purpose of the program: evaluate postfix expressions entered by the user using a stack
//Algorithm: The program will go through a while loop to evaluate user input, 
//and if any problems occur, they will be caught and the program will stop; 
//otherwise, it will find the result of the input

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result =0;
  
  while (expression[i] != '\0') // til the end of the expression
    {
     try
       {
	        item = expression[i];  // current char
	 	 // ** do all the steps in the algorithm given in the notes
         //    do not forget to throw an error message for invalid items
         //    do not forget that 54- is 5-4   
       if(item >= '0' && item <= '9') // Making sure its a number 0-9
          { 
            postfixstack.push(item-'0');
          }

       else if(item == '+' || item == '-' || item == '*') // Dealing with the operators
    {
            postfixstack.pop(box1);
            postfixstack.pop(box2);

       if(item == '+')
         {
            postfixstack.push(box2+box1);
         }

       else if(item == '-')
         {
            postfixstack.push(box2-box1);
         }
       else
         {
            postfixstack.push(box2*box1);
         }
      } 

        else
          {
             throw "invalid item";
          }
      postfixstack.displayAll();

       } // this closes try
     
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	      { cerr << "the expression was too long";  exit(1);}
      catch (stack::Underflow)
	      {cerr << "too few operands/numbers";  exit(1); }
      catch (char const* errormsg ) // for invalid item case
	      {cerr << "Error has occurred:" << errormsg;  exit(1); }

      // go back to the loop after incrementing i
      i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
   postfixstack.pop(result);
   cout << "The result is: "<<endl;
   cout<< result<<endl;
 // If anything is still left on the stack, an incomplete expression 
 // was found so also inform the user.
   if(!postfixstack.isEmpty())
      {
	      cout << " incomplete experssion" <<endl;
      }

}// end of the program
