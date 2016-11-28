#include "Data.h"
Data::Data(){}
Data::~Data(){
  for(auto v : varMap) delete v.second;
}
int Data::getCurrent(){
  return current;
}
void Data::setCurrent(int i){
  current = i;
}
void Data::addVar(string name, VAR * v){
  varMap[name] = v;
}
VAR * Data::getVar(string name){
  return varMap[name];
}
void Data::addLabel(string label, int i){
  labelMap[label] = i;
}
int Data::getLabel(string label){
  return labelMap[label];
}
