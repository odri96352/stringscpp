#include "string.h"
#include<cstdlib>
#include<iostream>

void test_constructeur_default();
void test_copy_constructor(string t);
void test_c_str(string t);
void test_clear();
void test_constructor_c_string(char* s);
void test_constructor_c_string_array(char* s, int size_t);
int test_max_size();
void test_operator_egal(char* c, string s);
void test_resize(string t);
void test_resize_with_char(string t, char c);
void test_operator_plus(string a, char b);
string operator+(const string& lhs, char rhs);

int main(){
  test_constructeur_default();

  string test = string();
  test_copy_constructor(test);
  test_c_str(test);
  test_clear();

  char a[] =  {'H', 'e', 'l', 'l', 'o', '\0'};
  test_constructor_c_string(a);
  int taille = 3;
  test_constructor_c_string_array(a, taille);

  char b[] =  {'e','q', 'u', 'a', 'l',' ', 'o', 'p', 'e', 'r','a', 't', 'o', 'r', ' ', 'w', 'o', 'r', 'k', 's', ' ','w','i','t','h', ' ', 'a','r','r','a','y','s','\0'};
  char c[] = {'e','q', 'u', 'a', 'l',' ', 'o', 'p', 'e', 'r','a', 't', 'o', 'r', ' ', 'w', 'o', 'r', 'k', 's', ' ','w','i','t','h', ' ','s','t','r','i','n','g','\0'};
  string s = string (c);
  test_operator_egal(b, s);
  test_operator_plus(s, 's');


  test_resize(test);
  test_resize_with_char( test , ')');

  std::exit(EXIT_SUCCESS);
};

void test_constructeur_default(){
    std::cout << "test the default constructor"<<std::endl;
  string test = string();
  test.print();
  std::cout <<std::endl;
};

void test_copy_constructor(string t){
  std::cout << "test the copy constructor"<<std::endl;
  string test_copy=string(t);
  test_copy.print();
  std::cout <<std::endl;
};

void test_c_str(string t){
  std::cout << "test the conversion string to array of characters"<<std::endl;
  std::cout<<t.c_str()<<std::endl;
};

void test_constructor_c_string(char* s){
  std::cout << "test the constructor from an array of char"<<std::endl;
  string output = string(s);
  output.print();
  std::cout <<std::endl;
};

void test_constructor_c_string_array(char* t, int size_t){
  std::cout << "test the constructor from an array of char and limiting the size"<<std::endl;
  string output = string(t, size_t);
  output.print();
  std::cout <<std::endl;
};

void test_clear(){
  std::cout << "printing a cleared string"<<std::endl;
  string test=string();
  test.clear();
  test.print();
  std::cout <<std::endl;
};

int test_max_size(){};

void test_resize(string t){
  std::cout << "augmenter la taille de mon string"<<std::endl;
  t.resize(t.size() + 1);
  t.print();
  std::cout<<std::endl;
  std::cout << "diminuer la taille de mon string"<<std::endl;
  t.resize(t.size() - 2);
  t.print();
  std::cout<<std::endl;
};

void test_resize_with_char(string t, char c){
  std::cout << "rajouter des charactères à la fin de mon string"<<std::endl;
  t.resize(t.size() + 2, c);
  t.print();
  std::cout<<std::endl;
};

void test_operator_egal(char* c, string s){
  std::cout << " = operator with array of characters"<<std::endl;
  string output = c;
  output.print();
  std::cout <<std::endl;
  std::cout << " = operator with an other string"<<std::endl;
  output = s;
  output.print();
  std::cout <<std::endl;
};

string operator+(const string& lhs, char rhs){
  //Returns a newly constructed string object
  //with its value being the concatenation of
  //the characters in lhs followed by those of rhs.

  string string_temp=string(lhs);
  char* contenu_de_string_temp=string_temp.c_str();
  char tableau_temp[string_temp.size()+2];

  for (int i = 0; i<string_temp.size(); ++i){ // "-1" pour ne pas récupérer '\0'
      tableau_temp[i] = contenu_de_string_temp[i];
  }
  tableau_temp[string_temp.size()]=rhs;
    tableau_temp[string_temp.size()+1]='\0';

  string output=string(tableau_temp);
  return output;

};

void test_operator_plus(string a, char b){
  std::cout << " + operator with one character "<<std::endl;
  string output = a + b;
  output.print();
  std::cout <<std::endl;
};
