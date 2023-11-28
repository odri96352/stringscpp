#include "string.h"

const int string::size_max = 100;

string::string(){
  size_=2
  list_char_=new char[size_];
  list_char_[0]=":";
  list_char_[1]=")";
}

string::size(){
  return this->size_;
}

string::string(const string& copy){
  int length=copy.size();
  if(length > size_max){
    std::length_error("Error ! The string is too big :(");
  }
	list_char_ = new char[length+1];
	size_ = length;
	for (int i = 0; i<length; i++){
	    list_char_[i] = copy.list_char_[i];
	}
}
