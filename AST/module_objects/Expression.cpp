
#ifndef _EXPRESSION_
#define _EXPRESSION_


#include "Value.cpp"
#include "Operator.cpp"
#include<list>

struct ExpMinor{
      Value val1;
      Operator opt;
};


 class Expression
 {    
 public:
    std::list<ExpMinor> exp_list;

    Expression() {} 
 };  // end of  Expression
 



Expression consume_expression(std::list<Token>::iterator& it , std::list<Token>::iterator& end){
    
    //TODO

    // sample expression adding code
     Expression exp = Expression();
     exp.exp_list.push_back( ExpMinor{ Value{ValueType.FUNCTION_VALUE , *it}  , Operator.PLUS_OP } );

     // sample end exp code
      exp.exp_list.push_back( ExpMinor{ Value{ValueType.FUNCTION_VALUE , *it}  , Operator.NO_OP } );

} // end of consume_ expression function


bool checkForDuplicate(Expression exp ,  std::list<Expression>& exp_list){
  //TODO
}
 

#endif