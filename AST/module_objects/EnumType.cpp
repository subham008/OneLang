#ifndef _ENUM_TYPE_
#define _ENUM_TYPE_

//#include"E:\SampleLanguage\lexer\lexer.cpp"
#include"../KeyWords.cpp"
#include"../lexer.cpp"
#include"error_printer.cpp"
#include<string>
#include<list>
#include<iostream>

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
           print_error(* it , "keywords cant be use as name" , ErrorType::INVALID_NAME_ERROR);

       EnumType etype = EnumType(name , *it ); 
       
       // to move to first values
       it++;
       while(it->token == "\n")
         it++;
      

       int first_value_indent=-1;
       if(it->indent_value > enum_indent_level )
             first_value_indent =it->indent_value;
       else{
           print_error(*it,"invalid indentation give space before enum values" , ErrorType::INDENTATION_ERROR);
           // if first value have wrong indentation then  we cant identify where enum value ends so we have to make this enum invalid
          return etype;
       }


       
       while( (it->indent_value > enum_indent_level  ||  it->token == "\n") && it!=end ){
           if(it->token=="\n"){
             it++;
             continue;
           }

           if(it->indent_value != first_value_indent){
                   print_error(*it , "All values of enum should be in same line or have same indentation", ErrorType::INDENTATION_ERROR) ;
                   it++;
                   continue;
           }

           if(isText(it->token)){
              //std::cout<<"enum text found"<<name<<std::endl;
              if(isKeyword(it->token))
                  print_error(*it , "keywords cant be use as name" , ErrorType::INDENTATION_ERROR);
              else
              etype.enum_values.push_back(it->token);
           }

            it++;
       }//end of while


       if(etype.enum_values.size()<=0)
           print_error(*--it , "enum with no value not allowed before enum values", ErrorType::VALUE_ERROR);
        
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