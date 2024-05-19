#ifndef _LEXER_
#define _LEXER_


#include<stdint.h>
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>



struct Token {
    std::string token;
    int indent_value;
    uint64_t line_number;
    size_t token_index;
    const std::string& src_name;
    const std::list<std::string>& raw_code;
};

class Lexer {
public:
    std::list<std::string> raw_code;


    Lexer(const std::string& source , std::string s_name) : source(source), current_pos(0), current_indent(0) , source_name(s_name) {}
  
    std::list<Token> tokenize() {
        std::list<Token> tokens;
        std::string line;
        std::istringstream stream(source);

        uint64_t line_count=0; 
        while (std::getline(stream, line)) {
            current_pos = 0;
            current_indent = calculateIndent(line);
            while (current_pos < line.size()) {
                if (std::isspace(line[current_pos])) {
                    ++current_pos;
                    continue;
                }
                tokens.push_back(nextToken(line , line_count));
            }
            
            raw_code.push_back(line);
            tokens.push_back(Token{"\n" , 0  ,line_count,current_pos, source_name , raw_code });
            line_count++;
        }
        return tokens;
    }

private:

    std::string source;
    std::string source_name;
    size_t current_pos;
    int current_indent;

    int calculateIndent(const std::string& line) {
        int indent = 0;
        while (current_pos < line.size() && line[current_pos] == ' ') {
            ++indent;
            ++current_pos;
        }
        return indent;
    }

    Token nextToken(const std::string& line, uint64_t line_count) {
    std::string token;
    while (current_pos < line.size() && !std::isspace(line[current_pos])) {
        if (std::ispunct(line[current_pos]) && line[current_pos] != '_') {
            if (!token.empty()) {
                return Token{token, current_indent, line_count, current_pos, source_name, raw_code};
            } else {
                token += line[current_pos++];
                return Token{token, current_indent, line_count, current_pos, source_name, raw_code};
            }
        } else {
            token += line[current_pos++];
        }
    }
    return Token{token, current_indent, line_count, current_pos, source_name, raw_code};
}
// end of nextToken



};

void lexer_test(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();

    Lexer lexer(code , filename);
    std::list<Token> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        if(token.token == "\n")
        std::cout << "Token: " <<"END_OF_LINE"<<std::endl;
        else
        std::cout << "Token: " << token.token << ", Indent: " << token.indent_value << std::endl;
    }
}


bool isText(std::string& t){
    // if first and last charater  is an alphabet then we consider it as text
     int  f= (int)t.at(0);
     
      if(  (f>=65 && f<=90)  || ( f>=97 && f<=122) || f==95)
         return true;


      return false;   
  }

#endif