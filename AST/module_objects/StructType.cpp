#ifndef _STRUCT_TYPE_
#define _STRUCT_TYPE_


#include<string>
#include<list>
#include"Variable.cpp"

class StructType
{   
public:
    std::string struct_name;
    std::list<VariableType> v_type_list;
    std::list<std::string> v_name_list;
    Token& name_token;
    //constructer
    StructType(std::string name , Token& tok) : struct_name(name) ,  name_token(tok) {}


    
};



StructType consume_struct(std::list<Token>::iterator& it , std::list<Token>::iterator& end){
    // consuming tasty and yummy structs
    
    // now iterator it has "struct"
    int struct_indent_level = it->indent_value;

    std::string struct_name = (++it)->token;
    // now consuming types and values
    StructType stype = StructType(struct_name , *it);

    // to move to first values
       it++;
       while(it->token == "\n")
         it++;
      
     int first_value_indent=-1;
       if(it->indent_value > struct_indent_level )
             first_value_indent =it->indent_value;
       else{
           print_error(*it,"invalid indentation give space before struct variables" , ErrorType::INDENTATION_ERROR);
           // if first value have wrong indentation then  we cant identify where enum value ends so we have to make this enum invalid
          return stype;
       }



         while( (it->indent_value > struct_indent_level  ||  it->token == "\n") && it!=end ){
              if(it->token=="\n"){
             it++;
             continue;
           }

            if(it->indent_value != first_value_indent){
                   print_error(*it , "All variables of struct should be in same line or have same indentation", ErrorType::INDENTATION_ERROR) ;
                   it++;
                   continue;
           }


            if(isText(it->token)){
              //std::cout<<"enum text found"<<struct_name<<std::endl;
              if(isKeyword(it->token))
                  print_error(*it , "keywords cant be use as type" , ErrorType::INDENTATION_ERROR);
              else{
                 stype.v_type_list.push_back(VariableType::CLASS);
                 stype.v_name_list.push_back((++it)->token);
              }
           }


           it++;
         }

       if(stype.v_type_list.size()<=0)
           print_error(*--it , "struct with no variables not allowed ", ErrorType::VALUE_ERROR);
    

    return stype;
}




bool checkForDuplicate(StructType stype ,  std::list<StructType>& struct_list){
            
            bool status=false;
            for( StructType ty : struct_list){
                  if(ty.struct_name == stype.struct_name){
                       status= true;  break;
                  }
            }
          
     return status;
  }


#endif