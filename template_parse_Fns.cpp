//
//  main.cpp
//  MIS_Project
//
//  Created by Brian Nguyen on 11/3/16.
//  Copyright © 2016 Brian Nguyen. All rights reserved.
// STRING,mystring,100,"Hello world MIS:"

//#include "<All>_c_plus_plus_<All>.h"
#include <string>
#include <iostream>    
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main ()
{
  map<int, vector<string>> cmdmap;
  ifstream cmdFile("cmdfile.txt");
  string file;
  int cmdNum = 0;
  //  int count =0;
  
  //reads in file, parses, pushesback substrings into string vector of map.
  //ideally each line from text file will be referenced by the int value of map
  //great for jmp later on.
  while(getline(cmdFile, file))
    {
      size_t prev = 0, pos;
      while ((pos = file.find_first_of("$,", prev)) != string::npos)
	     {
    	  if (pos > prev)
    	    cmdmap[cmdNum].push_back(file.substr(prev, pos-prev));
    	  prev = pos+1;
	     }
       if (prev < file.length())
	     {
	       cmdmap[cmdNum].push_back(file.substr(prev, string::npos));
	     }
       cmdNum++;
    }
  
  //prints out output
  for(auto &i : cmdmap)
    {
      cout<<"Line # "<< i.first << ": "<<endl; // prints map int value
      for(int j = 0; j<i.second.size(); j++) //prints map vector values.
	     {
	      cout<< i.second.at(j); 
	     }
      cout<<"--------------------"<<endl;
    }

    
}




//inputString<<"STRING $mystring,100,\"Hello world MIS\"";

//parses inputString with $'s and ,'s for each line. inputString can be a txt
//file later on...








/*
write functions that take an arbitrary number of arguments in a type-safe way
 and have all the argument handling logic resolved at compile-time, rather than
run-time.*/
/*
template<typename N>
class Num {
   public:
      string name;
      N valN;
      Num(string n, N val){
         name = n;
         valN = val;
      }
      
      N getVal(){
         return valN;
      }

      N setVal(int n){
         valN = n;
         return valN;
      }
};

class intNum : public Num<int> {
public:
   int value;
   intNum(string name,int val) : Num(name,val) {
      value = val;
   }
};






template<typename T> T ADD(T v) { return v; }
template<typename T> T SUB(T v) { return v; }
template<typename T> T DIV(T v) { return v; }
template<typename T> T MULT(T v) { return v; }

template<typename T, typename... Args>
T ADD(T first, Args... args) {
  return first + ADD(args...);
}

template<typename T, typename... Args>
T SUB(T first, Args... args) {
  return first - SUB(args...);}

template<typename T, typename... Args>
T DIV(T first, Args... args) {
  return first - DIV(args...);
}

template<typename T, typename... Args>
T MULT(T first, Args... args) {
  return first - MULT(args...);
}


int main(){
   intNum myNum("Num1" , 1);
   string s1 = "This ", s2 = "is ", s3 = "a ", s4 = "sentence.";
   string ssum = ADD(s1, s2, s3, s4);

   //double d1=6.2 , d2 =1.2;
   int i1 = 2, i2= 4;
   //adds ints and doubles together.

   cout<< ADD(myNum.getVal(), i1, i2)<<endl;
   cout<< myNum.getVal()<<endl;
   myNum.setVal(ADD(myNum.getVal(), i1, i2));
   cout<<"myNum = " << myNum.getVal()<<endl;
}

*/
