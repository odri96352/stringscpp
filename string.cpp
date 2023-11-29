#include "string.h"
#include<iostream>
#include <cstdlib>

const int size_max = 100;

string::string(){
  size_=2;
  list_char_=new char[size_];
  list_char_[0]=':';
  list_char_[1]=')';
};

int string::size(){
  return this->size_;
};

int string::length(){
  return this->size_;
};

int string::max_size(){
  return size_max;
};

string::string(const string& copy){
  int length=copy.size_;
  if(length > size_max){
    std::cout<<'W'<<std::endl;
  }
	list_char_ = new char[length];
	size_ = length;
	for (int i = 0; i<length; i++){
	    list_char_[i] = copy.list_char_[i];
	}
};

void string::print(){
  for(int i=0; i<this->size_; ++i){
    std::cout<<this->list_char_[i];
  }
  std::cout<<std::endl;
};

string::string(char* s){
  //Copies the null-terminated character sequence
  //(C-string) pointed by s.
  //a C-String has to end with '/0'.
  int i = 0;
  while(i < size_max && s[i] != '\0' ){
    i += 1;
  }
  this -> size_ = i;
  this -> list_char_ = new char[i];
  for (int j =0; j<i; j++){
    list_char_[j] = s[j];
  }
  return;
};

string::string(char* s, int n){
  //Copies the first n characters
  //from the array of characters pointed by s.
  this -> size_ = n;
  this -> list_char_ = new char[this -> size_];
  for(int i=0; i<this -> size_; i++){
    list_char_[i] = s[i];
  }
};

char* string::c_str(){
  char* cEquivalent=new char[this->size_ +1];
  for(int i=0; i<this->size_; ++i){
    cEquivalent[i]=this->list_char_[i];
    }
  cEquivalent[this->size_ +1]='\0';
  //cEquivalent[this->size_ +2]='0';
  return cEquivalent;
};

void string::clear(){
  this->size_=0;
  delete [] list_char_;
  this->list_char_=nullptr;
};

string& string::operator=(char* t){
  delete [] this -> list_char_;
  int i = 0;
  while(i < size_max || t[i] != '\0' ){
    i += 1;
  }
  this -> size_ = i;
  this -> list_char_ = new char[i];
  for (int j =0; j<i; j++){
    list_char_[j] = t[j];
  }
  return *this;
};

string& string::operator= (const string& str){
// Assigns a new value to the string, replacing its current contents.
// Parameter: A string object,whose value is copied
  delete [] this -> list_char_;
  this -> list_char_ = new char[str.size_];
  this -> size_ = str.size_;
  for (int i = 0; i<this -> size_; i++){
      list_char_[i] = str.list_char_[i];
  }
  return *this;
};

void string::resize(int n){
  // Resizes the string to a length of n characters.

  // If n is smaller than the current string length,
  // the current value is shortened to its first n character,
  // removing the characters beyond the nth.

  // If n is greater than the current string length,
  // the current content is extended by inserting at the end
  // as many characters as needed to reach a size of n.

  if(n > size_){
    char* temp = new char[n];
    for(int i=0; i< size_; i++){
      temp[i]=list_char_[i];
    }
    delete [] this -> list_char_;
    for(int i=size_; i < n; i++){
      temp[i]= '0';
    }
    this -> list_char_ = temp;
    this -> size_ = n;

  }else if(n < size_){
    char* temp = new char[n];
    for(int i=0; i< n; i++){
      temp[i]=list_char_[i];
    }
    delete [] this -> list_char_;
    this -> list_char_ = temp;
    this -> size_ = n;

  }else{
    return;
  }
return;
};

void string::resize(int n,  char c){
//Resizes the string to a length of n characters.
// If c is specified, the new elements are initialized as copies of c

if(n > size_){
  char* temp = new char[n];
  for(int i=0; i< size_; i++){
    temp[i]=list_char_[i];
  }
  delete [] this -> list_char_;
  for(int i=size_; i < n; i++){
    temp[i]= c;
  }
  this -> list_char_ = temp;
  this -> size_ = n;

}else if(n < size_){
  char* temp = new char[n];
  for(int i=0; i< n; i++){
    temp[i]=list_char_[i];
  }
  delete [] this -> list_char_;
  this -> list_char_ = temp;
  this -> size_ = n;

}else{
  return;
}
return;


};
