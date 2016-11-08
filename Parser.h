//
//  Parser.h
//  
//
//  Created by Brian Nguyen on 11/8/16.
//
//

#ifndef Parser_h
#define Parser_h

class Parser{
 private:
  vector<string> parsed;
  string instruction;  
  string instructionType;
 public:  
  Parser();
  vector<string> parseFile(string file);
  map<int,vector<string>> parseInstructions();
};

#endif /* Parser_h */
