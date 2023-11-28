#include "string.h"
#include<cstdlib>
#include<iostream>

void test_constructor_c_string(char* s);
void test_constructor_c_string_array(char* s, int size_t);
int test_max_size();

int main(){
  string test = string();
  test.print();

  std::cout<<test.c_str()<<std::endl;
  
  char a = 'a';
  char* s = &a;
  test_constructor_c_string(s);

  int size_t = 3;
  char t[] = {'a','b','c'};
  test_constructor_c_string_array(t, size_t);

  std::exit(EXIT_SUCCESS);
}

void test_constructor_c_string(char* s){
  string output = string(s);
  output.print();
};

void test_constructor_c_string_array(char* t, int size_t){
  string output = string(t, size_t);
  output.print();
};

int test_max_size(){};
