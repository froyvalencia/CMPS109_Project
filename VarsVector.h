#ifndef VARVECT_H
#define VARVECT_H
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "VAR.cpp"
using namespace std;

class VarsVector{

	public: 
		vector<VAR> varsVector;	
		VarsVector(VAR);
		~VarsVector();
		int getSize();
		

};
#endif