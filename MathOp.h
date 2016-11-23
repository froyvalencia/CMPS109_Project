
#ifndef MATHOP_H
#define MATHOP_H
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class MathOp {  
private: 
	template<typename T> T ADD(T v);
	template<typename T> T SUB(T v);
	template<typename T> T DIV(T v);
	template<typename T> T MULT(T v);
public:
	MathOp();
	~MathOp();
	template<typename T, typename... Args>
 		T ADD(T first, Args... args);
 	template<typename T, typename... Args>
  		T SUB(T first, Args... args);
  	template<typename T, typename... Args>
  		T MUL(T first, Args... args);
  	template<typename T, typename... Args>
  		T DIV(T first, Args... args);

};



#endif