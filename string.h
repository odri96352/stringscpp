class string{
  public :
    string();
    string(const string& copy);
    int size();
  private :
    char[] list_char_;
    int size_;
}
