class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    string(char* s, int n);
    int size();
    void print();
  private :
    char* list_char_;
    int size_;
};
