/*
  
 */
#include "MathOp.h"
using namespace std;

MathOp::MathOp(){}
MathOp::~MathOp(){}
//HELPERS
template<typename T> T MathOp::ADD(T v) { return v;}
template<typename T> T MathOp::SUB(T v) { return v;}
template<typename T> T MathOp::DIV(T v) { return v;}
template<typename T> T MathOp::MULT(T v) { return v;}

template<typename T, typename... Args>
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
