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
  map<string, VAR *> insMap;
  map<string, Instruction *> insMap;
  insMap["ADD"] = new Add();
  insMap["SUB"] = new Sub();
  insMap["MUL"] = new Mul();
  insMap["DIV"] = new Div();
  insMap["EQUAL"] = new Equal();
  vector<string> ins = {"EQUAL", "ADD", "SUB", "MUL", "DIV"};
  Parser myParse;
  myParse.parseFile("varTxt.txt");
  myMap = myParse.parseInstructions();
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
        }else if(Assign* op = dynamic_cast<Assign*>(obj)){
          op->execute(i.second);
        }else if(Label * op = dynamic_cast<Label*>(obj)){
          op->execute(i.second);
        }else if(Jump * op = dynamic_cast<Jump*>(obj)){
          op->execute(i.second);
        }else if(JumpZ * op = dynamic_cast<JumpZ*>(obj)){
          op->execute(i.second);
        }else if(JumpNZ * op = dynamic_cast<JumpNZ*>(obj)){
          op->execute(i.second);
        }else if(JumpGT * op = dynamic_cast<JumpGT*>(obj)){
          op->execute(i.second);
        }else if(JumpGTE * op = dynamic_cast<JumpGTE*>(obj)){
          op->execute(i.second);
        }else if(JumpLT * op = dynamic_cast<JumpLT*>(obj)){
          op->execute(i.second);
        }else if(JumpLTE * op = dynamic_cast<JumpLTE*>(obj)){
          op->execute(i.second);
        }else if(Sleep * op = dynamic_cast<Sleep*>(obj)){
          op->execute(i.second);
        }
        delete (obj); // delete the object
      } else cout << "Undefined Object Identifier\n"; 
    }
  }
  cout<<"after: "<< endl;
  return 0;
}