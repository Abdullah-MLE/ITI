#include <iostream>
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
    if (isEmpty()) {
      cout << "Poping from empty LL!";
      return;
    }

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
    if (isEmpty()) {
      cout << "Poping from empty LL!";
      return;
    }

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
    if (isEmpty()) {
      cout << "empty List!" << endl;
      return;
    }
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
    if (isEmpty()) {
      cout << "it's Empty list!!!!" << endl;
    } else if (index > size) {
      cout << "out of poundery!!!!!" << endl;
    }
    Node* cur = head;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur->data;
  }

  // ======= not modifiyed for pre pointer yet =============

  /*
  void InsertAfterValue(int data, int afterData) {
    Node* cur = head;
    while (cur->data != afterData) cur = cur->next;
    Node* newNode = new Node(data);
    newNode->next = cur->next;
    if (tail == cur) tail = newNode;  // LL one node
    cur->next = newNode;

    size++;
  }

  void InsertBeforeValue(int data, int beforeData) {
    if (isEmpty()) return;

    if (head->data == beforeData) {  // case if first node is the target
      pushFront(data);
      return;
    }

    Node* pre = head;
    Node* cur = head->next;
    while (cur->data != beforeData) {
      cur = cur->next;
      pre = pre->next;
    }

    Node* newNode = new Node(data);
    newNode->next = pre->next;
    pre->next = newNode;

    size++;
  }
  */
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
    if (isEmpty()) {
      cout << "empty array!!!!!!" << endl;
      return -1;
    }

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

class queueUsingLinkedList {
 private:
  Node* front;
  Node* rear;
  int size;

 public:
  queueUsingLinkedList() {
    front = nullptr;
    rear = nullptr;
    size = 0;
  }
  ~queueUsingLinkedList() { clear(); }

  void enqueue(int value) {
    // case 1: empty queue
    if (isEmpty()) {
      Node* newNode = new Node(value);
      front = rear = newNode;
      size++;
      return;
    }

    // case (2,3): 1 OR Many node
    else {
      Node* newNode = new Node(value);
      front->pre = newNode;
      newNode->next = front;
      front = newNode;
      size++;
      return;
    }
  }

  int dequeue() {
    // case 1: empty List
    if (isEmpty()) {
      cout << "Poping from empty LL!";
      return -1;
    }

    // case 2: one node
    else if (front == rear) {
      int poped = rear->data;
      Node* temp = rear;
      front = nullptr;
      rear = nullptr;
      delete temp;
      size--;
      return poped;
    }

    // case 3: many Nodes
    else {
      int poped = rear->data;
      Node* temp = rear;
      rear = rear->pre;
      rear->next = nullptr;
      delete temp;
      size--;
      return poped;
    }
  }

  int peek() { return front->data; }
  int getRear() { return rear->data; }
  bool isEmpty() { return size == 0; }
  int grtSize() { return size; }
  void clear() {
    if (isEmpty()) return;
    Node* cur = front;
    while (cur) {
      Node* temp = cur;
      cur = cur->next;
      delete temp;
    }
    front = rear = nullptr;
    size = 0;
  }
};

class queueUsingArray {
 private:
  int* arr;
  int front;
  int rear;
  int size;
  int cap;

 public:
  queueUsingArray(int cap) {
    this->cap = cap;
    arr = new int[cap];
    size = 0;
    front = rear = -1;
  }

  ~queueUsingArray() {
    delete arr;
    arr = nullptr;
  }

  void enqueue(int value) {
    // case 1: Empty Array
    if (isEmpty()) {
      front = rear = 0;
      arr[rear] = value;
      size++;
    }

    // case 2: full array
    else if (isFull()) {
      cout << "cant enqueue in full queue!!!!!" << endl;
    }

    // case 3: still place
    else {
      rear = (rear + 1) % cap;  // move rear
      arr[rear] = value;        // append in the array
      size++;
    }
  }

  int dequeue() {
    // case 1: Empty Array
    if (isEmpty()) {
      cout << "cant dequeue from empty queue!!!!!" << endl;
      return -1;
    }

    // case 2: one element
    else if (rear == front) {
      int temp = arr[front];
      rear = front = -1;
      size = 0;
      return temp;
    }

    // case 2: more than 1 element
    else {
      int temp = arr[front];
      front = (front + 1) % cap;  // move front
      size--;
      return temp;
    }
  }

  int peek() { return arr[front]; }
  int getRear() { return arr[rear]; }
  bool isFull() { return cap == size; }
  bool isEmpty() { return front == -1; }
  int getSize() { return size; }
};

int main() {
  LinkedList list;
  stackUsingLinkedList stack;
  queueUsingLinkedList queue;
  queueUsingArray arrQueue{5};

  // ======== queue using array ==============
  /*
  cout << "arrQueue.isEmpty(): " << arrQueue.isEmpty() << endl;

  cout << "adding 5 elements: " << endl;
  arrQueue.enqueue(1);
  arrQueue.enqueue(2);
  arrQueue.enqueue(3);
  arrQueue.enqueue(4);
  arrQueue.enqueue(5);
  arrQueue.enqueue(6);

  cout << "arrQueue.peek(): " << arrQueue.peek() << endl;
  cout << "arrQueue.getSize(): " << arrQueue.getSize() << endl;

  cout << "removing 3 elements: " << endl;
  cout << "arrQueue.dequeue(): " << arrQueue.dequeue() << endl;
  cout << "arrQueue.dequeue(): " << arrQueue.dequeue() << endl;
  cout << "arrQueue.dequeue(): " << arrQueue.dequeue() << endl;

  cout << "arrQueue.peek(): " << arrQueue.peek() << endl;
  cout << "arrQueue.getSize(): " << arrQueue.getSize() << endl;
  */

  // ======== queue using LL ==============
  /*
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);

  cout << "queue.peek(): " << queue.peek() << endl;
  cout << "queue.dequeue(): " << queue.dequeue() << endl;
  cout << "queue.getRear(): " << queue.getRear() << endl;
  */

  // ========== stack =============
  /*
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  cout << stack.peek();

  stack.pop();

  cout << stack.peek();
  */

  // ========== Linked List =============
  /*
  list.pushFromHead(10);
  list.pushFromHead(20);
  list.pushFromHead(30);
  list.pushFromHead(40);

  // // 40 --> 30 --> 20 --> 10
  list.print();

  list.pushFromTail(1);
  list.pushFromTail(2);
  list.pushFromTail(3);
  list.pushFromTail(4);

  list.print();

  list.popFromTail();

  list.print();

  list.popFromHead();

  list.print();
  */

  return 0;
}