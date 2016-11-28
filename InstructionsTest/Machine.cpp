/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
*/
#include "Machine.h"
Machine::Machine(){
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
    insMap["ASSIGN"] = new Assign();
    insMap["OUT"] = new Out();
    insMap["SET_STR_CHAR"] = new SET_STR_CHAR();
    insMap["GET_STR_CHAR"] = new GET_STR_CHAR();
    insMap["LABEL"] = new Label();
    insMap["JMP"] = new Jump();
    insMap["JMPZ"] = new JumpZ();
    insMap["JMPNZ"] = new JumpNZ();
    insMap["JMPGT"] = new JumpGT();;
    insMap["JMPLT"] = new JumpGTE();
    insMap["JMPGTE"] = new JumpLT();
    insMap["JMPLTE"] = new JumpLTE();
    insMap["SLEEP"] = new Sleep();
}

Machine::Machine(std::string filename){

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
    insMap["ASSIGN"] = new Assign();
    insMap["OUT"] = new Out();
    insMap["SET_STR_CHAR"] = new SET_STR_CHAR();
    insMap["GET_STR_CHAR"] = new GET_STR_CHAR();
    insMap["LABEL"] = new Label();
    insMap["JMP"] = new Jump();
    insMap["JMPZ"] = new JumpZ();
    insMap["JMPNZ"] = new JumpNZ();
    insMap["JMPGT"] = new JumpGT();;
    insMap["JMPLT"] = new JumpGTE();
    insMap["JMPGTE"] = new JumpLT();
    insMap["JMPLTE"] = new JumpLTE();
    insMap["SLEEP"] = new Sleep();
    data = new Data();
    data->setCurrent(0);
    next = 0;
    loadFile(filename);
}

void Machine::loadFile(std::string filename){
    cout << "before codeLines\n";
    codeLines = parser.parseFile(filename);
    cout << "before code\n";
    code = parser.parseInstructions();
    cout << "after code\n";
}
VAR * Machine::getVar(string varName){
    return data->getVar(varName);
}

bool Machine::running(){
    return run;
}

void Machine::executeAll(){
    vector<string> ins = {"EQUAL","ADD","SUB","MUL","DIV","ASSIGN","OUT","GET_STR_CHAR","SET_STR_CHAR","LABEL","JMP","JMPZ","JMPNZ","JMPGT","JMPLT","JMPGTE","JMPLTE","SLEEP"};
    cout<< "-------------------------------------------" <<endl;
    cout<<"before: " << endl;
    cout << "Code size: " << code.size() << endl;
    for(next = data->getCurrent(); next < code.size(); next++){ //reads each element in file, mreads line per line using next.
        data->setCurrent(next);
        cout << "Current size: " << data->getCurrent();
        cout << "Next: " << next << endl;  
        if(code[next].at(0) == "VAR"){
            cout << "Inside VAR IF IN MACHINE" << endl; 
            VAR * obj = objMap[code[next].at(2)];
            if(obj != NULL){
                cout << "BEFORE CLONE\n";
                obj = obj->clone(code[next]);
                //string varName = code[next].at(1) 
                data->addVar(code[next].at(1),obj);
            }
        //delete obj;//make sure no memory leak.
        }else if(std::find(ins.begin(), ins.end(), code[next].at(0)) != ins.end()){
            cout << "Inside INSTRUCTION IF IN MACHINE" << endl; 
            cout << "Found: " <<   code[next].at(0) << endl;
            Instruction * obj = insMap[code[next].at(0)];
            if (obj != NULL) { // If can find an object with name index
                obj = obj->clone(); // Clone an object of the same type
                obj->execute(data, code[next]);
            }else cout << "Undefined Object Identifier\n"; 
        }else{
            cout << "Unknown command\n";
        }
    }
    cout<<"after: "<< endl;
}
void Machine::executeNext() {
   /* if(code[next].at(0) == "VAR"){
        VAR * obj = objMap[code[next].at(2)];
        if(obj != NULL){
            cout << "BEFORE CLONE\n";
            obj = obj->clone(code[next]);
            varMap[code[next].at(1)] = obj; 
        }
    }else if(std::find(ins.begin(), ins.end(), code[next].at(0)) != ins.end()){
        Instruction * obj = insMap[code[next].at(0)];
        if (obj != NULL) { // If can find an object with name index
        obj = obj->clone(); // Clone an object of the same type
        obj->execute(code[next]);
    }
    next++;
    if(next > code.size()) 
        run = false;
        */
}
/*
if(Add* op = dynamic_cast<Add*>(obj)){
  op->execute(code[next]);
}else if(Sub* op = dynamic_cast<Sub*>(obj)){
  op->execute(code[next]);
}else if(Div* op = dynamic_cast<Div*>(obj)){
  op->execute(code[next]);
}else if(Mul* op = dynamic_cast<Mul*>(obj)){
  op->execute(code[next]);
}else if(Equal* op = dynamic_cast<Equal*>(obj)){
  op->execute(code[next]);
}else if(Assign* op = dynamic_cast<Assign*>(obj)){
  op->execute(code[next]);
}else if(Label * op = dynamic_cast<Label*>(obj)){
  op->execute(code[next]);
}else if(Jump * op = dynamic_cast<Jump*>(obj)){
  op->execute(code[next]);
}else if(JumpZ * op = dynamic_cast<JumpZ*>(obj)){
  op->execute(code[next]);
}else if(JumpNZ * op = dynamic_cast<JumpNZ*>(obj)){
  op->execute(code[next]);
}else if(JumpGT * op = dynamic_cast<JumpGT*>(obj)){
  op->execute(code[next]);
}else if(JumpGTE * op = dynamic_cast<JumpGTE*>(obj)){
  op->execute(code[next]);
}else if(JumpLT * op = dynamic_cast<JumpLT*>(obj)){
  op->execute(code[next]);
}else if(JumpLTE * op = dynamic_cast<JumpLTE*>(obj)){
  op->execute(code[next]);
}else if(Sleep * op = dynamic_cast<Sleep*>(obj)){
  op->execute(code[next]);
}
cout << "After INSTRUCTION IF IN MACHINE" << endl;
*/
//delete obj; // delete the object
