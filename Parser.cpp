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
  vector<string> parsed;
  map<int, vector<string>> cmdMap;
}

//Takes in file name ("cmdfile.txt") and pushes lines into parsed.
vector<string> Parser::parseFile(string file){
  ifstream cmdFile(file,std::ios::binary);
  while(getline(cmdFile, file, '\n'))
    parsed.push_back(file);
  return parsed;
}

//parses lines from parsed into seperate strings.
vector < vector<std::string> > Parser::parseInstructions(){
  vector< vector<std::string> > code;
  for(int i =0; i <parsed.size(); i++){
    string l = parsed.at(i);
    size_t prev = 0, pos;
    vector<std::string> temp;
    bool first = true;
    cout << "STRING L: " << l << endl;
   
    while ((pos = l.find_first_of("$,", prev)) != std::string::npos){
      cout << "POS: " << pos <<endl;
      if (pos > prev){
        
        if(first){
          cout << "if FIRST !!!:" << l.substr(prev,pos-prev-1)<< ":!!!" << endl;
          temp.push_back(l.substr(prev, pos-prev-1));
          first = false;
        } else {
          temp.push_back(l.substr(prev, pos-prev));
          cout << "!!!:" << l.substr(prev,pos-prev)<< ":!!!" << endl;
        }
      }
      prev = pos+1;
    }
  
    if (prev < l.length()){
      cout << "!!!:"<< l.substr(prev, std::string::npos) << ":!!!"<< endl;
      temp.push_back(l.substr(prev, std::string::npos));
    }
    code.push_back(temp);
  }

  return code;
}


