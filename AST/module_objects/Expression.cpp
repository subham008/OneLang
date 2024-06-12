
#ifndef _EXPRESSION_
#define _EXPRESSION_

#include"Module.cpp"
#include "Value.cpp"
#include"../KeyWords.cpp"
#include"../lexer.cpp"
#include"error_printer.cpp"
#include"Operator.cpp"


#include<list>
#include<string>




struct ExpMinor{
      Value val;
      Operator opt;
};


 class Expression
 {    
 public:
    std::list<ExpMinor> exp_list;
    Expression() {} 
 };  // end of  Expression
 



Expression consume_expression( Module& module ,    std::list<Token>::iterator& it , std::list<Token>::iterator& end){
  // remember expression  is called when equal_op is reached , so we just have to think about value assigning and nothing
  // rest is responsiblity of Intsruction.cpp

    Expression exp = Expression();
    it++; //reachng first value after equal_op
    while(*it->token == "\n"  || it != end){
        // parsing expression
        Value v= makevalue(it , end);
        Operator op = 
         it++;// increasing to get next token after each loop
    }
  return exp;
} // end of consume_ expression function



bool checkForDuplicate(Expression exp ,  std::list<Expression>& exp_list){
  //TODO
} // end of  checkForDuplicate
 


#endif