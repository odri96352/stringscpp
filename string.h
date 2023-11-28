class string{
  public :
    string();
    string(const string& copy);
    int size();
    void print();
    char* c_str();
  private :
    char* list_char_;
    int size_;
};
