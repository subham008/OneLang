#include<stdio.h>


//llvm includes
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/LLVMContext.h> 
#include<llvm/IR/Module.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Support/FileSystem.h>
#include<llvm/Support/CommandLine.h>


void saveModule(const llvm::Module &module, const std::string &filename) {
    std::error_code EC;
    llvm::raw_fd_ostream dest(filename, EC, llvm::sys::fs::OF_None);

    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message() << "\n";
        return;
    }

    module.print(dest, nullptr);
}


void addInteger(llvm::Module& module , llvm::LLVMContext& context , std::string v_name , int value);
void addFloat(llvm::Module& module , llvm::LLVMContext& context , std::string v_name , int value);
void addString(llvm::Module& module , llvm::LLVMContext& context , std::string v_name , std::string value);
void addGlobalIntArray(llvm::Module &module, llvm::LLVMContext &context, const std::string &name, const std::vector<int> &values);
void  addFunction(
    llvm::Module &module,
    llvm::LLVMContext &context,
    const std::string &name,
    llvm::Type *returnType,
    const std::vector<llvm::Type*> &paramTypes);


int main(int argc , char* argv[]){
    
   std::unique_ptr<llvm::LLVMContext> context=std::make_unique<llvm::LLVMContext>();
   std::unique_ptr<llvm::Module> mod=std::make_unique<llvm::Module>("One Lang" , *context);
   std::unique_ptr<llvm::IRBuilder<>> builder=std::make_unique< llvm::IRBuilder<>>(*context);
    
    
    printf("compiler IR : \n\n\n");
    
    addInteger(*mod , *context , "num_of_devices" , 234);
    //addFloat(*mod , *context , "x_axis" , 2347);
    addString(*mod , *context , "my_name" , "subham shaw"); 
    addGlobalIntArray(*mod , *context , "marks" , {23,45,78,12,90});
    addFunction(*mod , *context , "main" ,llvm::Type::getInt16Ty(*context) , {llvm::Type::getInt16Ty(*context) , llvm::Type::getInt16Ty(*context)  });
    mod->print(llvm::errs(), nullptr);
    
    saveModule(*mod , "out.ll");

    return 0;
}




void addInteger(llvm::Module& module , llvm::LLVMContext& context , std::string v_name , int value){
    llvm::Type *typei32 = llvm::Type::getInt32Ty(context);  // creating type for i32 variable 
    
    llvm::Constant *init = llvm::ConstantInt::get(typei32 , value);  //defining a constant variable it cannot be changed

    llvm::GlobalVariable *gvar = new llvm::GlobalVariable(module , typei32 , true , llvm::GlobalValue::ExternalLinkage , init , v_name );
    
    gvar->setAlignment(llvm::Align(4));   

}


void addFloat(llvm::Module& module , llvm::LLVMContext& context , std::string v_name , int value){
       llvm::Type *ty = llvm::Type::getFloatTy(context);

       llvm::Constant *cons = llvm::ConstantInt::get(ty , value);

       llvm::GlobalVariable *gvar = new llvm::GlobalVariable(module , ty , false , llvm::GlobalVariable::ExternalLinkage ,cons , v_name  );
       
       gvar->setAlignment(llvm::Align(4));
}


void addString(llvm::Module& module , llvm::LLVMContext& context , std::string name , std::string value){
      
      llvm::Constant *constant = llvm::ConstantDataArray::getString(context , value);

      llvm::ArrayType *array = llvm::ArrayType::get(llvm::Type::getInt8Ty(context) , value.length()+1);

      // Create the global variable
    llvm::GlobalVariable *globalStr = new llvm::GlobalVariable(
        module,
        array,
        true,  // isConstant
        llvm::GlobalValue::PrivateLinkage,
        constant,
        name
    );
}// addString


void addGlobalIntArray(llvm::Module &module, llvm::LLVMContext &context, const std::string &name, const std::vector<int> &values) {
    // Define the type of the elements (int32)
    llvm::Type *int32Type = llvm::Type::getInt32Ty(context);

    // Create a vector of constants for the initializer
    std::vector<llvm::Constant*> constValues;
    for (int value : values) {
        constValues.push_back(llvm::ConstantInt::get(int32Type, value));
    }

    // Create a constant array with the provided values
    llvm::Constant *initializer = llvm::ConstantArray::get(llvm::ArrayType::get(int32Type, values.size()), constValues);

    // Create the global variable
    llvm::GlobalVariable *globalArray = new llvm::GlobalVariable(
        module,
        initializer->getType(),
        false,  // isConstant
        llvm::GlobalValue::PrivateLinkage,
        initializer,
        name
    );

    // Optionally, set additional attributes like alignment
    globalArray->setAlignment(llvm::Align(4));
}


void addFunction(
    llvm::Module &module,
    llvm::LLVMContext &context,
    const std::string &name,
    llvm::Type *returnType,
    const std::vector<llvm::Type*> &paramTypes) {

    // Create the function type
    llvm::FunctionType *funcType = llvm::FunctionType::get(returnType, paramTypes, false);

    // Create the function and add it to the module
    llvm::Function *function = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        name,
        module
    );

    // Create a basic block and set the insertion point to it
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context, "", function);
    llvm::IRBuilder<> builder(block);

    // Retrieve function arguments
    llvm::Function::arg_iterator args = function->arg_begin();
    llvm::Value *arg1 = args++;
    arg1->setName("a");
    llvm::Value *arg2 = args++;
    arg2->setName("b");

    // Add instructions to the function (e.g., return a + b)
    llvm::Value *sum = builder.CreateAdd(arg1, arg2, "sum");
    builder.CreateRet(sum);
}




