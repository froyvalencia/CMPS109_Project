/*
  

 */
//Parser.cpp
#include "Parser.h"

Parser(){
  parsed = new vector<string>();
  cmdMap = new map<int, vector<string>();
}

//Takes in file name ("cmdfile.txt") and pushes lines into parsed.
vector<string> parseFile(string file){
  ifstream cmdFile(file);
  int line;
  
  while(getline(cmdFile, line))
    parsed.push_back(file);
  
  return parsed;
}


//parses lines from parsed into seperate strings.
map<int,vector<string>> parseInstructions(){
  for(int i =0; i <parsed.size(); i++)
    {
      string l = parsed.at(i);
      size_t prev = 0, pos;
      
      while ((pos = l.find_first_of("$,", prev)) != string::npos)
	{
	  if (pos > prev)
	    cmdMap[i].push_back(l.substr(prev, pos-prev));
	  prev = pos+1;
	}
         if (prev < s.length())
	   cmdMap[i].push_back(l.substr(prev, string::npos));
    }
  return cmdMap;  
}
