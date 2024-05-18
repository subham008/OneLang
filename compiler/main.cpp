#include<stdio.h>


//llvm includes
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/LLVMContext.h> 
#include<llvm/IR/Module.h>
#include<llvm/IR/Verifier.h>


std::unique_ptr<llvm::LLVMContext> context;
std::unique_ptr<llvm::Module>   mod;
std::unique_ptr<llvm::IRBuilder<>> builder;

void saveModule(const std::string& filename  ){
   std::error_code error_code;
   llvm::raw_fd_ostream outll(filename , error_code);
   mod->print(outll , nullptr);
}


llvm::Value* gen(){
     return builder->getInt32(42);
}


 llvm::Function*   createFunctionProto(const std::string& fname , llvm::FunctionType* fntype){
      auto fn=llvm::Function::Create(fntype,llvm::Function::ExternalLinkage,fname,*mod);
      return fn;
}

void createFunctionBlock(llvm::Function* fun ,const std::string& bname){
    auto entry=llvm::BasicBlock::Create(*context , bname , fun);
    builder->SetInsertPoint(entry);
}


llvm::Function* createFunction(const std::string& fname , llvm::FunctionType* fntype){
    auto fn=mod->getFunction(fname);
    if(fn==nullptr){
          fn=createFunctionProto(fname , fntype);
    }

    createFunctionBlock(fn , "entry");
    return fn;
}



int main(int argc , char* argv[]){
    
    context=std::make_unique<llvm::LLVMContext>();
    mod=std::make_unique<llvm::Module>("One Lang" , *context);
    builder=std::make_unique< llvm::IRBuilder<>>(*context);
    
    auto fn = createFunction("main" , llvm::FunctionType::get(builder->getInt32Ty() , false));
    auto result=gen();
    // variable making
    auto i32r=builder->CreateIntCast(result ,builder->getInt32Ty() ,true );  
    builder->CreateRet(i32r);

    printf("compiler IR : \n");
    
    saveModule("./out.ll");
    

    return 0;
}