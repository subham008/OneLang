
//  owner : SUBHAM SHAW

//any changes you want , ask owner to do

#ifndef _ERROR_PRINTER_
#define _ERROR_PRINTER_



#include<stdint.h>
#include<iostream>
#include<string>
#include<list>
#include"../lexer.cpp"





// ANSI escape codes for colors
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string RESET = "\033[0m";





enum ErrorType{
  SYNTAX_ERROR,
  FILE_NOT_FOUND,
  INVALID_NAME_ERROR,
  DUPLICATE_IDENTIFIER,
  UNEXPECTED_IDENTIFIER,
  INDENTATION_ERROR,
  VALUE_ERROR,
  COMPILER_ERROR
};



const char* getErrorTypeToString(ErrorType ty){
    switch (ty)
    {
    case  SYNTAX_ERROR:
        return "SYNTAX ERROR";
        break;
    case COMPILER_ERROR:
        return "COMPILER ERROR";
        break;
    case FILE_NOT_FOUND:
        return "FILE NOT FOUND";
        break; 
    case DUPLICATE_IDENTIFIER:
       return "DUPLICATE INDENTIFIER FOUND";
       break;   
    case UNEXPECTED_IDENTIFIER:
       return "DUPLICATE INDENTIFIER FOUND";
       break;   
    case VALUE_ERROR:
       return "VALUE ERROR";
       break;
    case INDENTATION_ERROR:
      return "INDENTATION ERROR";
       break;
    case INVALID_NAME_ERROR:
      return "INVALID NAME";
      break;
    default:
        return "UNKNOWN ERROR";
        break;
    }
} 

void print_error( const Token& token  ,  std::string messege="unexpected identifier" ,  ErrorType type=SYNTAX_ERROR  ){

   //checking is src has that line
   if( token.line_number > token.raw_code.size()) {
      std::cout<<YELLOW <<getErrorTypeToString(COMPILER_ERROR)<<" : dont worry it is our fault , please report this error to OneLang community"<<RESET<<std::endl;
      std::cout<<"\t"<<RED<<"error occured at  error_printer.cpp->print_error(...) :  line_number is bigger than total lines"<<RESET<< std::endl;
      return;
   }
     
    
    auto it=token.raw_code.begin();
    std::advance(it , token.line_number);
    std::string line =  *it;

     if(token.token_index <= line.length()){
      std::cout<<YELLOW<<token.src_name<<"  at "<<token.line_number+1<<':'<<token.token_index<< " -----> "<<RED<< getErrorTypeToString(type)<<RESET  <<std::endl<<std::endl; //printing error type and line at which error occured
      std::cout<<"\t"<<line<<std::endl<<"\t";
      
      for(int i=0; i<token.token_index-token.token.length() ; i++)
         std::cout<<" ";
      
      std::cout<<RED<<token.token<<std::endl<<std::endl;

      std::cout<<"\t"<<messege<<RESET <<std::endl;

      std::cout<<GREEN<<"  -------------------"<<RESET<<std::endl;
     }
     else{
         std::cout<<getErrorTypeToString(COMPILER_ERROR)<<"  dont worry it is our fault , please report this error to OneLang community"<<std::endl;
         std::cout<<"error occured at  error_printter.cpp->print_errro(...) :  token_index is bigger than total total characters"<<std::endl; 
     }//end of else

   //at first print line
   
}

#endif