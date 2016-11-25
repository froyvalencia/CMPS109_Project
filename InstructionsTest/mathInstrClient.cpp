#include <algorithm>
#include <iostream>
#include <string>    
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include "Instruction.h"
#include "Parser.h"
#include "Equal.h"
#include "Sub.h"
#include "Add.h"
#include "Mul.h"
#include "Div.h"
using namespace std;
map<int, vector<string> > myMap;
int main(){
  map<string, Instruction *> insMap;
  insMap["ADD"] = new Add();
  insMap["SUB"] = new Sub();
  insMap["MUL"] = new Mul();
  insMap["DIV"] = new Div();
  insMap["EQUAL"] = new Equal();
  vector<string> ins = {"EQUAL", "ADD", "SUB", "MUL", "DIV"};
  Parser myParse;  
  //MathOp myMathOp;
  myParse.parseFile("varTxt.txt");
  myMap = myParse.parseInstructions();
  cout << "Parsed map:" <<endl;
  for(auto &i : myMap) {
    cout<<"Line "<< i.first << ": "<<endl;
    for(int j = 0; j<i.second.size(); j++) cout<< i.second.at(j)<< ",";
    cout <<""<< endl;
  }
  cout<< "-------------------------------------------" <<endl;
  cout<<"before: " << endl;
  for(auto &i : myMap){ //reads each element in myMap. Essentially reads line per line using i.
    if(std::find(ins.begin(), ins.end(), i.second.at(0)) != ins.end()){
      cout << "Found: " <<   i.second.at(0) << endl;
      Instruction * obj = insMap[i.second.at(0)];
      if (obj != NULL) { // If can find an object with name index
        obj = obj->clone(); // Clone an object of the same type
        if(Add* op = dynamic_cast<Add*>(obj)){
          op->execute(i.second);
        }else if(Sub* op = dynamic_cast<Sub*>(obj)){
          op->execute(i.second);
        }else if(Div* op = dynamic_cast<Div*>(obj)){
          op->execute(i.second);
        }else if(Mul* op = dynamic_cast<Mul*>(obj)){
          op->execute(i.second);
        }else if(Equal* op = dynamic_cast<Equal*>(obj)){
          op->execute(i.second);
        }
        delete (obj); // delete the object
      } else cout << "Undefined Object Identifier\n"; 
    }
  }
  cout<<"after: "<< endl;
  return 0;
}