class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    string(char* s, int n);

    int size();
    int length();
    void print();
    int max_size();

  private :
    char* list_char_;
    int size_;
};
