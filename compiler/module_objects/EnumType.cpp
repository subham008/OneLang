#ifndef _ENUM_TYPE_
#define _ENUM_TYPE_

//#include"E:\SampleLanguage\lexer\lexer.cpp"
#include"../KeyWords.cpp"
#include"../lexer.cpp"
#include"error_printer.cpp"
#include<string>
#include<list>


  class EnumType
  {
  public:
    std::string enum_name;
    std::list<std::string> enum_values;
    Token& name_token;
    EnumType(std::string name , Token& tok): enum_name(name) , name_token(tok) {}

    Token& getNameToken(){
      return name_token;
    }

  };


  EnumType consume_enum( std::list<Token>::iterator& it , std::list<Token>::iterator& end ){
         
       //here  we will create enum
       
       // now iterator it has "ENUM"
       int enum_indent_level = it->indent_value;

       std::string name = (it)->token; 
      
       if(isKeyword(name))
           print_error(* it , "keywords cant be use as name" , ErrorType::SYNTAX_ERROR);

       EnumType etype = EnumType(name , *it ); 
       
        ++it; // to reach the first Enum value

       while(it->indent_value > enum_indent_level){
           if(isText(it->token)){
              if(isKeyword(it->token))
                  print_error(*it , "keywords cant be use as name" , ErrorType::SYNTAX_ERROR);
              else
              etype.enum_values.push_back(it->token);
           }

            it++;
       }


       if(etype.enum_values.size()<=0)
           print_error(*--it , "enum with no value not allowed", ErrorType::VALUE_ERROR);
        
      return etype; 

  }

  
  




  bool checkForDuplicate(EnumType enumt ,  std::list<EnumType>& enum_list){
            
            bool status=false;
            for( EnumType ty : enum_list){
                  if(ty.enum_name == enumt.enum_name){
                       status= true;  break;
                  }
            }
          
     return status;
  }

#endif