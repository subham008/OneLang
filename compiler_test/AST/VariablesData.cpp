#ifndef _VARIABLE_DATA__
#define _VARIABLE_DATA_

#include <iostream>
#include <string>


uint8_t NATIVE_VARIABLES_TYPE=0xbb;
uint8_t CUSTOM_VARIABLES_TYPE=0xbb;


 class VariablesData
{
private:
    std::string variable_type;
    std::string variable_value;
public:
    VariablesData(const std::string& v_type , const std::string& v_value ){
        variable_type = v_type;
        variable_value = v_value;
    }


    std::string getType(){
        return variable_type;
    }
   

   std::string getValue(){
        return variable_value;
    }
   
};


#endif