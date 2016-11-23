/*
  @author Froylan Valencia
  Var Header File
  Expected instruction line input to be recieved in

  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”

  Var class is an object class that wil take in 2 paramenters name and type.
  This base class will be branched down to ALpha and Number classes and then
  will branch down further as needed. 
*/
#ifndef STR_H
#define STR_H

#include <iostream>
#include "VAR.h"
using namespace std;

class STR : VAR {
public:
  string msg;
  STR(string n, string t, string v, string m);
  virtual string getMsg() const;
};

#endif






/*

#ifndef VAR_H
#define VAR_H


#include <iostream>
class VAR {
 private:
 protected:
  string name; //unique name associated with var
  string type; //holds string of type i.e. "Numeric", "Real", "Char", "Stringg
 public:
  VAR(string n, string t);
  virtual string getType() const;
  virtual string getName() const;
  virtual void printType() const;
  //auto getValue()=0;
  //virtual auto getValue()=0;
*/