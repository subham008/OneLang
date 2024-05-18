#ifndef _FUNCTION_DATA__
#define _FUNCTION_DATA_


#include<string>
#include<vector>


uint8_t  SYSTEM_FUNCTIONS=0xCC;
uint8_t  USER_DEFINED_FUNCTIONS=0xCA;
 
 class FunctionData
{
private:
    std::string  r_type;
    std::vector<std::string>  args;
    std::string f_data;
public:
    FunctionData(std::string return_type , std::vector<std::string>  arguments , std::string function_data){
            r_type=return_type;
            args=arguments;
            f_data=function_data;
    }

    std::string  getReturnType(){
        return r_type;
    }

    std::vector<std::string> getArguments(){
        return args;
    }
   
};


#endif