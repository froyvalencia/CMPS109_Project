#include "Label.h"
Label::Label(){}
Label::~Label(){}
void Label::execute(Data * d,vector<string> line){
	d->addLabel(line.at(1),d->getCurrent());
}

Instruction * Label::clone(){
	Label * label = new Label();
	return label;
}