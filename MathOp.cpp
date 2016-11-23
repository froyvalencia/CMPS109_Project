<<<<<<< HEAD
/*
  
 */
=======
>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
#include "MathOp.h"
using namespace std;

MathOp::MathOp(){}
MathOp::~MathOp(){}
<<<<<<< HEAD
=======

>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
//HELPERS
template<typename T> T MathOp::ADD(T v) { return v;}
template<typename T> T MathOp::SUB(T v) { return v;}
template<typename T> T MathOp::DIV(T v) { return v;}
template<typename T> T MathOp::MULT(T v) { return v;}

template<typename T, typename... Args>
<<<<<<< HEAD
T MathOp::ADD(T first, Args... args) { 
  return first + ADD(args...);
}
template<typename T, typename... Args>
T MathOp::SUB(T first, Args... args) { 
  return first - SUB(args...);
}

template<typename T, typename... Args>
T MathOp::MUL(T first, Args... args) { 
  return first * MULT(args...);
}
template<typename T, typename... Args>
T MathOp::DIV(T first, Args... args) { 
  return first / DIV(args...); 
}
=======
	T MathOp::ADD(T first, Args... args) { 

		return ADD(args...) + ADD(args...);}
template<typename T, typename... Args>
	T MathOp::SUB(T first, Args... args) { return first - SUB(args...);}
template<typename T, typename... Args>
	T MathOp::MUL(T first, Args... args) { return first  *  MULT(args...);}
template<typename T, typename... Args>
	T MathOp::DIV(T first, Args... args) { return first / DIV(args...); }
>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
