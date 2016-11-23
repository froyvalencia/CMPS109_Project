/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
*/
#include "Machine.h"
Machine::Machine(std::string filename){
  next = 0;
  loadFile(filename);
}

void Machine::loadFile(std::string filename){
  linesOfCode = parser.parseFile(filename); //vector<std::string>
}

//main execution loop
void Machine::executeInstruction(){
  //execure single line call like JMP
  auto instructions = parser.parseInstructions();
  while(next != linesOfCode.size()){
    std::vector<std::string> line = instructions[next++];
    size_t n = line.size();
    if(instructionHandler.isMath(line[0])){
      executeMath(line);
    } else if(instructionHandler.isJump(line[0])){
      //next = executeJump(line);
    } else if(instructionHandler.isAlpha(line[0])){
      executeAlpha(line);
    } else if(line[0] == "ASSIGN" ){
      executeAsignment(line);
    } else if(line[0] == "LABEL"){
      labels[line[1]] = next; 
    }else { //default it is OUT
      executeOut(line);
    }
  }
}

void Machine::executeAsignment(std::vector<std::string> line){
  std::string opcode = line[1];
  std::string varName = line[2];
  std::string val = line[3];
  
  bool objectFlag = true;
  auto search = variables.find(varName);
  if(search == variables.end() ) {
    objectFlag = false;
    //put errorinto buffer
  }
  /*
  if(opcode == "NUMERIC") {
    if(objectFlag) numericMap[varName] = Numeric(varName, numericMap[val].getValue());
    else numericMap[varName] = Numeric(varName, stoi(val));
    variables[varName] = "Numeric";
    
  }else if(opcode == "REAL"){
    if(objectFlag) realMap[varName] = Real(varName,realMap[val].getValue());
    else realMap[varName] = Real(varName,stod(val));
    variables[varName] = "Real";
    
  }else if(opcode == "CHAR"){    
    if(objectFlag) charMap[varName] = CharVar(varName, charMap[val].getValue());
    else charMap[varName] = CharVar(varName, val[0]); 
    variables[varName] = "Char";
    
  }else { // by default it is std::string if(opcode == "STRING"){
    if(objectFlag) stringMap[varName] = StringVar(varName,val,stoi(line[4]));
    else stringMap[varName] = StringVar(varName,stringMap[val].getValue(),stringMap[val].getLength());
    variables[varName] = "String";
  }
  */
  next++;
}

//  return Numeric var obj
Numeric* Machine::getVal(std::string s){
  /*
    auto search = numericMap.find(s);
  if(search != numericMap.end()) {
    auto var = numericMap[s]; //return Numeric Var obj
    return var;
  }*/
  return NULL;
}

//helpre 
Real* Machine::getReal(std::string s){
  /*  
  auto search2 = realMap.find(s);
  if(search2 != realMap.end()){
    auto var = realMap[s]; //return Real Var obj  
    return var;
    }*/
  return NULL;
}

auto Machine::helper(int curr, std::vector<std::string> &line){
  /*    if(curr < line.size() ) return getVal(line[0]);
	return getVal(line[curr]);  */ 
}

void Machine::executeMath(std::vector<std::string> line){
  if(line.size() < 4){
    //error
    //exit(1);
  }
  /*
  std::string opcode = line[0];
  auto search = numericMap.find(line[1]);
  auto var;
  
  if(search != numericMap.end()) {
    var = numericMap[line[1]]; //return Numeric Var obj
  } 

  auto search2 = realMap.find(line[1]);
  if(search2 != realMap.end()){
    var = realMap[line[1]]; //return Real Var obj
  }

  auto val1 = getVal(line[2]);
  auto val2 = getVal(line[3]);

  if(opcode == "DIV" ) {  
    if(line.size()!=4){
      //message to err
      exit(1);
    }
    instructionHandler.DIV(var,val1,val2);
  }else if (opcode == "SUB"){
    if(line.size()!=4){
      //message to err
      exit(1);
    }
    instructionHandler.SUB(var,val1,val2);    
  }else{ 
    //get values if necesary

    int i=3;
    auto val3 = helper(++i,line);
    auto val4 = helper(++i,line);
    auto val5 = helper(++i,line);
    auto val6 = helper(++i,line);
    auto val7 = helper(++i,line);
    auto val8 = helper(++i,line);
    auto val9 = helper(++i,line);
    auto val10 = helper(++i,line);
    auto val11 = helper(++i,line);
    auto val12 = helper(++i,line);
    if(opcode == "MUL"){
      switch (line.size() - 1){
      case 3: instructionHandler.MUL(var,val1,val2); break;
      case 4: instructionHandler.MUL(var,val1,val2,val3); break;
      case 5: instructionHandler.MUL(var,val1,val2,val3,val4); break;
      case 6: instructionHandler.MUL(var,val1,val2,val3,val4,val5); break;
      case 7: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6); break;
      case 8: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7); break;
      case 9: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7,val8); break;
      case 10: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7,val8,val9); break;
      case 11: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10); break;
      case 12: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11); break;
      case 13: instructionHandler.MUL(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12); break;
      }//END SWITCH
    } else if(opcode == "ADD"){
      switch (line.size() -1 ){
        case 3: instructionHandler.ADD(var,val1,val2); break;
        case 4: instructionHandler.ADD(var,val1,val2,val3); break;
    	case 5: instructionHandler.ADD(var,val1,val2,val3,val4); break;
    	case 6: instructionHandler.ADD(var,val1,val2,val3,val4,val5); break;
    	case 7: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6); break;
    	case 8: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7); break;
    	case 9: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7,val8); break;
    	case 10: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7,val8,val9); break;
    	case 11: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10); break;
    	case 12: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11); break;
    	case 13: instructionHandler.ADD(var,val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12); break;
    	}//END SWITCH
    }
  } 
  */
}


