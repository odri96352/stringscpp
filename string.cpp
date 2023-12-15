#include "string.h"
#include<iostream>
#include <cstdlib>

const int size_max = 100;

string::~string(){
  delete [] this -> list_char_;
};

string::string(){
  size_=2;
  capacity_=2;
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
  capacity_ = length;
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
  this -> capacity_ = i;
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
  this -> capacity_ = n;
  this -> list_char_ = new char[this -> size_];
  for(int i=0; i<this -> size_; i++){
    list_char_[i] = s[i];
  }
};

char* string::c_str(){
  return this-> list_char_;
};

void string::clear(){
  this->size_=0;
  this -> capacity_=0;
  delete [] list_char_;
  this->list_char_= nullptr;
};

string& string::operator=(const char* t){
  delete [] this -> list_char_;
  int i = 0;
  while(i < size_max || t[i] != '\0' ){
    i += 1;
  }
  this -> size_ = i;
  this -> capacity_ =i;
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
  this -> capacity_ =  str.size_;
  for (int i = 0; i<this -> size_; i++){
      list_char_[i] = str.list_char_[i];
  }
  return *this;
};

string& string::operator= (char c){
// The string value is set to a single copy of character c
// (the string length becomes 1)
  this -> resize(1);
  this -> list_char_[0] = c;
  this -> size_ = 1;
  this -> capacity_ =  1;
  return *this;
};

void string::resize(int n){
// Resizes the string to a length of n characters.

// If n is smaller than the current string length,
// the current value is shortened to its first n character,
// removing the characters beyond the nth.
// the capacity isn't shortened.

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
    this -> capacity_ = n;

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
    this -> capacity_ = n;

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

int string::capacity(){
//Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
//This capacity is not necessarily equal to the string length.
//(pour l'instant, pour nous, si. On a pas créé de méthodes d'optimisation d'ajout de charactères)
//"char" types take 1 byte of storage
  return this -> capacity_;
};

bool string::empty(){
// Returns whether the string is empty (i.e. whether its length is 0).
  if ( this -> size_ == 0){
    return true;
  } else {
    return false;
  }
};

void string::reserve (int n){
// Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
// if n> the size of the string, we increase its capacity to n.
// if n< the size of the string, we delete the elements from [n; size of string]
  if (n>this->capacity_){
    char* new_list_char = new char[n];
    for (int i=0; i<this-> size_; ++i){
      new_list_char[i]= this -> list_char_[i];
    }
    delete [] this -> list_char_;
    this -> list_char_ = new_list_char;
    this -> capacity_ = n;
  }else {
    char* new_list_char = new char[n];
    for (int i=0; i<n; ++i){
      new_list_char[i]= this -> list_char_[i];
    }
    delete [] this -> list_char_;
    this -> list_char_ = new_list_char;
    this -> capacity_ = n;
    this->size_=n;
  }
};

// string string::operator+(char rhs){
//   //Returns a newly constructed string object
//   //with its value being the concatenation of
//   //the characters in this followed by those of rhs.
//
//   this -> resize(this->size_ +1, rhs);
//   string output=string(*this);
//   this -> reserve(this->size_ - 1);
//   return output;
//
// };

// string string::operator+(const string&){
//
// };
