#include "string.h"
#include<cstdlib>
#include<iostream>

int main(){
  string test = string();
  test.print();

  std::cout<<test.c_str()<<std::endl;

  std::exit(EXIT_SUCCESS);
}
