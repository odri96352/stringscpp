#include "string.h"
#include<cstdlib>
#include<iostream>

void test_constructeur_default();
void test_copy_constructor(string t);
void test_c_str(string t);
void test_clear();
void test_constructor_c_string(char* s);
void test_constructor_c_string_array(char* s, int size_t);
void test_max_size(string t);
void test_operator_egal(char* s, string t, char c);
void test_resize(string t, char c);
void test_operator_plus(string a, string b, char c);
string operator+(const string& a1, const char* b1);
string operator+(const string& lhs, char rhs);
string operator+(const string& lhs, const string& rhs);
void test_reserve_and_capacity(string t);
void test_empty(string t);

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

  char b[] =  {'E','q', 'u', 'a', 'l',' ', 'o', 'p', 'e', 'r','a', 't', 'o', 'r', ' ', 'w', 'o', 'r', 'k', 's', ' ','w','i','t','h', ' ', 'a','r','r','a','y','s','\0'};
  char c[] = {'E','q', 'u', 'a', 'l',' ', 'o', 'p', 'e', 'r','a', 't', 'o', 'r', ' ', 'w', 'o', 'r', 'k', 's', ' ','w','i','t','h', ' ','s','t','r','i','n','g','\0'};
  string s = string (c);
  test_operator_egal(b, s, 'w');
  test_operator_plus(s,test,'s');
  test_max_size(test);
  test_reserve_and_capacity(test);

  test_resize(test, ')');
  test_empty(test);

  std::exit(EXIT_SUCCESS);
};


void test_constructeur_default(){
  std::cout << "Testing the default constructor"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << ":)"<<std::endl;
  std::cout << "Is: "<<std::endl;
  string test = string();
  test.print();
  std::cout <<std::endl;
};

void test_copy_constructor(string t){
  std::cout << "Testing the copy constructor"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << ":)"<<std::endl;
  std::cout << "Is: "<<std::endl;
  string test_copy=string(t);
  test_copy.print();
  std::cout <<std::endl;
};

void test_c_str(string t){
  std::cout << "test the conversion string to array of characters"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "[:)]"<<std::endl;
  std::cout << "Is: "<<std::endl;
  int taille=t.size();
  std::cout << "[";
  for (int i=0; i< taille; ++i){
    std::cout <<   t.c_str()[i];
  }
  std::cout<<"]";
  std::cout<<std::endl;
};

void test_constructor_c_string(char* s){
  std::cout << "test the constructor from an array of char"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "Hello"<<std::endl;
  std::cout << "Is: "<<std::endl;
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
  std::cout << "Testing the clear function"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "The string is clear"<<std::endl;
  std::cout << "Is: "<<std::endl;
  string test=string();
  test.clear();
  test.print();
  std::cout <<std::endl;
};

void test_max_size(string t){
  std::cout << "Testing the max_size function"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "100"<<std::endl;
  std::cout << "Is: "<<std::endl;
  std::cout<<t.max_size();
  std::cout<<std::endl;
};

void test_resize(string t, char c){
  std::cout << "Testing the resize function"<<std::endl;
  std::cout << "Making our string bigger"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << ":)0"<<std::endl;
  std::cout << "Is: "<<std::endl;
  t.resize(t.size() + 1);
  t.print();
  std::cout<<std::endl;
  std::cout << "Making our string smaller"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << ":"<<std::endl;
  std::cout << "Is: "<<std::endl;
  t.resize(t.size() - 2);
  t.print();
  std::cout << "Making our string bigger by adding specified characters"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << ":))"<<std::endl;
  std::cout << "Is: "<<std::endl;
  t.resize(t.size() + 2, c);
  t.print();
  std::cout<<std::endl;
};


