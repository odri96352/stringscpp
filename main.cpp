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
void test_operator_egal(char* c);
void test_resize(string t);
void test_resize_with_char(string t, char c);

int main(){
  test_constructeur_default();

  string test = string();
  test_copy_constructor(test);
  test_c_str(test);
  test_clear();

  char t[] =  {'H', 'e', 'l', 'l', 'o', '\0'};
  test_constructor_c_string(t);
  int taille = 3;
  test_constructor_c_string_array(t, taille);

  char c[] =  {'e','q', 'u', 'a', 'l',' ', 'o', 'p', 'e', 'r','a', 't', 'o', 'r', ' ', 'w', 'o', 'r', 'k', 's', '\0'};
  test_operator_egal(c);


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

void test_operator_egal(char* c){
  std::cout << " = operator"<<std::endl;
  string output = c;
  output.print();
  std::cout <<std::endl;
};
