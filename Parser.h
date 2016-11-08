//
//  Parser.h
//  
//
//  Created by Brian Nguyen on 11/8/16.
//
//
#ifndef Parser_h
#define Parser_h

#include <map>
#include<vector>
class Parser{
 private:
  std::vector<std::string> parsed;
 public:  
  Parser();
  std::vector<std::string> parseFile(std::string file);
  std::map< int, std::vector<std::string> > parseInstructions();
};

#endif /* Parser_h */
