#ifndef _COMPILER_
  #define _COMPILER_

#include<iostream>

//llvm includes
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>


class Compiler{
    
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module>   module;


     public:

     Compiler(){
        context=std::make_unique<llvm::LLVMContext>();
        module=std::make_unique<llvm::Module>("Compiler" , *context);
     } 


     void compile(const std::string& program){
         
         

        saveModuleToFile("module.ll");
     }
   

    
    //to save to file 
     void saveModuleToFile(const std::string& name){
        std::error_code errorCode;
        llvm::raw_fd_ostream outll(name , errorCode);
        module->print(outll , nullptr);
     }


};


#endif