
#ifndef _EXPRESSION_
#define _EXPRESSION_


#include "Value.cpp"
#include "Operator.cpp"


struct ExpMinor{
      Value val1;
      Operator opt;
      Value val2;
};


 class Expression
 {
 private:
     
 public:
    Expression(){}
    
 };
 



void consume_expression(std::list<Token>::iterator& it , std::list<Token>::iterator& end){
     //TODO
} // end of consume_ expression function


bool checkForDuplicate(Expression exp ,  std::list<Expression>& exp_list){
  //TODO
}
 

#endif