class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    string(char* s, int n);

    int size();
    int length();
    void print();
    char* c_str();
    void clear();
    int max_size();
    void operator_egal(char t);
    void resize(int n);
    void resize(int n,  char c);

  private :
    char* list_char_;
    int size_;
};
