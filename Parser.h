//
//  Parser.h
//  
//
//  Created by Brian Nguyen on 11/8/16.
//  builds @ 9:38pm 
//
#ifndef Parser_h
#define Parser_h

#include <map>
#include<vector>
class Parser{
 private:
  std::vector<std::string> parsed;
  std::map<int, std::vector<std::string> > cmdMap;
 public:  
  Parser();
  std::vector<std::string> parseFile(std::string file);
  std::map< int, std::vector<std::string> > parseInstructions();
};

#endif /* Parser_h */
