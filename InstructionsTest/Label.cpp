Label::Label(){}
Label::~Label(){}
void Label::execute(vector<string> line){
	name = line.at(1);
	value = next;
	labelMap[name] = value;
}

Instruction * Label::clone(){
	Label * label = new Label();
	return label;
}