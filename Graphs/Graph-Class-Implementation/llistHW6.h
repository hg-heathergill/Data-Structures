
// =======================================================
// HW#: HW3P1 llist
// Your name: Heather Gill
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
    void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // HOW TO CALL: No argument. Returns Boolean.
 // PURPOSE: returns true if queue is empty, otherwise false
  bool isEmpty();
    
   
    // HOW TO CALL: No argument. Returns nothing.
   //PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
   // Otherwise, diplays the Elem fields horizontally sandwiched between lines of dashes.
  void displayAll();

   // HOW TO CALL: Provide the element to be added as an argument.   
   // PURPOSE: calls isEmpty and if true, adds a new Node puts newNum in the Elem field and updates count.
// Otherwise, adds a new node at the front and puts newNum in the Elem field of this new node and updates count
  void addFront(el_t newNum );
    
  //HOW TO CALL: Provide the element to be added as an argument. 
  //PURPOSE: calls isEmpty and if true, adds a new Node puts newNum in the Elem field.
// Otherwise, adds a new node at the rear and puts newNum in the Elem field of this new node and updates count
  void addRear(el_t newNum );

   // HOW TO CALL: Gives back the removed element via pass by reference. 
  // PURPOSE:calls isEmpty and if true, throws exception. 
//Otherwise, check if theres one node left and after deleted make rear and front NULL and updates count.
//If not, then deletes front node and updates count
  void deleteFront(el_t& OldNum) ;
  
    

   // HOW TO CALL: Gives back the removed element via pass by reference. 
  // PURPOSE:calls isEmpty and if true, throws exception. 
//Otherwise, check if theres one node left and after deleted make rear and front NULL and updates count.
//If not, then deletes rear node and updates count.
  void deleteRear(el_t& OldNum);


  //HOW TO CALL:Provide the element to be added as an argument 
  //and Gives back the element via pass by reference. 
  //PURPOSE: Check if it falls within the range, if not throws exception.
  //If in range, calls moveTo to find the right node and gets its elem
  
  void getIth(int I, el_t& OldNum);
    
  
  //---------------------------------------


  //HOW TO CALL: Provide the element to be removed as an argument
// PURPOSE: Checks if the value is illegal; if so, throws an exception.  
// Otherwise, checks if the node is the first or last in the list. if so, calls the appropriate functions.  
// If not, it calls moveTo to help delete the Ith node.  

  void deleteIth(int, el_t& OldNum) ;  // calls moveTo

  //HOW TO CALL: Provide the element to be added as an argument
// PURPOSE: Checks if the value is illegal; if so, throws an exception.  
// Otherwise, checks if the node is the first or last in the list; if so, calls the appropriate functions.  
// If not, it calls moveTo to help add the Ith node.  

  void insertIth(int, el_t newNum);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  //   (because of pointers we need to write this)
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist) (because of pointers
  //   we need overloading)
  llist& operator=(const llist&); 

};
