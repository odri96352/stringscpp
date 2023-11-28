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
void test_operator_egal();
void test_resize(string t);

int main(){
  test_constructeur_default();
  test_copy_constructor(test);
  test_c_str(test);
  test_clear();
  test_operator_egal();

  char a = 'a';
  char* s = &a;
  test_constructor_c_string(s);

  int taille = 3;
  char t[] = {'a','b','c'};
  test_constructor_c_string_array(t, taille);


  test_resize(test);

  std::exit(EXIT_SUCCESS);
};

void test_constructeur_default(){
  string test = string();
  test.print();
};

void test_copy_constructor(string t){
  string test_copy=string(t);
  test_copy.print();
};

void test_c_str(string t){
  std::cout<<t.c_str()<<std::endl;
};

void test_constructor_c_string(char* s){
  string output = string(s);
  output.print();
};

void test_constructor_c_string_array(char* t, int size_t){
  string output = string(t, size_t);
  output.print();
};

void test_clear(){
  string test=string();
  test.clear();
  test.print();
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

void test_operator_egal(){
  string test=string();
  test.operator_egal('t');
  test.print();
