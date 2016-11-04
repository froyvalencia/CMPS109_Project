// \n, \r, \t

class Parser {  
private:
  List<string> parsed;
public:
  Parser();
  
  //getName();
  //getType();
  //getValue();
};

//undetermined
//string tokenizer(){}
class Pasrse_Instruction : Parser {
private:
  string instruction;
  
public:
  pasrse_Instruction(String instruction){
    string instructionType = getInstructionType();
    List<string> params = getParameters(instructionType);//or get objectType
    //for param : objType.getParams()) //hopefully by refrence or something
    int num = getNumOfParams();
    for(param : params)
      //get some particular thing
      }
  
};

class Parse_Asignment : parser {

private:
  string asignment;
public:
  parse_Asignmnet(string asignment){
    inst = toeknzize(null,'$');
    name = tokenize('$',',' );
    getType();
    getName();
    getValue();
  }
};
