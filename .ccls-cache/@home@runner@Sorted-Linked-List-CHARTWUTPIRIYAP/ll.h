#include <iostream>
#include "node.h"

using namespace std;

typedef Node* NodePtr;

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  ~LL();
  // void printListR();
};

LL::LL() {
  this->hol = nullptr;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

void LL::insert(int value) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value); // create node & put value in

  if (newPtr != nullptr) { // is space available
    previousPtr = nullptr;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != nullptr && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
    } // end while

    // insert new node at the beginning of the list
    if (previousPtr == nullptr) {
      newPtr->set_next(hol);
      hol = newPtr;
    } // end if
    else {
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_next(currentPtr);
    } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

int LL::deletes(int value) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (value == hol->get_data()) {
    tempPtr = hol;         // hold onto node being removed
    hol = hol->get_next(); // de-thread the node
    size--;

    delete tempPtr; // free the de-threaded node

    return value;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != nullptr && currentPtr->get_data() != value) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      if (currentPtr == hol)
        currentPtr = nullptr;
    } // end while

    // delete node at currentPtr
    if (currentPtr != nullptr) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      currentPtr = currentPtr->get_next();

      delete tempPtr;
      size--;
      return value;
    } // end if
  }   // end else

  return '\0';
} // end function deletes

int LL::isEmpty() {
  return hol == nullptr;
}

void LL::printList() {
  NodePtr currentPtr = hol;
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;
    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_next();
    } // end for
    cout << "NULL" << endl;
  } // end else
} // end function printList

