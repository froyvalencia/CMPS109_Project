/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’

*/

class CharVar : Alpha {  
private:
  char value;
public:
  CharVar(string n);
  CharVar(string n, char v);
  friend ostream& operator<<(ostream& os, const CharVar& var);
};
CharVar::CharVar(string n) : Alpha(n, "CHAR") {
  //value = '';
}

CharVar::CharVar(string n, char v) : Alpha(n, "CHAR") {
  value = v;
}



