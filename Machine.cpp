/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
 */

class Machine {
private:
  Parser parser;
  Instruction instructionHandler;
  int next;
  vector<string> linesOfCode;
  Map<string, int> labels
  
  
  //holds variabls
  Map<string, Numeric> numericMap;
  Map<string, Real> realMap;
  Map<string, StringVar> stringMap;
  Map<string, CharVar> charMap;
  
  //Map<string, Instruction> instructions;
  
public:
  Machine() {
    parser = new Parser();
  }
  Machine(string filename){
    parser = new Parser();
    next = 0;
    loadfile(filename);
  }
  
  void LoadFile(string filename){
    linesOfCode = parser.readFile(filename); //vector<string>
  }
  
  void LoadInstructions(string label=null){
    //parser.parseInstructions(); //Map <int line, vector<string> >
    //parser.parseLabels();
      //jump to instruction 
    return false;
  }
  
  void executeInstructions(){
    
    for(int i=0;i<instructions.size();++i){
      vector<string> line = instructions[i];
      string opcode = line[0];
      
      if(instructionHandler.valid(opcode){
	  string type = instructionHandler.getType(opcode);
	  if(type == "VAR") {
	    //execute asignment
	    
	  }else if(type == "instructions"){
	    //execute instruction
	    
	  }else{
	    //throw some err exit
	    
	  }
	  
	}
	
	//line by line from start to finish
	return false;
	}
    }
  }

  
  void executeInstruction(){
        //execure single line call like JMP
    while(next != size){
      vector< string > line = instructions[next]; 
      
      if(instructionHandler.isAssign(line[0]) ){
	executeAsignment(line);
      }else if(instructionHandler.isMath(line[0]) ){
	executeMath();
      } else if(instructionHandler.isJump(line[0]) ){
	executeJump();
      } else if(instructionHandler.isJump(line[0]) ){
	executeAlpha();
      } else {
	
      }   
    }
  }
 
  void executeAsignment(vector<string> line){
    string opcode = line[0];
    string varName = line[1];
    string val = line[2];
    
    if(opcode == "NUMERIC"){
      //numericMap.insert(varName)
      auto search =  numericMap.find(varName); //look if  present in map
      
      //names are unique if present break free or throw error
      if(search != numericMap.end()) return;
      numericMap.insert(varName); //we can safely insert var name into map
      
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
      charMap.insert(varName); //we can safely insert var name into map
      
      search = charMap.find(equals); //look if  present in map
      if(search == charMap.end())
	charMap[varName] = new Numeric(varName,stoi(val));
      else
	charMap[varName] = new Numeric(varName,charMap[val].getValue());
      
    }else { // by default it is string if(opcode == "STRING"){
      auto search =  stringMap.find(varName); //look if  present in map      
      if(search != stringMap.end()) return;//names are unique if present break free or throw error
      stringMap.insert(varName); //we can safely insert var name into map
      
      search = stringMap.find(equals); //look if  present in map
      if(search == stringMap.end())
	stringMap[varName] = new Numeric(varName,stoi(val));
      else
	stringMap[varName] = new Numeric(varName,stringMap[val].getValue());
    }
    next++;
    executeInstruction();
  }
  

};

