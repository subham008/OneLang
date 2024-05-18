
#ifndef _MODULE_
#define _MODULE_


#include"lexer.cpp"
#include"module_objects/function.cpp"
//#include"module_objects/ClassType.cpp"
#include"module_objects/EnumType.cpp"
//#include"module_objects/StructType.cpp"
#include"module_objects/Import.cpp"
#include<iostream>
#include<vector>  
#include<list>
#include"keywords.cpp"


class Module{
  private:  
    std::list<Token> tokens;
  public:
    std::string module_name;
    std::list<Import> module_imports; 
    std::list<Function> module_functions;
    std::list<Variable> module_varibles;
    std::list<Instruction> module_instruction;
    //std::list<ClassType> class_declaretion;
    std::list<EnumType> enum_declaretion;
    //std::list<StructType> struct_declaretion;
    std::list<Module*> modules;

  Module(std::list<Token> tok ,std::string m_name ): tokens(tok),module_name(m_name) {}
      



  void parse_tokens(){
     //here Tokens to AST 
     
    // this for loop will find keywords which then call it respectective function to consume those objects
     std::list<Token>::iterator it=tokens.begin();
     std::list<Token>::iterator end=tokens.end();


     while(it!=end){
         find_keywods(it , end);
         it++;
     }



  }// end of parse_tokens()


     void print_counts(){
      std::cout<<"Module:        "<<module_name<<std::endl;
      std::cout<<"Variables:     "<<module_varibles.size()<<std::endl;
      std::cout<<"Functions:     "<<module_functions.size()<<std::endl;
      std::cout<<"Enums          "<<enum_declaretion.size()<<std::endl;
      std::cout<<"Instructions:  "<<module_instruction.size()<<std::endl;
      std::cout<<"Imports:       "<<module_imports.size()<<std::endl;
 }//end of parse _ counts
    




void find_keywods(std::list<Token>::iterator it , std::list<Token>::iterator end){
       if(it->token ==  keyword::IMPORT){
                module_imports.push_back( consume_import(++it , end));
       }
       else if(it->token ==  keyword::ENUM){
            EnumType ety = consume_enum(++it , end);
            if( !checkForDuplicate(ety ,  this->enum_declaretion))
                enum_declaretion.push_back(  ety);
            else
              print_error(ety.getNameToken() , "enum with same name already exist" , ErrorType::DUPLICATE_IDENTIFIER);
       }
}





    
};//end of Module   class

#endif