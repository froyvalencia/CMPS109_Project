/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
class Alpha : VAR {
private:
protected:
public:
  Alpha();
  

  /*
    @params out 1-12
    Any variables or constants
    
    @description
    Prints  out  the  parameters to the standard output.
  */
  void OUT(VAR& var);
  
  /*
    @params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable or constant character.
    
    @description
    Set  a  string  character  at specific  index  to  a character.
    Note: index range  should  be  checked and  errors  should  be reported.
  */
  void SET_STR_CHAR();
  
};
