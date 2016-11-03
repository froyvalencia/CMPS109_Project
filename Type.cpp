Class TYPE {/
  //STRIng , CHAR, INT, REAl
  string type;
  string value;
  Type(string type, string value){
    
  }
};

class alpha : TYPE {
  //flag
  size;
};

class char_t : alpha {

};
class str_t : alpha {

};
class num : type {
  
  void add(auto &num,auto num2){
    num+=num2;
  }
};
class dbl_t : num {
};
class int_t : num {
};
