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
    int max_size();
    void resize(int n);
    void resize(int n,  char c);

  private :
    char* list_char_;
    int size_;
};
