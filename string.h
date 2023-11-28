class string{
  public :
    string();
    string(const string& copy);
    int size();
    string(char* c);
  private :
    char[] list_char_;
    int size_;
}
