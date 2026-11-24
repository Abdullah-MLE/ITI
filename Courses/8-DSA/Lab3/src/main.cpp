// Factorial using stack
// selection sort, bubble sort and binary search using LL

#include <iostream>
#include <stdexcept>  // Required for runtime_error
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* pre;
  Node(int data) {
    this->data = data;
    next = nullptr;
    pre = nullptr;
  }
};

class LinkedList {
 private:
  Node* head;
  Node* tail;
  int size;

 public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
  ~LinkedList() { clear(); }

  void pushFromTail(int value) {
    // case 1: empty LL
    if (isEmpty()) {
      Node* newNode = new Node(value);
      head = tail = newNode;
      size++;
      return;
    }

    // case (2,3): 1 OR Many nodes
    else {
      Node* newNode = new Node(value);  // 1- new node
      tail->next = newNode;             // 2- tail.next = new
      newNode->pre = tail;              // 3- new.pre = tail
      tail = newNode;                   // 4- tail = new
      size++;
      return;
    }
  }

  void pushFromHead(int value) {
    // case 1: empty List
    if (isEmpty()) {
      Node* newNode = new Node(value);
      head = tail = newNode;
      size++;
      return;
    }

    // case (2,3): 1 OR Many node
    else {
      Node* newNode = new Node(value);
      head->pre = newNode;
      newNode->next = head;
      head = newNode;
      size++;
      return;
    }
  }

  void popFromTail() {
    // case 1: empty List
    if (isEmpty()) throw runtime_error("Poping from empty LL");

    // case 2: one node
    if (head == tail) {
      Node* temp = head;
      head = nullptr;
      tail = nullptr;
      delete temp;
      size--;
    }

    // case 3: many Nodes
    else {
      Node* temp = tail;
      tail = tail->pre;
      tail->next = nullptr;
      delete temp;
      size--;
    }
  }

  void popFromHead() {
    // case 1: empty List
    if (isEmpty()) throw runtime_error("Poping from empty LL");

    // case 2: one node
    if (head == tail) {
      Node* temp = head;
      head = nullptr;
      tail = nullptr;
      delete temp;
      size--;
    }

    // case 3: many Nodes
    else {
      Node* temp = head;
      head = head->next;
      head->pre = nullptr;
      delete temp;
      size--;
    }
  }

  Node* getHead() { return head; }
  Node* getTail() { return tail; }
  int Getsize() { return size; }
  bool isEmpty() { return size == 0; }

  void print() {
    if (isEmpty()) throw runtime_error("empty List");

    Node* cur = head;
    while (cur->next != nullptr) {
      cout << cur->data << " --> ";
      cur = cur->next;
    }
    cout << cur->data << endl;
  }

  void clear() {
    if (isEmpty()) return;
    Node* cur = head;
    while (cur) {
      Node* temp = cur;
      cur = cur->next;
      delete temp;
    }
    head = tail = nullptr;
    size = 0;
  }

  int& operator[](int index) {
    if (isEmpty())
      throw runtime_error("it's Empty list");

    else if (index > size)
      throw runtime_error("out of poundery");

    Node* cur = head;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur->data;
  }

  void swap(int index1, int index2) {
    if (index1 == index2) return;
    (*this)[index1] += (*this)[index2];
    (*this)[index2] = (*this)[index1] - (*this)[index2];
    (*this)[index1] -= (*this)[index2];
  }
};

class stackUsingLinkedList {
 private:
  Node* top;
  Node* head;
  int size;

 public:
  stackUsingLinkedList() {
    top = nullptr;
    head = nullptr;
    size = 0;
  }
  ~stackUsingLinkedList() { clear(); }

  void push(int value) {
    // case 1: empty LL
    if (isEmpty()) {
      Node* newNode = new Node(value);
      head = top = newNode;
      size++;
      return;
    }

    // case (2,3): 1 OR Many nodes
    else {
      Node* newNode = new Node(value);  // 1- new node
      top->next = newNode;              // 2- top.next = new
      newNode->pre = top;               // 3- new.pre = top
      top = newNode;                    // 4- top = new
      size++;
      return;
    }
  }

