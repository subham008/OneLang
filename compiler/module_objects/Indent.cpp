#ifndef _INDENT_
#define _INDENT_

#include"../lexer.cpp"

class Indent{
  
  public:
   std::list<Token>::iterator& iter;
   Indent(std::list<Token>::iterator& it): iter(it){}
   int first_token_indent=-1;

   bool nextToken(){
       ++iter;
       if(this.first_token_indent == -1){
             first_token_indent=*iter.indent_value;
             return true;
       }
          
      else  if(*iter.indent_value ){

       }
   }
}

#endif