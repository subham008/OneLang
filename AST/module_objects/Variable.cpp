#ifndef _VARIABLES_
#define _VARIABLES_

   #include<string>
   #include"Expression.cpp"
   #include"Value.cpp"

   enum ValueType{
      INT,
      FLOAT,
      DOUBLE,
      STRING,
      BOOLEAN,
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
      POINTER,
      NOT_VARIABLE_TYPE
   };


   class Variable{
    public:
     ValueType type;
     std::string& name;
     Value value;

     Variable(ValueType ty,std::string& nm){
        type = ty;
        name=nm;
     }
     
   }; // end of variable



#endif