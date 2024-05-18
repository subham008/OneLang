

#include "Parser.cpp"
#include<iostream>

int main(int  argc, const char* argv[]){
  
  ImportData im("sample");
  std::cout<<im.getFileContents()<<std::endl;
return 0;
}