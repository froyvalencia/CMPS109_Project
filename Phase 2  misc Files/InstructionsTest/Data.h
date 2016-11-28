#ifndef DATA_H
#define DATA_H
#include "VAR.h";
class Data {
private:
	std::map<std::string,VAR *> varMap;
	std::map<std::string,int> labelMap;
	int current;
public: 
	Data(){}
	int getCurrent(){
		return current;
	}

	void setCurrent(int i){
		current = i;

	}

	void addVar(string name, VAR * v){
		varMap[name] = v;
	}

	VAR * getVar(string name){
		return varMap[name];
	}

	void addLabel(string label, int i){
		labelMap[label] = i;
	}

	int getLabel(string label){
		if(labelMap[label]){
			cout << "ERROR \n";
			exit(1);
			//return NULL;
		} else {
			return labelMap[label];
		}
	}

};
#endif
