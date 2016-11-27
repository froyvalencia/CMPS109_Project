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
  vector< vector<std::string> > cd;
  for(int i =0; i <parsed.size(); i++){
    cout<<"line:"<<i<<endl;
    string l = parsed.at(i);
    size_t prev = 0, pos;
    bool first = true;
    int j=0;
    while((pos = l.find_first_of("$,", prev)) != std::string::npos){
      cout<<"loop:"<<j++<<endl;
      if(pos > prev) {
        cout<<"inside:\n";
        if(l[pos] == ',') {
          cout << "first\n";
          cd[i].push_back(l.substr(prev, pos-prev));
        }else {
          cout << "second\n";
          cd[i].push_back(l.substr(prev, pos-prev-1));
        }
      }
      cout<<"outside:\n";
      prev = pos+1;
    }
    cout<<"outside of LOOP:\n";
    if (prev < l.length()) 
      cd[i].push_back(l.substr(prev, std::string::npos));
  }
  return cd;  
}

