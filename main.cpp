#include "string.h"
#include<cstdlib>
#include<iostream>

void test_constructor_c_string(char* s);
void test_constructor_c_string_array(char* s, int size_t);
void test_constructeur_default();
void test_c_str();
void test_clear();
int test_max_size();

int main(){

  test_constructeur_default();
  test_c_str();
  test_clear();

  char a = 'a';
  char* s = &a;
  test_constructor_c_string(s);

  int size_t = 3;
  char t[] = {'a','b','c'};
  test_constructor_c_string_array(t, size_t);

  string test = string();
  test.print();
  std::cout<<test.c_str()<<std::endl;

  std::exit(EXIT_SUCCESS);
}


void test_constructeur_default(){
  string test = string();
  test.print();
};

void test_c_str(){
  string test=string();
  std::cout<<test.c_str()<<std::endl;
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
