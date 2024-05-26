#ifndef _VALUE-
#define _VALUE_


#include "Variable.cpp"
#include<string>

struct Value{
    ValueType valueType;
    std::string value;
};



enum ValueType{
    FUNCTION_VALUE,
    VARIABLE_VALUE,
    IMMEDIATE_VALUE,
}

#endif