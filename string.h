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
    string& operator=(char* t);
    string& operator= (const string& str);
    void resize(int n);
    void resize(int n,  char c);


  private :
    char* list_char_;
    int size_;
};


// Remarques:
// pour la fonction "resize", est ce qu'on peut avoir des arguments non obligatoires en c++ (pour l'arg "char c") ?
// faire gaffe au deletes et aux news, vérifier qu'il n'y a pas de leaks
