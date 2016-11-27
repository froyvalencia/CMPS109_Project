#include "Machine.h"
using namespace std;
int main(){
  cout << "BEGIN: \n";
  //Machine *vm = new Machine("varTxt.txt");
  int i = 0;
  //while(vm->running()){
    //cout << "i:" << i << endl;
        //executing one by one
      //  vm->executeNext();}
  //cout << " Execute ALL : \n";
  Machine *vm = new Machine("varTxt.txt");
  vm->executeAll();
  cout << " Execute ALL Finished : \n";
  //return 0;
}
/*
  Parser myParse;  
  //MathOp myMathOp;
  myParse.parseFile("varTxt.txt");
  myvector = myParse.parseInstructions();
  //printing 
  cout << "Parsed map:" <<endl;
  for(auto &i : myvector) {
//    cout<<"Line "<< i << ": "<<endl;
    for(int j = 0; j<i.size(); j++) cout<< i.at(j)<< " ";
    cout <<""<< endl;
  }
  //printing 

  cout<< "-------------------------------------------" << endl;
  cout<<"size of Varvector before load: " << varVector.size() << endl <<endl;
  for(auto &i : myvector){ //reads each element in myMap. Essentially reads line per line using i.
    for(int j=0; j<sizeof(arrLABEL); j++){
      if(i.second.at(0) == arrLABEL[j]){ //compares Label of Vector inside myMap to  arrayLabels to determine action
        cout << "LABEL: " << arrLABEL[j] <<endl;        
        if(arrLABEL[j] != "VAR "){ //VAR LABEL
          VAR * obj = objMap[i.second.at(2)];
          obj = obj->clone(i.second);
          if ( obj != NULL ) { // If can find an object with name index
            //Clone an object of the same type
            if(Numeric * num = dynamic_cast<Numeric*>(obj)){ //obj->getType() == "NUMERIC"){
              cout << num->getValue() << endl;
              var
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
  */


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
