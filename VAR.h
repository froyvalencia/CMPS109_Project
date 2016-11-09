/*
<<<<<<< HEAD
  @author Froylan Valencia
  Var Header File
  Expected instruction line input to be recieved in
=======
  Var Header File
  Expected instruction line input to be recieved in

>>>>>>> 830ded6f28ff872e46951a3c9088a57c66ea8385
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
