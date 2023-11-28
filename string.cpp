#include "string.h"
#include<iostream>
#include <cstdlib>

const int size_max = 100;

string::string(){
  size_=2;
  list_char_=new char[size_];
  list_char_[0]=':';
  list_char_[1]=')';
}

int string::size(){
  return this->size_;
}

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
}


void string::print(){
  for(int i=0; i<this->size_; ++i){
    std::cout<<this->list_char_[i];
  }
  std::cout<<std::endl;
}

string::string(char* s){
  //Copies the null-terminated character sequence
  //(C-string) pointed by s.
  this -> list_char_ = new char[1];
  list_char_[0] = *s;
  this -> size_ = 1;
}

string::string(char* s, int n){
  //Copies the first n characters
  //from the array of characters pointed by s.
  this -> size_ = n;
  this -> list_char_ = new char[this -> size_];
  for(int i=0; i<this -> size_; i++){
    list_char_[i] = s[i];

char* string::c_str(){

  char* cEquivalent=new char[this->size_ +1];
  for(int i=0; i<this->size_; ++i){
    cEquivalent[i]=this->list_char_[i];
  }
  cEquivalent[this->size_ +1]='\0';
  //cEquivalent[this->size_ +2]='0';
  return cEquivalent;
}
