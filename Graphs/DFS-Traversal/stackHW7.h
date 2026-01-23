
// =======================================================
// HW#: HW1P1 stack
// Your name: Heather Gill
// Compiler:  g++ 
// File type: headher file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef char el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
 class Overflow{};
class Underflow{};

  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide a holder (elem) for the element (pass by ref)
  void topElem(el_t&);
  
  // ** Must add good comments for each function - See Notes2A

  //PURPOSE: returns true if stack is empty else false (empty means top is -1)
  bool isEmpty();

  //PURPOSE:checks top and returns true if full, else false (full means top is MAX-1)
  bool isFull();

  //PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
// Otherwise, diplays the elements vertically sandwiched between lines of dashes.
  void displayAll();

  //PURPOSE:pops all elements from the stack until 
// it is empty using a while loop
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

