#include "string.h"
#include<cstdlib>
#include<iostream>

void test_copy_constructor(string t);
void test_c_str(string t);
void test_constructor_c_string(char* s);
void test_constructor_c_string_array(char* s, size_t sizet);
int test_max_size();

int main(){
  string test = string();
  test.print();

  test_copy_constructor(test);

  test_c_str(test);

  char a = 'a';
  char* s = &a;
  test_constructor_c_string(s);

  size_t sizet = 3;
  char t[] = {'a','b','c'};
  test_constructor_c_string_array(t, sizet);

  std::exit(EXIT_SUCCESS);
};

void test_copy_constructor(string t){
  string test_copy=string(t);
  test_copy.print()
};

void test_c_str(string t){
  std::cout<<t.c_str()<<std::endl;
};

void test_constructor_c_string(char* s){
  string output = string(s);
  output.print();
};

void test_constructor_c_string_array(char* t, size_t sizet){
  string output = string(t, sizet);
  output.print();
};

int test_max_size(){};
