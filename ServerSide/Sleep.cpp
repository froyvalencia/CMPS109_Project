#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Sleep.h"
Sleep::Sleep(){}
Sleep::~Sleep(){}

void Sleep::execute(Data * d,vector<string> line){
	VAR * first = d->getVar(line.at(1));
	int i;
	if(Numeric * num = dynamic_cast<Numeric*>(first))
		i = num->getValue();
	else //if(Real * num = dynamic_cast<Real*>(first)){
		i = stoi(line.at(2));
	std::this_thread::sleep_for(std::chrono::milliseconds(i));
}

Instruction * Sleep::clone(){
	Sleep * set = new Sleep();
	return set;
}