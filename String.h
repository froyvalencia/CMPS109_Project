/*
  @author Froylan Valencia
  String Header class
  
  Expected instruction line to be receieved as input:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
  String class inherits from alpha and recieves String value after figuring out the type in VAR
*/
#pragma once
#ifndef STR_H
#define STR_H
#include "VAR.h"
class String : public VAR {
protected:
  int length;
  std::string value;
  static const size_t MAX = 256;
public:
  String();
  String(std::string n, std::string v, int l);
  virtual ~String();
  // A method that initializes the object from a stringstream
  virtual void initialize (vector<string> line); 
  VAR * clone (vector<string> line);
  void setValue(std::string v, int l);
  int getLength();
  string getValue();
  //String& operator=(const String& other); // copy assignment
  char &operator[](int i);  //operator overload used for set_ / get_
};
#endif
