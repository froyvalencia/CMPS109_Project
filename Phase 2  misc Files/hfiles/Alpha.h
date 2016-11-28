/*
  Alpha Header File

  Expected instruction line examples to work with:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
 
  Alpha inherits from VAR and handles the given input which will be passed to CharVar or StringVar
*/
//@Status -> VAR compiles and works
#ifndef ALPHA_H
#define ALPHA_H

#include <iostream>
#include <string>
#include "VAR.h"
using namespace std;
class Alpha : public VAR {
private:
protected:
public:
  Alpha(string n, string t);
  virtual void printType();
};
#endif
