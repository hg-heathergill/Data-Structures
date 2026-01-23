

// ====================================================
//HW#: HW3P1 llist
//Your name: Heather Gill
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

#include<iostream>
#include"llistHW7.h" 
using namespace std;

//PURPOSE:Initalize Front and Rear to both start with NULL and Count with 0.
llist::llist()
{ //cout << "... in llist constructor..." << endl; 
  Front =NULL;
   Rear =NULL;
  Count =0;
}
//PURPOSE: while the queue is not empty, call deleteFront repeatedly to delete all nodes.
llist::~llist()
{ //cout << ".... in llist destructor..." << endl; 
  el_t temp; //deletefront placement since it passes a element to the function.
    while(!isEmpty())
{
    deleteFront(temp);
}
}
//PURPOSE:return true if Front and Rear are both pointing to NULL and Count is 0.
//PARAMETER:No argument. Returns Boolean.
bool llist::isEmpty()
{
if(Front == NULL && Rear == NULL && Count ==0 ) return true; else return false;
}
 // be sure to check all 3 data members

// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
// Otherwise, diplays the Elem fields horizontally sandwiched between lines of dashes.
void llist::displayAll()
{ 
  if (isEmpty()) cout << "[ empty ]" << endl; //empty
  else // displays Elem fields
    {
      Node *P;  // go throughs all of queue elem fields to display
      P = Front;
      cout << "[";
    while (P != NULL)
    {	cout << " " << P->Elem;
        P = P->Next;
        
    }   
     cout <<" ]" <<endl;
    }
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!

//PURPOSE: calls isEmpty and if true, adds a new Node puts newNum in the Elem field.
// Otherwise, adds a new node at the rear and puts newNum in the Elem field of this new node and updates count
//PARAMETER: the element NewNum to be added in the Elem field
void llist::addRear(el_t NewNum)
{
  if (isEmpty()) //special case for first node
{
    Front =new Node;
    Rear =Front;
    Rear->Elem=NewNum;
    Rear-> Next=NULL;
    Count++;
   
}
    else // regular case for other nodes
    {
        Rear->Next= new Node;
        Rear= Rear->Next;
        Rear->Elem= NewNum;
        Rear->Next=NULL;    
       Count++;

    }

 } // comment the 2 cases

  
//PURPOSE:calls isEmpty and if true, adds a new Node puts newNum in the Elem field and updates count.
// Otherwise, adds a new node at the front and puts newNum in the Elem field of this new node and updates count.
// Parameters: the element NewNum to be added in the Elem field
void llist::addFront(el_t NewNum)
{ 
if (isEmpty()) //special case for first node
{
  Front =new Node;
  Rear =Front;
  Rear->Elem=NewNum;
  Rear-> Next=NULL;
  Count++;

}
else // regular case for other nodes
{
  Node *T;
T = new Node;
T->Elem = NewNum;
T->Next = Front;
Front =T;
Count++;

}

} // comment the 2 cases

//PURPOSE:calls isEmpty and if true, throws exception. 
//Otherwise, check if theres one node left and after deleted make rear and front NULL and updates count
//If not, then deletes front node and updates count.
// Parameters: the deleted element OldNum to be returned by reference
void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty()) throw Underflow(); //empty
	
    else if(Front == Rear) // only one node
    { 
     OldNum = Front->Elem;
        delete Front;
        Rear= NULL;
        Front =NULL;
            Count--;

    }
    else //regular case
    {
       OldNum = Front->Elem;
        Node *Second; //temp placement for front
        Second= Front ->Next;
        delete Front;
        Front=Second;
        Count--;
    }


 } // comment the 3 cases

//PURPOSE:calls isEmpty and if true, throws exception. 
//Otherwise, check if theres one node left and after deleted make rear and front NULL and updates count
//If not, then deletes rear node and updates count
//PARAMETER:the deleted element OldNum to be returned by reference
void llist::deleteRear(el_t& OldNum)
{
 if (isEmpty()) throw Underflow();  //empty

 else if(Front == Rear) // only one node
 {
     OldNum = Rear->Elem;
        delete Rear;
        Rear= NULL;
        Front =NULL;
        Count--;
 }

else    //regular case
    {
Node *P;
P= Front;
OldNum = Rear->Elem;
while(P->Next!= Rear)
{
	P=P->Next;
}
delete Rear;
Rear = P;
Rear->Next = NULL;
Count--;
    }

} // comment the 3 cases

//PURPOSE:Check if it falls within the range, if not throws exception.
//If in range, calls moveTo to find the right node and gets its elem
//PARAMETER:The elem of node and elem to be returned by reference
void llist::getIth(int I, el_t& OldNum)
{ Node* temp;
  // calls moveTo to move to Ith if I is within 1 and Count
  //  Otherwise throw an exception
  if(I >= 1 && I<= Count)
   {moveTo(I, temp);
   OldNum = temp->Elem;
 
   }
  else
  {
    throw OutOfRange(); 
  }
} 

// Utility Function to move a pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ temp = Front; // start at front
  // moves temp J-1 times to go to the Jth node (>=1 and <= Count is assumed)   
  // for ( int K = ... ) temp = temp->Next;
  for (int K = 1; K <= J-1; K++)  // for J-1 times
{ temp = temp->Next; }

}



/* --- harder ones for case 2 and 3 follow -- */


// PURPOSE: Checks if the value is illegal; if so, throws an exception.  
// Otherwise, checks if the node is the first or last in the list. if so, calls the appropriate functions.  
// If not, it calls moveTo to help delete the Ith node.   
//PARAMETER:The elem of node and elem to be returned by reference
void llist::deleteIth(int I, el_t& OldNum)
{ 
if(I < 1 || I > Count)
{
    throw OutOfRange(); 
}
else if (I == 1) 
{
    deleteFront(OldNum);
}
else if (I == Count)
 {
    deleteRear(OldNum);
}

else
{
  Node* temp;
  Node* P;
  moveTo(I-1, temp);
  moveTo(I+1, P);
  Node* Q;

  Q= temp->Next;
  OldNum =Q->Elem;
  temp->Next = P;  
  delete Q;
Count--;

}

} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

// PURPOSE: Checks if the value is illegal; if so, throws an exception.  
// Otherwise, checks if the node is the first or last in the list; if so, calls the appropriate functions.  
// If not, it calls moveTo to help add the Ith node.  
//PARAMETER: The elem of node and elem to be returned by value
void llist::insertIth(int I, el_t newNum)
{
if(I < 1 || I > Count +1)
{
    throw OutOfRange(); 
}
else if (I == 1) 
{
    addFront(newNum);
}
else if (I == Count+1)
 {
    addRear(newNum);
}

else
{
  Node* temp;
  Node* P;
  moveTo(I-1, temp);
  moveTo(I, P);
  Node* Q;
  Q = new Node;
  Q->Elem = newNum; 
  Q->Next =P;
  temp->Next= Q;
Count++;

}
}

// must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Is to copy the constructor of an llist object. Making a new list as a copy of an existing one.
//PARAMETER: Pass of the llist object by pass by reference
llist::llist(const llist& Original)
{ // use my code
//  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with 
    //  operator= above. To do this,
   //  copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
 Node* P;  // local pointer for OtherOne
        P = Original.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
    //  Nothing to return because this is a constructor. // return the result unconditionally.  Note that the result is returned by reference.


//PURPOSE: Is to overload the '=' operator to copy one llist object to another
//PARAMETER: Pass of the llist object by pass by reference
llist& llist::operator=(const llist& OtherOne)
{ 
      el_t x;
     // First make sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
                   this->deleteRear(x);       
 // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} // use my code
