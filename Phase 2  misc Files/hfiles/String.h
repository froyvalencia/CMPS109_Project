/*
  @author Froylan Valencia 
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#ifndef STR_H
#define STR_H

class StringVar : public Alpha {
private:
  int length;
  std::string value;
  static const size_t MAX = 256;
public:
  StringVar();
  StringVar(std::string n, std::string v, int l);
  ~StringVar();
  void setValue(std::string v, int l);
  int getLength();
  auto getValue();
  //StringVar& operator=(const StringVar& other); // copy assignment
  char &operator[](int i);  //operator overload used for set_ / get_
};
#endif
