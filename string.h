class string{
  public :
    string();
    string(const string& copy);
    int size();
    void print();
  private :
    char* list_char_;
    int size_;
};
