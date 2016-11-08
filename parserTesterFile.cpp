//
//  main.cpp
//  practiceFile
//
//  Created by Brian Nguyen on 11/7/16.
//  Copyright © 2016 Brian Nguyen. All rights reserved.
//

#include <iostream>

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <string>
#include <vector>
#include <numeric>

//#include "date.cpp"

using namespace std;  


int main(){
   vector<string> cmdVector;
  map<int,vector<string>> code;
  ifstream cmdFile("cmdfile.txt");
  string file;


//input file into cmdVector
  while(getline(cmdFile, file))
  {
      cmdVector.push_back(file);
}
   for(string l : cmdVector)
   {
    cout<< l<<endl;
   cout<<"--------------------"<<endl;
   }



   cout<<"------------end of transferring input--------"<<endl;
   cout<<"-----------......Parsing......-------"<<endl;


//parsing test

  for(int i=0;i<cmdVector.size(); i++)
  {
   string s = cmdVector.at(i);
    size_t prev = 0, pos;
    while ((pos = s.find_first_of("$,", prev)) != string::npos)
    {
        if (pos > prev)
          code[i].push_back(s.substr(prev, pos-prev));
         prev = pos+1;
         }
        if (prev < s.length())
         code[i].push_back(s.substr(prev, string::npos));

   }

  for(string k : code[1])
   {
    cout<< k <<endl;
   cout<<"--------------------"<<endl;
   }


}


