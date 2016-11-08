// /*
//   Client for MIS Virtual Machine
// */
#include "Machine.h"

int main() {
  string ins1 = "";string ins2 = "";
  string ins3 = "";string ins4 = "";
  string ins5 = "";string ins5 = "";
  string ins7 = "";string ins8 = "";
  Machine VM = new Machine();
    
  //load instructions from file
  VM.loadFile("FILE.txt");
  //Load one instruction execution
  VM.loadInstruction(); //loads instruction to be executed
  VM.executeInstruction(); //executes one instruction
  
  //load Multiple Instructions for execution
  VM.loadInstructions(); //loads instructions to be executed
  VM.executeInstructions(); //executes all instructions
  VM.laodInstruction("LABEL")

}

