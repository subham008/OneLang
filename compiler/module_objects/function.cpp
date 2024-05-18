#ifndef _FUNCTION_
#define _FUNCTION_


#include"Variable.cpp"
#include"Modifier.cpp"
#include"AccessIdentifier.cpp"
#include"Instruction.cpp"
#include<string>
#include<vector>

class Function{
   public:
      
      Variable return_type;
      std::string function_name;
      Modifier modifier;
      AccessIdentifier identifier;
      Instruction instructions;
      const std::vector<Variable>& arguments;


       Function(Variable r_type=Variable(VariableType::VOID),
                std::string f_name =" ",
                Modifier mod=Modifier::NORMAL,
                AccessIdentifier ident=AccessIdentifier::PRIVATE,
                Instruction ins=Instruction(),
                const std::vector<Variable>& args=std::vector<Variable>()

                ): return_type(r_type) ,function_name(f_name),modifier(mod),identifier(ident),instructions(ins),arguments(args){}
     
    
};


#endif