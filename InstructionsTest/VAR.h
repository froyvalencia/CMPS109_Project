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
#pragma once
#ifndef VAR_H
#define VAR_H
#include <iostream>
#include <vector>
using namespace std;
class VAR {
 protected:
  string name;
  string type;
 public:
  VAR();
  virtual ~VAR();
  string getType() const;
  string getName() const;
  virtual void initialize (vector<string> line)=0;
  virtual VAR* clone (vector<string> line)=0;
};
#endif
