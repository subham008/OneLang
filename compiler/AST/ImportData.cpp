#ifndef _ONE_AST_
#define _ONE_AST_


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>


 //import sytax 

 //for importing  system directory  modules
 //import std.one.prelaude


//for importing from present working directory  modules
//import /std.one.prelaude


uint8_t IMPORTED_SYSTEM_MODULES=0xaa;
uint8_t IMPORTED_FILE_DIRECTORY_MODULES=0xaa;

class ImportData {
private:
    std::string filePath;
    uint8_t module_file_type;

public:
    ImportData(const std::string& path) {

        if(path.at(0)=='/')
            module_file_type=IMPORTED_FILE_DIRECTORY_MODULES;
        else
           module_file_type=IMPORTED_SYSTEM_MODULES;

        for(int i=0; i<path.length(); i++){
            char ch=path.at(i);
            if(ch == '.')
               filePath+='/';
            else
              filePath+=ch;   
        }
    }

    std::string getFileContents() {
        std::ifstream file(filePath+".one", std::ios::in);
        if (!file.is_open()) {
            throw std::runtime_error("Unable to locate file: " + filePath+".one");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }


    void getSystemPath(){
        //TODO


    }
};


#endif