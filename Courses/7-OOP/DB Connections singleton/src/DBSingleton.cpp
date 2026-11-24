#include <iostream>
using namespace std;

class DBCon {
 private:
  char* DB_URL;
  char* DB_HOST;
  int DB_PORT;

  // Private constructor prevents direct object creation
  DBCon() { cout << "DB Connected!" << endl; }

 public:
  // Delete copy constructor and assignment operator to prevent cloning
  DBCon(const DBCon&) = delete;
  DBCon& operator=(const DBCon&) = delete;

  // Static method to provide global access to the single instance
  static DBCon& getInstance() {
    // Local static variable is initialized only once the first time this
    // function is called
    static DBCon instance;
    return instance;
  }

  void testConnection() { cout << "DONE!\n" << endl; }
};