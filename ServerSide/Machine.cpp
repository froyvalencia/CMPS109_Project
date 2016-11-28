/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
*/
#include "Machine.h"
Machine::Machine(){
    initialize();
}
Machine::Machine(std::string filename){
    initialize();
    loadFile(filename);
}
Machine::~Machine(){
  delete data;
  for(auto& v : objMap) delete v.second; 
  for(auto& i : insMap) delete i.second;
}

void Machine::initialize(){
    data = new Data();
    data->setCurrent(0);
    next = 0;
    //initialize VarMap
    objMap["NUMERIC"] = new Numeric();
    objMap["REAL"] = new Real();
    objMap["STRING"] = new String();
    objMap["CHAR"] = new Char();
    //initialize instruction map;
    insMap["EQUAL"] = new Equal(); 
    insMap["ADD"] = new Add();
    insMap["SUB"] = new Sub();
    insMap["MUL"] = new Mul();
    insMap["DIV"] = new Div();
    insMap["OUT"] = new Out();
    insMap["ASSIGN"] = new Assign();
    insMap["LABEL"] = new Label();
    insMap["SLEEP"] = new Sleep();
    insMap["JMP"] = new Jump();
    insMap["JMPZ"] = new JumpZ();
    insMap["JMPNZ"] = new JumpNZ();
    insMap["JMPGT"] = new JumpGT();;
    insMap["JMPLT"] = new JumpGTE();
    insMap["JMPGTE"] = new JumpLT();
    insMap["JMPLTE"] = new JumpLTE();
    insMap["SET_STR_CHAR"] = new SET_STR_CHAR();
    insMap["GET_STR_CHAR"] = new GET_STR_CHAR();
}

void Machine::loadFile(std::string filename){
    codeLines = parser.parseFile(filename);
    code = parser.parseInstructions();
}

void Machine::executeAll(){
    vector<string> ins = {"EQUAL","ADD","SUB","MUL","DIV","ASSIGN","OUT","GET_STR_CHAR","SET_STR_CHAR","LABEL","JMP","JMPZ","JMPNZ","JMPGT","JMPLT","JMPGTE","JMPLTE","SLEEP"};
    for(next = data->getCurrent(); next < code.size(); next++){ //reads each element in file, mreads line per line using next.
        data->setCurrent(next);
        if(code[next].at(0) == "VAR"){
            cout << "Executing VAR:"<< code[next].at(2) << endl;
            VAR * obj = objMap[code[next].at(2)];
            if(obj != NULL){
                obj = obj->clone(code[next]);
                data->addVar(code[next].at(1),obj);
            } else cout << "Undefined VAR Identifier\n"; 
        }else if(std::find(ins.begin(), ins.end(), code[next].at(0)) != ins.end()){
            cout << "Executing Instruction:"<< code[next].at(0) << endl;
            Instruction * obj = insMap[code[next].at(0)];
            if (obj != NULL) { // If can find an object with name index
                obj = obj->clone(); // Clone an object of the same type
                obj->execute(data, code[next]);
            } else cout << "Undefined Instruction Identifier\n"; 
        }else cout << "Unknown command\n";
    }
}
