/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
class Alpha : VAR {
private:
protected:
public:
  Alpha(string n, string t);
  virtual void printType();
};

Alpha::Alpha(string n, string t, length l): VAR(n,t) { 
  cout << " ALPHA CONSTRUCTOR CALLED " << endl;
  length = l;
}

virtual void Alpha::printType(){
  cout<<"Calling Class Alpha of type " << type << endl;
}
