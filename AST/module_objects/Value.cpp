#ifndef _VALUE_
#define _VALUE_


#include "Variable.cpp"
#include "value_identifier.cpp"
#include<string>

class Value{
    public:
    ValueType type;
    void* value;
    
    ~Value(){
        delete value;
    }
};




Value makeValue(std::list<Token>::iterator& it , std::list<Token>::iterator& end){
      Value val;

      // for integer declaretion
      if(   isInteger(it->token)  ){
          val.type = ValueType.INT;
          
      }
      else if(isFloat(it->token)){
          val.type = ValueType.FLOAT;
      }
      else if( isDouble(it->token)  ){
          val.type = ValueType.DOUBLE;
      }



      return val;
}




#endif