void test_operator_egal(char* s, string t, char c){
  std::cout << "Testing the operator="<<std::endl;
  std::cout << "With an array of characters"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "Equal operator works with arrays"<<std::endl;
  std::cout << "Is: "<<std::endl;
  string output = s;
  output.print();
  std::cout <<std::endl;
  std::cout << "With an other string"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "Equal operator works with string"<<std::endl;
  std::cout << "Is: "<<std::endl;
  output = t;
  output.print();
  std::cout <<std::endl;
  std::cout << "With a single character"<<std::endl;
  std::cout << "Should be: "<<std::endl;
  std::cout << "w"<<std::endl;
  std::cout << "Is: "<<std::endl;
  output = c;
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

  for (int i = 0; i<string_temp.size(); ++i){
      tableau_temp[i] = contenu_de_string_temp[i];
  }
  tableau_temp[string_temp.size()]=rhs;
  tableau_temp[string_temp.size()+1]='\0';

  return string(tableau_temp);

};

string operator+(const string& a1, const char* b1){
  string a2=string(a1);
  int i = 0;
  while(i < 100 && b1[i] != '\0' ){
    i += 1;
  }
  a2.reserve(a2.size()+i);
  for (int j = 0; j<i; j++){
      a2 = a2 + b1[j];
  }
  return a2;
};

string operator+(const string& lhs, const string& rhs){
  //Returns a newly constructed string object
  //with its value being the concatenation of
  //the characters in lhs followed by those of rhs.
  string lhs_temp=string(lhs);
  // std::cout<<"print copy of lhs" <<std::endl;
  // lhs_temp.print();
  string rhs_temp=string(rhs);
  // std::cout<<"print copy of rhs" <<std::endl;
  // rhs_temp.print();
  int length= lhs_temp.size();
  char* rhs_array_temp=rhs_temp.c_str();
  // std::cout<<"print arrays of rhs" <<std::endl;
  // std::cout << rhs_array_temp<<std::endl;
  lhs_temp.reserve(length+rhs_temp.size());
  // std::cout<<"print new capacity of arrays of lhs" <<std::endl;
  // std::cout << lhs_temp.capacity()<<std::endl;

  for (int i = 0; i<rhs_temp.size(); i++){
      // std::cout<<"current character" <<std::endl;
      // std::cout<<rhs_array_temp[i] <<std::endl;
      lhs_temp = lhs_temp+ rhs_array_temp[i];
      // std::cout<<"we added a new character" <<std::endl;
      // lhs_temp.print();
  }

  return lhs_temp;

};

void test_reserve_and_capacity(string t){
  std::cout<<"Testing the reserve and capacity function"<<std::endl;
  std::cout<<"The string ";
  t.print();
  std::cout<<"takes up ";
  std::cout<<t.capacity();
  std::cout<<" bytes."<<std::endl;
  t.reserve(t.size()+3);
  std::cout<<"After increasing the capacity, the string ";
  t.print();
  std::cout<<"takes up ";
  std::cout<<t.capacity();
  std::cout<<" bytes."<<std::endl;
  t.reserve(t.size()-2);
  std::cout<<"After diminishing the capacity, the string ";
  t.print();
  std::cout<<"takes up ";
  std::cout<<t.capacity();
  std::cout<<" bytes.";
  std::cout<<std::endl;

};

void test_empty(string t){
  std::cout<< "Testing the emptyness of a string"<<std::endl;
  std::cout<<"The string: ";
  t.print();
  std::cout<<"is empty"<<std::endl;
  std::cout<<t.empty()<<std::endl;
  t.clear();
  std::cout<<"After clearin it, the string: ";
  t.print();
  std::cout<<"is empty"<<std::endl;
  std::cout<<t.empty();
  std::cout<<std::endl;
};

void test_operator_plus(string a, string b, char c){
  std::cout<< "Testing the different + operators"<<std::endl;
  char list_char[14] = {' ','a','n','d',' ','c','s','t','r','i','n','g','s', '\0'};
  std::cout << " + operator with c_string [a,b,c] "<<std::endl;
  string output = a + list_char;
  output.print();
  std::cout << " + operator with one character "<<std::endl;
  output = a + c;
  output.print();
  std::cout << " + operator with two strings "<<std::endl;
  output = a + b;
  output.print();
  std::cout <<std::endl;
};
