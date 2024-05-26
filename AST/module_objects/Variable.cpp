#ifndef _VARIABLES_
#define _VARIABLES_

   
   enum VariableType{
      INT,
      FLOAT,
      DOUBLE,
      STRING,
      CHAR,
      INT8,
      INT16,
      INT32,
      INT64,
      UINT8,
      UINT16,
      UINT32,
      UINT64,
      STRUCT,
      CLASS,
      LIST,
      ARRAY,
      TUPLE,
      ENUM,
      VOID,
      POINTER
   };


   #include<string>
   #include"Expression.cpp"

   class Variable{
    public:
     VariableType type;
     std::string type_name;
     std::string variable_name;
     const Expression& value;
     
     Variable(VariableType ty ,
              std::string tn=" ",
               std::string vn =" ", 
               const  Expression& ex =Expression() ): type(ty),type_name(tn),variable_name(vn),value(ex){}


   }; // end of variable



#endif