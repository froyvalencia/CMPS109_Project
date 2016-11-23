#include <iostream>
#include "Parser.cpp"
#include <string>
#include <iostream>    
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


int main()
{
	map<int, vector<string>> myMap; 
	static const string arrLABEL[] = {
		"STRING ", "NUMERIC ", "REAL ", "CHAR ", "VAR ", "EQUAL ", "ADD ", "SUB ", "MUL ", "DIV ",
		 "ASSIGN ", "OUT ", "SET_STR_CHAR ", "LABEL LOOP" ,"JMP ", "JMPZ ", "JMPNZ ", "JMPGT ","JMPLT ", 
		 "JMPGTE ", "JMPLTE ", "SLEEP ", "LABEL"};

	Parser myParse;	

	myParse.parseFile("cmdfile.txt");
	myMap = myParse.parseInstructions();

	cout<< "Parsed map:" <<endl;
	for(auto &i : myMap)
   	{
		cout<<"Line "<< i.first << ": "<<endl;
      for(int j = 0; j<i.second.size(); j++)
		cout<< i.second.at(j);
      cout<<""<<endl;
  	 }

  	cout<< "-------------------------------------------" <<endl;
  	//compares elements in map vector<string> to find a match when comparing to arrLABEL
  	for(auto &i : myMap)
   	{
   		for(int j=0; j<sizeof(arrLABEL); j++)
   		{
   			if(i.second.at(0) == arrLABEL[j])
   				cout<< "FOUND A MATCH: " << arrLABEL[j] <<endl;
   		}
   	}




	return 0;
}