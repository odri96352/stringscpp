class string{
  public :
    string();
    string(const string& copy);
    string(char* s);
    string(char* s, int n);
    ~string();
    int size();
    int length();
    void print();
    char* c_str();
    void clear();
    int max_size();
    string& operator=(const char* t);
    string& operator= (const string& str);
    string& operator= (char c);

    //string operator+(char rhs);
    //string operator+(const string&);

    void resize(int n);
    void resize(int n,  char c);
    int capacity();
    bool empty();
    void reserve (int n = 0);

  private :
    char* list_char_;
    int size_;
    int capacity_;
};

// Remarques:
// pour la fonction "resize", est ce qu'on peut avoir des arguments non obligatoires en c++ (pour l'arg "char c") ?
// faire gaffe au deletes et aux news, vérifier qu'il n'y a pas de leaks
// ça veut dire quoi string&, et pourquoi il faut retourner this* pour que ça marche ?
// essayer de comprendre comment utiliser "size_t" (capacity, resize, reserve)
// mettre operator+ dans string.cpp
