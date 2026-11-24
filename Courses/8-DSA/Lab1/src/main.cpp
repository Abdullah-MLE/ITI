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

int main() {
  LinkedList list;
  // ========== Linked List =============
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

  return 0;
}