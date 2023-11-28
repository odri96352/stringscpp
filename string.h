class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    string(char* s, int n);
    int size();
    void print();
    char* c_str();
    void clear();
    int length();
    int max_size();
  private :
    char* list_char_;
    int size_;
};
