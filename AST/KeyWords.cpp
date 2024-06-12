#ifndef _KEYWORDS_CPP_
#define _KEYWORDS_CPP_

#include<vector>
#include<string>
#include<unordered_set>




//there are 17 keywords 
namespace keyword{
   
   const char* IMPORT="import"; 
   const char* CLASS="class";
   const char* ENUM="enum";
   const char* STRUCT="struct";
   const char* IF="if";
   const char* ELSE="else";
   const char* FOR="for";
   const char* WHILE="while";
   const char* EXPORT="export";
   const char* LINK="link";
   const char* SELF="self";
   const char* PUBLIC="pub";
   const char* PRIVATE="pri";
   const char* STATIC="static";
   const char* RETURN="return";
   const char* AS="as";
   const char* FUNCTION="fn";
   const char* EXTENDS="extends";
   

   std::unordered_set<std::string>  keyword_set;
};


void fillkeywordSet(){
    using namespace keyword;
    
    keyword_set.insert(IMPORT);
    keyword_set.insert(keyword::CLASS);
    keyword_set.insert( keyword::ENUM);
    keyword_set.insert(keyword::STRUCT);
    keyword_set.insert(IF);
    keyword_set.insert(ELSE);
    keyword_set.insert(FOR);
    keyword_set.insert(WHILE);
    keyword_set.insert(keyword::EXPORT);
    keyword_set.insert(keyword::LINK);
    keyword_set.insert(SELF);
    keyword_set.insert(keyword::PUBLIC);
    keyword_set.insert(keyword::PRIVATE);
    keyword_set.insert(keyword::AS);
    keyword_set.insert(keyword::FUNCTION);
    keyword_set.insert(STATIC);
    keyword_set.insert(RETURN);
    keyword_set.insert(EXTENDS);
}


bool isKeyword(const std::string& key) {
   if(keyword::keyword_set.size()<=0)
       fillkeywordSet();
    
    if(keyword::keyword_set.find(key) != keyword::keyword_set.end())
       return true;

       return false;
}


#endif