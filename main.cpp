#include "string.h"
#include<cstdlib>

int main(){
  string test = string();
  test.print();

  char a= 'a';
  char* s=&a;
  string test_2= string(s);
  test_2.print();
  std::exit(EXIT_SUCCESS);
}
