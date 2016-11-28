#include <iostream>
#include <string>    
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include "Parser.h"
#include "VAR.h"
#include "Numeric.h"
#include "String.h"
#include "Char.h"
#include "Real.h"
//#include "MathOp.h"

using namespace std;

vector<VAR*> vars;
map<int, vector<string>> myMap; 
int main()
{
  map<string, VAR *> varMap;
  map<string, Instruction *> insMap;
  //initialize VarMap
  varMap["NUMERIC"] = new Numeric();
  varMap["REAL"] = new Real();
  varMap["STRING"] = new String();
  varMap["CHAR"] = new Char();
  //initialize instruction map;
  insMap["EQUAL"] = new Equal(); 
  insMap["ADD"] = new Add();
  insMap["SUB"] = new Sub();
  insMap["MUL"] = new Mul();
  insMap["DIV "] = new Div();
  insMap["ASSIGN "] = new Assign();
  insMap["OUT "] = new Out();
  insMap["SET_STR_CHAR "] = new SET_STR_CHAR();
  insMap["LABEL"] = new Label();
  /*
  insMap["JMP"] = new JMP();
  insMap["JMPZ "] = new JMP();
  insMap["JMPNZ "] = new JMP();
  insMap["JMPGT "] = new JMP();
  insMap["JMPLT "] = new JMP();
  insMap["JMPGTE "] = new JMP();
  insMap["JMPLTE "] = new JMP();
  insMap["SLEEP "] = new JMP();
  */
  static const string arrLABEL[] = {
    "STRING ", "NUMERIC ", "REAL ", "CHAR ", "VAR ", "EQUAL ", "ADD ", "SUB ", "MUL ", "DIV ",
     "ASSIGN ", "OUT ", "SET_STR_CHAR ", "LABEL LOOP" ,"JMP ", "JMPZ ", "JMPNZ ", "JMPGT ","JMPLT ", 
     "JMPGTE ", "JMPLTE ", "SLEEP "};

  Parser myParse;  
  //MathOp myMathOp;
  myParse.parseFile("varTxt.txt");
  myMap = myParse.parseInstructions();
  //printing 
  cout << "Parsed map:" <<endl;
  for(auto &i : myMap) {
    cout<<"Line "<< i.first << ": "<<endl;
    for(int j = 0; j<i.second.size(); j++) cout<< i.second.at(j)<< " ";
    cout <<""<< endl;
  }
  //printing 

  cout<< "-------------------------------------------" << endl;
  cout<<"size of Varvector before load: " << varVector.size() << endl <<endl;
  for(auto &i : myMap){ //reads each element in myMap. Essentially reads line per line using i.
    for(int j=0; j<sizeof(arrLABEL); j++){
      if(i.second.at(0) == arrLABEL[j]){ //compares Label of Vector inside myMap to  arrayLabels to determine action
        cout << "LABEL: " << arrLABEL[j] <<endl;        
        if(arrLABEL[j] != "VAR "){ //VAR LABEL
          VAR * obj = varMap[i.second.at(2)];
          obj = obj->clone(i.second);
          if ( obj != NULL ) { // If can find an object with name index
            //Clone an object of the same type
            if(Numeric * num = dynamic_cast<Numeric*>(obj)){ //obj->getType() == "NUMERIC"){
              cout << num->getValue() << endl;
              vars.
            }
            
            delete (obj); // delete the object
          } else cout << "Undefined Object Identifier\n"; 
        }
      }
    }
  }
  cout<<"size of Varvector after load: " <<varVector.size() << endl;
  return 0;
}

            /*
            if(i.second.at(2) == "STRING"){ 
            varVector.push_back(VAR(i.second.at(1), i.second.at(2), i.second.at(3), i.second.at(4)));
            cout<< "New VAR: "<< i.second.at(1) <<"\nType: "<<i.second.at(2)<<"\nValue: "<<i.second.at(3)
                <<"\nMsg: "<<i.second.at(4)<<endl<<endl;
            }
            else{
            varVector.push_back(VAR(i.second.at(1), i.second.at(2), i.second.at(3)));
            cout<< "New VAR: "<< i.second.at(1) <<"\nType: "<<i.second.at(2)<<"\nValue: " <<i.second.at(3)<<endl<<endl;
            }
            */
          //}
          /*
          else if(arrLABEL[j] == "ADD "){ //ADD LABEL
            double sumTotal = 0;
            for(int k=2; k<i.second.size(); k++){
              cout<<"Add "<<k-2<<".) : " << sumTotal << " + " <<checkType(i.second.at(k))<< endl;
              sumTotal = sumTotal + checkType(i.second.at(k));
            }
              varVector.at(checkVARexist(i.second.at(1))).setValue(to_string(sumTotal));
              cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value: "
                  <<varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl<<endl;
          }
          else if(arrLABEL[j] == "SUB "){ // SUB LABEL
            double subTotal = 0;  
              cout<<"Sub: " << checkType(i.second.at(3)) << " - " <<checkType(i.second.at(2))<< endl;
              subTotal = checkType(i.second.at(3)) - checkType(i.second.at(2));
              varVector.at(checkVARexist(i.second.at(1))).setValue(to_string(subTotal));
              cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value: "
                  << varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl<<endl;
          }
          else if(arrLABEL[j] == "DIV "){ // DIV Label
            double subTotal = 0;  
              cout<<"Div: " << checkType(i.second.at(3)) << " / " <<checkType(i.second.at(2))<< endl;
              subTotal = checkType(i.second.at(3)) / checkType(i.second.at(2));
              varVector.at(checkVARexist(i.second.at(1))).setValue(to_string(subTotal));
              cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value: "
                  << varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl<<endl;
          }
          else if(arrLABEL[j] == "MUL "){ //MUL LABEL
            double sumTotal = 1;
            for(int k=2; k<i.second.size(); k++){
              cout<<"Mul "<<k-2<<".) : " << sumTotal << " * " <<checkType(i.second.at(k))<< endl;
              sumTotal = sumTotal * checkType(i.second.at(k));
            }
              varVector.at(checkVARexist(i.second.at(1))).setValue(to_string(sumTotal));
              cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value: "
                  <<varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl<<endl;
          }
          else if(arrLABEL[j] == "ASSIGN "){ //ASSIGN LABEL
            cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value before ASSIGN"
              <<varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl;
            varVector.at(checkVARexist(i.second.at(1)))
              .setValue(varVector.at(checkVARexist(i.second.at(2))).getValue());
            cout<<varVector.at(checkVARexist(i.second.at(1))).getName()<<"'s value after ASSIGN"
                <<varVector.at(checkVARexist(i.second.at(1))).getValue()<<endl<<endl;
          }
          else if(arrLABEL[j] == "OUT "){ // OUT LABEL
              cout<<"Print for: " << varVector.at(checkVARexist(i.second.at(1))).getName()<<endl;
              varVector.at(checkVARexist(i.second.at(1))).printOut();
          }
          else if(arrLABEL[j] == "SET_STR_CHAR "){ // SET_STR_CHAR LABEL
            varVector.at(checkVARexist(i.second.at(1))).SET_STR_CHAR(stoi(i.second.at(2)),i.second.at(3));
            cout<<varVector.at(checkVARexist(i.second.at(1))).getMsg()<<endl;
          }
          else if(arrLABEL[j] == "GET_STR_CHAR "){ // GET_STR_CHAR LABEL
            varVector.at(checkVARexist(i.second.at(1))).SET_STR_CHAR(stoi(i.second.at(2)),i.second.at(3));
            cout<<varVector.at(checkVARexist(i.second.at(1))).getMsg()<<endl;
          }
         
         */





/*
int checkVARexist(string s){
  int vIndex = 0;
  bool found = false;
  for(int i=0; i<varVector.size(); i++)
    if(s == varVector.at(i).getName()){
      vIndex = i;
      found = true;
      break;
    }
  if(found == false && vIndex == 0){
    cout<<"VAR not created/found in varVector: " << s<< endl;
    exit(1);
  }
  return vIndex;
}

double checkType(string s){
  int charCounter = 0;
  char nums[] = {'1','2','3','4','5','6','7','8','9','0', '.'};
  for(int i=0;s[i]!='\0';i++)
    for(int j=0; j<sizeof(nums); j++)
      if(s[i] == nums[j])
        charCounter++;
  if(charCounter != s.length())
    return stod(varVector.at(checkVARexist(s)).getValue());
  else
    return stod(s);
}
*/
