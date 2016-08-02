/*
 * @file: linkedlist.h
 * Definition of templated class LinkedList
 * Implementation of List A.D.T.
 * @C - Galaxy Express Software
 * @C - Nibblobian Council
 * 
 * Version 16.1.1
 */

/* __________________
  /                  \
  | LinkedList Class |
  \__________________/
   
    Purpose: Implements a List ADT using a dynamically allocated 
        linked list to store the elements of the list.

    Error Handling: Whenever a function is given invalid parameter values 
        the message "!!-- ERROR : PANIC in LINKEDLIST.foo()" and an 
        explanation is displayed as in the tester output. 
        The list should remain unchanged. 
        If such function returns a value this value is 
        specified in the function description.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


// --------------- Forward Declarations ---------------
template <typename T>                  // the Node class
class Node;

template <typename T>                  // the LinkedList class
class LinkedList;

template <typename T>                 // a friend function for output
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& xlist);



/* ----------------------------------------
   Class 'Node', to store data values of the LinkedList
*/
template <typename T>
class Node
{
public:
  T m_data;            // Data to be stored
  Node<T>* m_next;     // Pointer to the next element in the list


  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // ---INLINE---
  Node() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // ---INLINE---
  Node(const T& x, Node<T>* p) 
             : m_data(x), m_next(p) {}

};  // class Node



/* ----------------------------------------
   Class 'LinkedList', the actual LinkedList.
*/
template <typename T>
class LinkedList
{

	/* -----------------
	   Member Variables
	*/
    Node<T>* m_head;     // Pointer to the head of the List
	int m_size;          // The number of elements in the LinkedList

public:

    // Purpose: Default constructor
    // Postconditions: head pointer set to NULL
    //                 size of the list set to 0
    // ---INLINE---
  LinkedList() : m_head(NULL), m_size(0) {}


    // ----------
    // ---- Big-3 Member Functions ---
    // ----------

    // Purpose: Destructor
    // Postconditions: Dynamic variables used for the list is de-allocated,
  ~LinkedList();

    // Purpose: performs a deep copy of the data from rhs into this linkedlist
    // Parameters: rhs is linked list to be copied
    // Returns: *this
    // Postconditions: this list contains same data values (in the same order)
    //     as are in rhs; any memory previously used by this list has been
    //     deallocated.
  const LinkedList<T>&  operator= (const LinkedList<T>& rhs);

    // Purpose: copy constructor
    // Parameters: rhs is the LinkedList that is to be copied
    // Postconditions: this list contains same data values (in same order) 
    //      as in rhs.
  LinkedList(const LinkedList<T>& rhs);
  

    // ----------
    // ---- Basic Accessor Operations ---
    // ----------

    // Purpose: accessor function for the current # data values in the list
    // Returns: current size of the list
  int size() const;
    
    // Purpose: determines whether the list is empty
    // Returns: 'true' if list is empty; 'false' otherwise
  bool isEmpty() const;

    // Purpose: Get a pointer to the first element node
    // Returns: pointer to the first node in the list; 
    //     returns NULL if the list is empty
  Node<T>* getFirstPtr() const;

    // Purpose: accessor function for last element node
    // Returns: pointer to the last element's node in the list; 
    //     returns NULL if list is empty
  Node<T>* getLastPtr();

    // Purpose: accessor function for a node in the list
    // Returns: pointer to the node at the i'th position in the list; 
    //     returns NULL if no such element exists.
  Node<T>* getAtPtr(int i);



    // --------
    // ---- Basic Mutator Operations ---
    // --------

    // Purpose: effectively "empties" the list, 
    //          Turn the list into an empty list.
    // Postconditions: ALL dynamically allocated memory for elements is deallocated
  void clear();

    // Purpose: puts the data x in the front of the list 
    // Parameters: x is data value to inserted
    // Postconditions: x is the first element of the list
  void insert_front(const T& x);

    // Purpose: puts the data value x at the position pointed by pos
    // Parameters: x is data value to inserted
    //     pos pointer to the position to insert x at.
    // Preconditions: pos is a pointer to a node in this list.
    // Postconditions: x is inserted at the position pointed by pos
  void insert(const T& x, Node<T>* pos);

    // Purpose: removed the element in the position pointed by pos
    // Parameters: pos pointer to the position to remove.
    // Preconditions: pos is a pointer to a node in this list.
    // Postconditions: position pointed by pos is removed from the list
  void remove(Node<T>* pos);



    // --------
    // ---- Complex Operations ---
    // --------

    // Purpose: determines whether this list is identical to rhs list in
    // terms of data values and their order in the list
    // Parameters: rhs is list to be compared to this list
    // Returns: true if lists are identical; otherwise, false
  bool operator== (const LinkedList<T>& rhs) const;

    // Purpose: determines whether x is in the list
    // Parameters: x is data value to be found
    // Returns: a pointer to the node of x in the list; 
    //     otherwise, NULL
  Node<T>* find(const T& x);    

    // Purpose: appends two lists
    // Parameters: xlist, a list to append to the end of 'this' list
    // Postconditions: elements of alist are appended to 'this' list 
  void append(const LinkedList<T>& xlist);


  // --------
  // ----- Complex Accessors Operations ----- 
  // --------
  // Purpose: prints the LinkedList
  friend std::ostream& operator<< <> (std::ostream& out, 
                                      const LinkedList<T>& xlist);
        
}; // of class LinkedList



// ---------------  Utility Function for Printing
// BONUS BONUS BONUS !!!!!!!
// Purpose: prints a LinkedList
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& xlist)
{
  out << "[ ";
  const Node<T>* p = xlist.m_head;
  while ( p != NULL ){
    out << p->m_data << ", ";
    p = p->m_next;
  } 
  out << "]"; 
  
  return out;
}


#include "linkedlist.hpp"
#endif
