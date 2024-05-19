
 #include"lexer.cpp"
 #include"Module.cpp"
#include<iostream>
#include"module_objects/error_printer.cpp"


int main(int argc, const char* argv[]){
   if(argc < 2){
    std::cout<<"PLEASE ENTER FILE NAME TOO :main  <filename>"<<std::endl;
    return 1;
  }


  //lexer_test(argv[1]);
  
  std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " <<argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();
    
  //lexer_test(argv[1]);

  Lexer lex( code , argv[1]);
  
  Module mod(lex.tokenize() , "name");
  mod.parse_tokens();
  mod.print_counts();
  

    return 0;
}// end of file