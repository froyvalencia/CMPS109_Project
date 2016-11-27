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
}
Machine::Machine(std::string filename){
  next = 0;
  loadFile(filename);
}
void Machine::loadFile(std::string filename){
  linesOfCode = parser.parseFile(filename);

}
void executeAll(){
	myMap = myParse.parseInstructions();
	while(running){
	








		next++;
		if(next > linesOfCode.size()) running = false;
	}
}	
void executeNext(){


	next++;
	if(next > linesOfCode.size()) running = false;
}

