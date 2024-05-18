#ifndef _IMPORT_TYPE_
#define _IMPORT_TYPE_

#include"E:\SampleLanguage\lexer\lexer.cpp"
#include "error_printer.cpp"
#include<string>
#include<iostream>
#include<list>


enum   ImportType{
  SYSTEM_PACKAGE,   //if there is no / before package location then it will find package in system directory
  WORKING_DIRECTORY,  //if there is no / then it will find file in working direcctory
  ABSOLUTE_PATH,         // if import start from ".." then it will considered as absolute path
};





class Import
{
   public:

   ImportType import_type;
   std::string path_to_file;
   Token& start_token;

    Import( ImportType ty, std::string   abs_path  , Token& tok)  :  import_type(ty) , path_to_file(abs_path) , start_token(tok) {}


    void print_data(){
      std::cout<<"Import abs path:"<<path_to_file<<std::endl;
    } 

};

bool isImportLocationValid(std::string& location , ImportType type );


Import consume_import(std::list<Token>::iterator& it , std::list<Token>::iterator& end){
       // AT first we will find import location
       //std::cout<<"consume_import begin:"<<it->token<<std::endl;

       Token& stoken = *--it;
       ++it;


       ImportType ty;
      
       if( it->token == "\"" ){
            ty = ImportType::ABSOLUTE_PATH;
            it++;
       }
       else if( it->token == "/"){
            ty=ImportType::WORKING_DIRECTORY;
            it++;
       }
       else{
          ty = ImportType::SYSTEM_PACKAGE;
       }
      

      

      std::string ab_path; 

      if(ty ==ImportType::WORKING_DIRECTORY ||   ty == ImportType::SYSTEM_PACKAGE  ){

          while(it->token != "\n"  && it != end){
              if(it->token == ".")
                 ab_path += "/";
              else
                ab_path += it->token;   

                ++it;
            } // end of while

            ab_path += ".one";  
          }
        else
           while(it->token != "\""  && it != end){
                ab_path += it->token;   
                ++it;
             }

    if( ! isImportLocationValid(ab_path , ty))
         print_error( *--it , "import file not found" , ErrorType::FILE_NOT_FOUND);
     
     ++it;
     return Import(ty,ab_path , stoken);
       
} // end of cosume energy




bool isImportLocationValid(std::string& location , ImportType type ){
     //TODO
     return true;
}


bool checkForDuplicate(Import imp){
      //TODO
     return true;
}



#endif