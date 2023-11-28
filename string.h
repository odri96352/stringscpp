class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    int size();
    void print();
  private :
    char* list_char_;
    int size_;
};
