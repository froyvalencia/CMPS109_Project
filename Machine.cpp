/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
*/
#include "Machine.h"
Machine::Machine(std::string filename){
  //parser = new Parser();
  next = 0;
  loadFile(filename);
}

void Machine::loadFile(std::string filename){
  linesOfCode = parser.parseFile(filename); //vector<std::string>
}

//main execution loop
void Machine::executeInstruction(){
  //execure single line call like JMP
  while(next != linesOfCode.size()){
    std::vector<std::string> line = instructions[next++];
    if(instructionHandler.isMath(line[0]) ){
      executeMath(line);
    } else if(instructionHandler.isJump(line[0]) ){
      executeJump(line);
    } else if(instructionHandler.isJump(line[0]) ){
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

void Machine::executeAsignment(vector<std::string> line){
  std::string opcode = line[0];
  std::string varName = line[1];
  std::string val = line[2];
  
  if(opcode == "NUMERIC"){
    auto search =  numericMap.find(varName); //look if  present in map
    
    //names are unique if present break free or throw error
    if(search != numericMap.end()) return;
    
    search = numericMap.find(equals); //look if  present in map
    if(search == numericMap.end())
      numericMap[varName] = new Numeric(varName,stoi(val));
    else
      numericMap[varName] = new Numeric(varName,numericMap[val].getValue());
    
  }else if(opcode == "REAL"){
    auto search =  realMap.find(varName); //look if  present in map
    
    //names are unique if present break free or throw error
    if(search != realMap.end()) return;
    realMap.insert(varName); //we can safely insert var name into map
    
    search = realMap.find(equals); //look if  present in map
    if(search == realMap.end())
      realMap[varName] = new Numeric(varName,stoi(val));
    else
      realMap[varName] = new Numeric(varName,realMap[val].getValue());
  }
  else if(opcode == "CHAR"){
    auto search =  charMap.find(varName); //look if  present in map
    if(search != charMap.end()) return;//names are unique if present break free or throw error
    
    search = charMap.find(equals); //look if  present in map
    if(search == charMap.end())
      charMap[varName] = new Numeric(varName,stoi(val));
    else
      charMap[varName] = new Numeric(varName,charMap[val].getValue());
    
  }else { // by default it is std::string if(opcode == "std::STRING"){
    auto search =  std::stringMap.find(varName); //look if  present in map      
    if(search != std::stringMap.end()) return;//names are unique if present break free or throw error
    
    search = std::stringMap.find(equals); //look if  present in map
    if(search == std::stringMap.end())
      std::stringMap[varName] = new Numeric(varName,stoi(val));
    else
      std::stringMap[varName] = new Numeric(varName,std::stringMap[val].getValue());
  }
  next++;
}

//helpre 
auto Machine::getVal(std::string s){
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
  var = stod(s);
}

void Machine::executeMath(vector<std::string> line){
  if(line.size() < 4){
    //error
    //exit(1);
  }
  
  std::string opcode = line[0];
  auto var;
  auto search = numericMap.find(line[1]);
  if(search != numericMap.end()) {
    var = numericMap[line[1]]; //return Numeric Var obj
  } 
  auto search = realMap.find(line[1]);
  if(searh != realMap.end()){
    var = numericMap[line[1]]; //return Real Var obj
  }
  
  auto val1,val2;
  val1 = getVal(line[2]);
  val2 = getVal(line[3]);
  
  if(opcode == "DIV" ) {  
    if(line.size!=4){
      //message to err
      exit(1);
    }
    instructionHandler.DIV(var,val1,val2);
  }else if (opcode == "SUB"){
    if(line.size!=4){
      //message to err
      exit(1);
    }
    instructionHandler.SUB(var,val1,val2);    
  }else{ 
    //get values if necesary
    auto val3,val4,val5,val6,val7,val8,val9,val10,val11,val12;
    int i=4;
    if(i<line.size()) val3 = getVal(line[i]);
    ++i;
    if(i<line.size()) val4 = getVal(line[i]);
    ++i;
    if(i<line.size()) val5 = getVal(line[i]);
    ++i;
    if(i<line.size()) val6 = getVal(line[i]);
    ++i;
    if(i<line.size()) val7 = getVal(line[i]);
    ++i;
    if(i<line.size()) val8 = getVal(line[i]);
    ++i;
    if(i<line.size()) val9 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val10 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val11 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val12 = getVal(line[i]);
      
    
    if(opcode == "MUL"){
      switch (line.size() -1 ){
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
      }
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
	}
      }
    } 
  }
  
  void Machine::executeAlpha(vector<std::string> line) {
    auto var = std::stringMap[line[1]];
    auto val1 = getVal(line[2]); // var or constrepresent index pos
    auto val2 = getCharVal(line[3]);
    if(line[0] == "GET_STR_CHR" ){
      instructionHandler.GET_STR_CHAR(var,val1,val2);
    }else { //default -> SET_STR_CHAR
      instructionHandler.SET_STR_CHAR(var,val1,val2);
    }
  }
  
  
  //helpr for executeAlpha()
  auto Machine::getCharVal(std::string s){
    auto var;
    auto search = charMap.find(s);
    if(search != charMap.end()) {
      var = charcMap[s]; //return Numeric Var obj
      return var;
    } 
    return ((char) s);
  } 

void Machine::executeOut(vector<std::string> line) {
    int i=1;
    if(i<line.size()) val1 = getVal(line[i]);
    ++i;
    if(i<line.size()) val2 = getVal(line[i]);
    
    if(i<line.size()) val3 = getVal(line[i]);
    ++i;
    if(i<line.size()) val4 = getVal(line[i]);
    ++i;
    if(i<line.size()) val5 = getVal(line[i]);
    ++i;
    if(i<line.size()) val6 = getVal(line[i]);
    ++i;
    if(i<line.size()) val7 = getVal(line[i]);
    ++i;
    if(i<line.size()) val8 = getVal(line[i]);
    ++i;
    if(i<line.size()) val9 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val10 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val11 = getVal(line[i]);
    ++i;    
    if(i<line.size()) val12 = getVal(line[i]); 

    switch (line.size() ) {
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
    
    auto val;
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
    return s;
  }
  
};

int main(){
  return 0;
}