void Machine::executeAlpha(std::vector<std::string> line) {
  /*
  auto var = stringMap[line[1]];
  auto val1 = getVal(line[2]); // var or constrepresent index pos
  auto val2 = getCharVal(line[3]);
  if(line[0] == "GET_STR_CHR" ){
    instructionHandler.GET_STR_CHAR(var,val1,val2);
  }else { //default -> SET_STR_CHAR
    instructionHandler.SET_STR_CHAR(var,val1,val2);
  }
  */
}

//helpr for executeAlpha()
CharVar *Machine::getCharVal(std::string s){
  //  CharVar v = charMap[s]; //return char Var obj
  //return v;
  return NULL;
} 

//auto Machine::helperOut(int curr, std::vector<std::string> &line){
  //if(curr < line.size() ) return getOutVal(line[0]);
  //  return getOutVal(line[curr]); //cast to string
//}

void Machine::executeOut(std::vector<std::string> line) {
  int i=-1;
  
  /*
    auto Machine::helperOut(int curr, std::vector<std::string> &line){
    if(curr < line.size() ) return getOutVal(line[0]);
    return getOutVal(line[curr]);
    }
  */
  /*
  auto val1 = helperOut(++i,line);
  auto val2 = helperOut(++i,line);
  auto val3 = helperOut(++i,line);
  auto val4 = helperOut(++i,line);
  auto val5 = helperOut(++i,line);
  auto val6 = helperOut(++i,line);
  auto val7 = helperOut(++i,line);
  auto val8 = helperOut(++i,line);
  auto val9 = helperOut(++i,line);
  auto val10 = helperOut(++i,line);
  auto val11 = helperOut(++i,line);
  auto val12 = helperOut(++i,line);

  switch (line.size()) {
  case 1: instructionHandler.OUT(val1); break;
  case 2: instructionHandler.OUT(val1,val2); break;
  case 3: instructionHandler.OUT(val1,val2,val3); break;
  case 4: instructionHandler.OUT(val1,val2,val3,val4); break;
  case 5: instructionHandler.OUT(val1,val2,val3,val4,val5); break;
  case 6: instructionHandler.OUT(val1,val2,val3,val4,val5,val6); break;
  case 7: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7); break;
  case 8: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7,val8); break;
  case 9: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7,val8,val9); break;
  case 10: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7,val8,val9,val10); break;
  case 11: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11); break;
  case 12: instructionHandler.OUT(val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12); break;
  default: break;//"error"      
  }

  //helper for executeOut
  auto Machine::getOutVal(std::string s){
  auto var;
    
  auto search = numericMap.find(s);
  if(search != numericMap.end()) {
    var = numericMap[s]; //return Numeric Var obj
    return var;
  }
  
  auto search = realMap.find(s);
  if(searh != realMap.end()){
    var = numericMap[s]; //return Real Var obj
    return var;
  }

  auto search = numericMap.find(s);
  if(search != numericMap.end()) {
    var = numericMap[s]; //return Numeric Var obj
    return var;
  } 
    //return real
  auto search = realMap.find(s);
  if(searh != realMap.end()){
    var = numericMap[s]; //return Real Var obj
    return var;
  }  
  */
  }
  
