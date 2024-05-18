#ifndef _PARSER_
#define _PARSER_


#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Token {
    string type;
    string value;
};

vector<Token> tokenize(const string& code) {
    vector<Token> tokens;
    static const regex patterns[] = {
        regex(R"(import\s+\w+(\.\w+)*)"),                     // IMPORT
        regex(R"(print\("(.*)\"))"),                         // PRINT
        regex(R"((\w+)\s*=\s*(\w+)\((.*)?\))"),              // ASSIGNMENT
        regex(R"(fn\s+(\w+)\s*\((\w+\s*,?\s*)*\))"),         // FUNCTION
        regex(R"(switch\((\w+)\))"),                         // SWITCH
        regex(R"(case\s+(\w+\.\w+))"),                       // CASE
        regex(R"(return\s+(.*))")                            // RETURN
        // Add more patterns for other language constructs
    };
    static const string tokenTypes[] = {
        "IMPORT", "PRINT", "ASSIGNMENT", "FUNCTION", "SWITCH", "CASE", "RETURN"
        // Add more token types for other language constructs
    };

    int position = 0;
    while (position < code.length()) {
        bool match = false;
        for (int i = 0; i < sizeof(patterns) / sizeof(regex); i++) {
            smatch result;
            if (regex_search(code.begin() + position, code.end(), result, patterns[i])) {
                match = true;
                tokens.push_back({ tokenTypes[i], result.str() });
                position += result.str().length();
                break;
            }
        }
        if (!match) {
            cout << "Illegal character at position " << position << endl;
            return {};
        }
    }
    return tokens;
}

int main() {
    string code = R"(
import one.std 
print("Enter a string")
name=scan(string)
print("ascii is" , getAscii(name , 8))
fn int getSafeAscii(string name , int n)
    ch=name.at(n)
    switch(Error)
        case string.INDEX_MORE
            ch=name.last()
        case string.NEGATIVE_INDEX
            ch=name.first()
    return (int)ch
)";

    vector<Token> tokens = tokenize(code);
    for (const Token& token : tokens) {
        cout << "Type: " << token.type << ", Value: " << token.value << endl;
    }

    return 0;
}


#endif