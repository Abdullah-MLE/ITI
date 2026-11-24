#include <iostream>

#include "./DBSingleton.cpp"
using namespace std;

int main() {
  // Access the single instance and call member functions
  DBCon& db1 = DBCon::getInstance();
  db1.testConnection();

  // Subsequent calls return a reference to the exact same instance
  DBCon& db2 = DBCon::getInstance();
  return 0;
}