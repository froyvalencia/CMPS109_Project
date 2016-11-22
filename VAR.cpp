/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include "VAR.h"
using namespace std;
VAR::VAR(string n, string t, string v) {
  name = n;
  type = t;
  value = v;
}
VAR::VAR(string n, string t, string v, string m) {
  name = n;
  type = t;
  value = v;
  msg = m;
}

void VAR::printType() const {cout << type << endl;}

string VAR::getType() const{ return type;}
string VAR::getName() const{ return name;}
string VAR::getValue() const{ return value;}
string VAR::getMsg() const{ return msg;}
void VAR::setMsg(string s){ msg = s;}
void VAR::setValue(string valIN){ value = valIN;}
void VAR::printOut(){
  cout<< "Name: "<< name<<"\nType: "<<type<<"\nValue: " <<value<<endl<<endl;
}
void VAR::SET_STR_CHAR(int n, string r){
  if(msg.length()>=n){
    string str = msg.substr(0,n) + r + msg.substr(n, msg.length());
    setMsg(str);
  }
  else
  {
    cout<<"Can't preform Set_STR_CHAR_ because of string range error"<<endl;
    exit(1);
  }
} 
/*
void VAR::GET_STR_CHAR(int n){
  int index = pos; 
  var[index] = val;
} 
*/









//int main(){
//return 0;
//}
/*
#include <iostream>
#include "VAR.h"
VAR::VAR(string n, string t) {
  name = n;
  type = t;
}
//virtual 
void VAR::printType() const {
  //cout << type << endl;
}
string VAR::getType() const{
  return type;
}
string VAR::getName() const{
  return name;
}
*/