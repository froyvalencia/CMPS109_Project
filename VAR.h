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
#ifndef VAR_H
#define VAR_H

#include <iostream>
using namespace std;

class VAR {
 public:
  string name, type, value, msg;
  VAR(string n, string t, string v);
  VAR(string n, string t, string v, string m);
  virtual string getType() const;
  virtual string getName() const;
  virtual string getValue() const;
  virtual string getMsg() const;
  virtual void setValue(string valIN);
  virtual void setMsg(string s);
  virtual void printType() const;
  virtual void printOut();
  virtual void SET_STR_CHAR(int n, string r);
 // virtual void GET_STR_CHAR(int n);
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