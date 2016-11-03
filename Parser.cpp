

class Alpha_t : TYPE {
  flag
  size;
};

class Char_t : alpha {
};
class Str_t : alpha {
};

class Num : type {
  void add(){}
};
class Dbl_t : num {
};
class Int_t : num {
};

template<S *, T *, V *>
Class VAR {
  VAR() {declare stuff }
  varhelpers(){}
};
class Machine {
  MACHINE(){
    //$
    //parser mechanis -> callout to antother classm
    //< >
    //... > 
    //HahsTable[VAR.id] = OBK(VAR)
    //VAR<><><> t = new VAR<><><>();
    
    //submitCommand()


    //I/O
    //
  }
};

  //parse()
  //VAR<><><>
  
class parser {
  parser()
  //getName();
  //getType();
  //getValue();
  

};

//undetermined
//string tokenizer(){}

class Pasrse_Instruction : Parser {
  pasrse_Instruction(String instruction){
    string instructionType = getInstructionType();
    List<string> params = getParameters(instructionType);//or get objectType
    //for param : objType.getParams()) //hopefully by refrence or something
    int num = getNumOfParams();
    for(param : params)
      //get some particular thing
  }
  
};

class parse_Asignment : parser {
 
  parse_Asignmnet(String asignment){
    inst = toeknzize(null,'$');
    name = tokenize('$',',' )
    getName();
    getType();
    getValue();
  }
};

int main() {

  return 0;
}
