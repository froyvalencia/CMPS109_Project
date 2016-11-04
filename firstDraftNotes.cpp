
template<S *, T *, V *>
class VAR {
  VAR() {declare stuff }
  varhelpers(){}
};

class Machine {
  MACHINE(){
    //$
    //parser mechanis -> callout to antother classm
    //... > 
    //MAP[VAR.id] = OBJ(VAR)
    //VAR<><><> t = new VAR<><><>();
    //submitCommand()

    //I/O
  }
};

class parser {
  parser()
  // getName();
  //getType();
  //getValue();
  //undetermined
  //string tokenizer(){}
};
class pasrse_Instruction : parser {
private:
  
public:
  pasrse_Instruction(String instruction){
    string instructionType = getInstructionType();
    List<string> params = getParameters(instructionType);//or get objectType
    //for param : objType.getParams()) //hopefully by refrence or something
    int num = getNumOfParams();
    for(param : params){
      //get some particular thing
    }
  }
};
 
 


class Parse_Asignment : Parser {
  parse_Asignmnet(String asignment){
    inst = toeknzize(null,'$');
    name = tokenize('$',',' );
    getName();
    getType();
    getValue();
  }
};

int main() {
  return 0;
}
