class DBCon {
 private:
  char* DB_URL;
  char* DB_HOST;
  int DB_PORT;

  DBCon();
  DBCon(DBCon& old_obj);

 protected:
 public:
  ~DBCon();

  void testConnection() {}
};