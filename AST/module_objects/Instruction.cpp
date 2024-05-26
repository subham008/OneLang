#ifndef _INSTRUCTION_
#define _INSTRUCTION_
  

#include "Expression.cpp"
#include <list>

  class Instruction{
      public:
      std::list<Expression> expressions;

      Instruction()  {}        
       
  };//end of Instruction
#endif