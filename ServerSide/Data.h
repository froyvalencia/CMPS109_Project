#ifndef DATA_H
#define DATA_H
#include "VAR.h"
#include <map>
using namespace std;
class Data {
 private:
  map<string,VAR *> varMap;
  map<string,int> labelMap;
  int current;
 public:
  Data();
  ~Data();
  int getCurrent();
  void setCurrent(int i);
  void addVar(string name, VAR * v);
  VAR * getVar(string name);
  void addLabel(string label, int i);
  int getLabel(string label);
};
#endif
