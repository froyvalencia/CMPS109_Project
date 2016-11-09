/*
This class handles the txt file input into the system. Then parses them intop a map which 
can be referenced by their int line value. 
 
Brian Nguyen
builds@ 9:35pm
 */
//Parser.cpp
#include "Parser.h"
#include <map>
#include <vector>

#include <string>
#include <iostream>  
#include <fstream>

using namespace std;


Parser::Parser(){
  vector< string > parsed;
  map<int , vector<string> > cmdMap;
}

//Takes in file name ("cmdfile.txt") and pushes lines into parsed.
vector<string> Parser::parseFile(string file){
  ifstream cmdFile(file);
  while(getline(cmdFile, file, '\n'))
    {parsed.push_back(file);}
  return parsed;
}


//parses lines from parsed into seperate strings.
map<int,vector<std::string>> Parser:: parseInstructions(){
  for(int i =0; i <parsed.size(); i++)
    {
      string l = parsed.at(i);
      size_t prev = 0, pos;
      
      while ((pos = l.find_first_of("$,", prev)) != std::string::npos)
	{
	  if (pos > prev)
	    cmdMap[i].push_back(l.substr(prev, pos-prev));
	  prev = pos+1;
	}
         if (prev < l.length())
	   cmdMap[i].push_back(l.substr(prev, std::string::npos));
    }
  return cmdMap;  
}