  int pop() {
    // case 1: empty
    if (isEmpty()) throw runtime_error("empty array");

    // case 2: one node
    else if (head == top) {
      Node* temp = head;
      int tempVal = temp->data;
      head = nullptr;
      top = nullptr;
      delete temp;
      size--;
      return tempVal;
    }

    // case 3: many Nodes
    else {
      Node* temp = top;
      int tempVal = temp->data;
      top = top->pre;
      top->next = nullptr;
      delete temp;
      size--;
      return tempVal;
    }
  }

  int peek() { return top->data; }
  bool isEmpty() { return size == 0; }
  int getSize() { return size; }

  void clear() {
    if (isEmpty()) return;
    Node* cur = head;
    while (cur) {
      Node* temp = cur;
      cur = cur->next;
      delete temp;
    }
    head = top = nullptr;
    size = 0;
  }
};

int StackFactorial(int val) {
  // initialize a stack of size N --we are using a linked list stack so no size
  // needed --
  stackUsingLinkedList stack = stackUsingLinkedList();

  // push numbers from 1 to N in the stack
  for (int i = 1; i <= val; i++) stack.push(i);

  // pop fisrt 2 elements from the stack and push
  // the Multiplication of them in the stack agin
  // get out if only one item in the stack
  while (stack.getSize() != 1) stack.push(stack.pop() * stack.pop());

  return stack.pop();
}

int recursionFactorial(int val) {
  if (val == 1) return val;
  return val * recursionFactorial(val - 1);
}

void bubbleSortLinkedList(LinkedList& LL) {
  // 1 iterate aroud the ll and swap if left is bubble
  for (int j = 0; j < LL.Getsize() - 1; j++) {
    for (int i = 0; i < LL.Getsize() - 1 - j; i++) {
      if (LL[i] > LL[i + 1]) LL.swap(i, i + 1);
    }
  }
}

void selectionSortLinkedList(LinkedList& LL) {
  // we have selected item(index), correct postion(index)
  // we will itrated and in the end of each loop we will swap

  for (int CorrectPostion = 0; CorrectPostion < LL.Getsize();
       CorrectPostion++) {
    int selectedItemIndex = CorrectPostion;
    for (int counter = selectedItemIndex + 1; counter < LL.Getsize();
         counter++) {
      if (LL[counter] < LL[selectedItemIndex]) selectedItemIndex = counter;
    }
    LL.swap(selectedItemIndex, CorrectPostion);
  }
}

int binarySearchLinkedList(LinkedList& LL, int val) {
  // we have min and max
  // at first max is size and min is 0
  // we calclute the mid = (max + min) / 2
  // we ask if mid it the item:
  //   if yes return the mid (index)
  //   if no:
  //     we ask if bigger or smaller
  //       if bigger min = mid + 1 and go from line 3 agin
  //       if smaller max = mid - 1 and go from line 3 agin
  int min = 0;
  int max = LL.Getsize() - 1;

  for (int i = 0; i < LL.Getsize(); i++) {
    int mid = (min + max) / 2;
    if (LL[mid] == val)
      return mid;
    else if (LL[mid] > val)
      max = mid - 1;
    else if (LL[mid] < val)
      min = mid + 1;
  }
  return -1;
}

int main() {
  cout << "StackFactorial(5): " << StackFactorial(5) << endl;
  cout << "recursionFactorial(5): " << recursionFactorial(5) << endl;

  LinkedList ll = LinkedList();
  ll.pushFromTail(8);
  ll.pushFromTail(65);
  ll.pushFromTail(80);
  ll.pushFromTail(566);
  ll.pushFromTail(76);
  ll.pushFromTail(999);
  ll.pushFromTail(1);
  ll.pushFromTail(23);

  ll.print();

  // bubbleSortLinkedList(ll);
  selectionSortLinkedList(ll);

  ll.print();

  cout << "binarySearchLinkedList(ll, 999): "
       << binarySearchLinkedList(ll, 8);
  return 0;
}