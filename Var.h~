/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/

#include <iostream>
//#include <string>
class VAR {
 private:
 protected:
  std::string name; //unique name associated with var
  std::string type; //holds string of type i.e. "Numeric", "Real", "Char", "Stringg
 public:
  VAR(std::string n, std::string t);
  std::string getType() const;
  std::string getName() const;
  virtual void printType() const;
  //virtual auto getValue()=0;
};

