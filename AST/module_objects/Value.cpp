#ifndef _VALUE_
#define _VALUE_


#include "Variable.cpp"
#include<string>

class Value{
    public:
    ValueType valueType;
    void* value;
    
    ~Value(){
        delete value;
    }
};



enum ValueType{
    FUNCTION_VALUE,
    VARIABLE_VALUE,
    INTEGER_DECLARETION,
    CHAR_DECLARETION,
    STRING_DECLARETION
    BOOLEAN_DECLARETION,
    CLASS_DECLARETION,
    LIST_DECLARETION,
    TUPLE_DECLARETION,
    ARRAY_DECLARETION,
    STRUCT_DECLARETION
}


#endif