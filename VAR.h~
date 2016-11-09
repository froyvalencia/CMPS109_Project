/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#ifndef VAR_H
#define VAR_H

#include <iostream>
class VAR {
 private:
 protected:
  std::string name; //unique name associated with var
  std::string type; //holds string of type i.e. "Numeric", "Real", "Char", "Stringg
 public:
  VAR(std::string n, std::string t);
  virtual std::string getType() const;
  virtual std::string getName() const;
  virtual void printType() const;
  //auto getValue()=0;
  //virtual auto getValue()=0;
};

#endif
