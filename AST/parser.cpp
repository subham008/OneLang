#ifndef _PARSER_
#define _PARSER_

#include"lexer.cpp"
#include<vector>
#include<list>
#include<string>
#include<iostream>



enum NodeType {
    IMPORT,
    VARIABLE,
    FUNCTION,
    IF_LOOP,
    WHILE_LOOP,
    ARRAY,
    LIST,
    TUPLE,
    CLASS,
    STRUCT,
    ENUM,
    ROOT,
    LITERAL_NODE,
    VALUE,
    PRINT
};


std::string nodeTypeToString(NodeType type) {
    switch(type) {
        case IMPORT: return "IMPORT";
        case VARIABLE: return "VARIABLE";
        case FUNCTION: return "FUNCTION";
        case IF_LOOP: return "IF_LOOP";
        case WHILE_LOOP: return "WHILE_LOOP";
        case ARRAY: return "ARRAY";
        case LIST: return "LIST";
        case TUPLE: return "TUPLE";
        case CLASS: return "CLASS";
        case STRUCT: return "STRUCT";
        case ENUM: return "ENUM";
        case ROOT: return "ROOT";
        case LITERAL_NODE: return "LITERAL_NODE";
        case PRINT: return "PRINT";
        default: return "UNKNOWN";
    }
}


 struct  Node {
    NodeType type;
    std::vector<Node*> children;

    Node(NodeType type, const std::string& value = "") {}

    void debug(){
        std::cout<<"type:\t"<<nodeTypeToString(type)<<"   childs:"<<children.size()<<std::endl;
    }
   

    ~Node() {
        for (Node* child : children)  {
            delete child;
        }
       
    }
};


class Parser{
   std::vector<Token> tokens;

   public:
    Parser(std::vector<Token> tok):tokens(tok){}

   
    Node* parse_assignment(std::vector<Token>::iterator& it, std::vector<Token>::iterator end);
    Node* parse_if_statement(std::vector<Token>::iterator& it, std::vector<Token>::iterator end);
    Node* parse_expression(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) ;
    void  parse_block(std::vector<Token>::iterator& it, std::vector<Token>::iterator end, std::vector<Node*>& body);
    Node* parse_while_loop(std::vector<Token>::iterator& it, std::vector<Token>::iterator end);
    Node* parse_print_statement(std::vector<Token>::iterator& it, std::vector<Token>::iterator end);

    
    bool is_type(const Token& token, TokenType type);
    bool is_any_type(const Token& token, std::vector<TokenType> types);
    bool consume(std::vector<Token>::iterator& it, std::vector<Token>::iterator end, TokenType type) ;


    Node* parse_import(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::IMPORT);
        ++it;  // Consume 'import'
        
        while( (it != end)   && (it->type != END_OF_LINE)  ){
        if (is_type(*it,IDENTIFIER)) {
            node->children.push_back(new Node(NodeType::VALUE, it->value)); 
        } 
        ++it;
        }
        return node;
    }//end of import 


     Node* parse_array(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::ARRAY);
        ++it;  // Consume '{'
        while (it != end && !is_type(*it, OPERATOR) && it->value != "}") {
            node->children.push_back(parse_expression(it, end));
            if (consume(it, end, OPERATOR) && it->value == ",") {
                ++it;
            }
        }
        if (!consume(it, end, OPERATOR) || it->value != "}") {
            // Handle error: expected '}'
        } else {
            ++it;
        }
        return node;
    }


    Node* parse_list(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::LIST);
        ++it;  // Consume '['
        while (it != end && !is_type(*it, OPERATOR) && it->value != "]") {
            node->children.push_back(parse_expression(it, end));
            if (consume(it, end, OPERATOR) && it->value == ",") {
                ++it;
            }
        }
        if (!consume(it, end, OPERATOR) || it->value != "]") {
            // Handle error: expected ']'
        } else {
            ++it;
        }  
        return node;
    }


    Node* parse_tuple(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::TUPLE);
        ++it;  // Consume '('
        while (it != end && !is_type(*it, OPERATOR) && it->value != ")") {
            node->children.push_back(parse_expression(it, end));
            if (consume(it, end, OPERATOR) && it->value == ",") {
                ++it;
            }
        }
        if (!consume(it, end, OPERATOR) || it->value != ")") {
            // Handle error: expected ')'
        } else {
            ++it;
        }
        return node;
    }


    Node* parse_enum(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::ENUM);
        ++it;  // Consume 'enum'
        if (is_type(*it, IDENTIFIER)) {
            node->children.push_back(new Node(NodeType::LITERAL_NODE, it->value));
            ++it;
        } else {
            // Handle error: expected identifier
        }
        while (it != end && is_type(*it, IDENTIFIER)) {
            node->children.push_back(new Node(NodeType::LITERAL_NODE, it->value));
            ++it;
        }
        return node;
    }

    Node* parse_struct(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::STRUCT);
        ++it;  // Consume 'struct'
        if (is_type(*it, IDENTIFIER)) {
            node->children.push_back(new Node(NodeType::LITERAL_NODE, it->value));
            ++it;
        } else {
            // Handle error: expected identifier
        }
        std::vector<Node*> members;
        parse_block(it, end, members);
        node->children.insert(node->children.end(), members.begin(), members.end());
        return node;
    }


    Node* parse_class(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
        Node* node = new Node(NodeType::CLASS);
        ++it;  // Consume 'class'
        if (is_type(*it, IDENTIFIER)) {
            node->children.push_back(new Node(NodeType::LITERAL_NODE, it->value));
            ++it;
        } else {
            // Handle error: expected identifier
        }
        std::vector<Node*> members;
        parse_block(it, end, members);
        node->children.insert(node->children.end(), members.begin(), members.end());
        return node;
    }




    Node* parse() {
        Node* root = new Node(NodeType::ROOT);
        std::vector<Token>::iterator it = tokens.begin();
        std::vector<Token>::iterator end = tokens.end();

        while (it != end) {
            if (is_type(*it, IDENTIFIER)) {
                root->children.push_back(parse_assignment(it, end));
            } else if (is_type(*it, KEYWORD)) {
                if (it->value == "if") {
                    root->children.push_back(parse_if_statement(it, end));
                } else if (it->value == "while") {
                    root->children.push_back(parse_while_loop(it, end));
                } else if (it->value == "print") {
                    root->children.push_back(parse_print_statement(it, end));
                } else if (it->value == "import") {
                    std::cout<<"import found"<<std::endl;
                    root->children.push_back(parse_import(it, end));
                } else if (it->value == "enum") {
                    root->children.push_back(parse_enum(it, end));
                } else if (it->value == "struct") {
                    root->children.push_back(parse_struct(it, end));
                } else if (it->value == "class") {
                    root->children.push_back(parse_class(it, end));
                }
            } else if (is_type(*it, OPERATOR)) {
                if (it->value == "{") {
                    root->children.push_back(parse_array(it, end));
                } else if (it->value == "[") {
                    root->children.push_back(parse_list(it, end));
                } else if (it->value == "(") {
                    root->children.push_back(parse_tuple(it, end));
                } else {
                    ++it;
                }
            } 
                ++it;
            
        }//end of while

        return root;
    }


    

};//end of parser







bool Parser::is_type(const Token& token, TokenType type) {
    return token.type == type;
}

bool Parser::is_any_type(const Token& token, std::vector<TokenType> types) {
    for (TokenType type : types) {
        if (token.type == type) {
            return true;
        }
    }
    return false;
}

bool Parser::consume(std::vector<Token>::iterator& it, std::vector<Token>::iterator end, TokenType type) {
    if (it == end || !is_type(*it, type)) {
        return false;
    }
    ++it;
    return true;
}




Node* Parser::parse_expression(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
    Node* node = nullptr;
    if (is_type(*it, LITERAL_INT) || is_type(*it, LITERAL_FLOAT) || is_type(*it, LITERAL_DOUBLE) ||
        is_type(*it, LITERAL_STRING) || is_type(*it, LITERAL_CHAR)) {
        node = new Node(NodeType::LITERAL_NODE, it->value);
        ++it;
    } else if (is_type(*it, IDENTIFIER)) {
        node = new Node(NodeType::VARIABLE, it->value);
        ++it;
    } else {
        // Handle error: invalid expression
    }
    return node;
}

void Parser::parse_block(std::vector<Token>::iterator& it, std::vector<Token>::iterator end, std::vector<Node*>& body) {
    while (it != end && !is_type(*it, DEDENT)) {
        if (is_type(*it, IDENTIFIER)) {
            body.push_back(parse_assignment(it, end));
        } else if (is_type(*it, KEYWORD)) {
            if (it->value == "if") {
                body.push_back(parse_if_statement(it, end));
            } else if (it->value == "while") {
                body.push_back(parse_while_loop(it, end));
            } else if (it->value == "print") {
                body.push_back(parse_print_statement(it, end));
            }
        } else if (is_type(*it, INDENT)) {
            ++it;
        } else {
            ++it;
        }
    }
}

Node* Parser::parse_while_loop(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
    Node* node = new Node(NodeType::WHILE_LOOP);
    ++it;  // Consume 'while'
    node->children.push_back(parse_expression(it, end));
    std::vector<Node*> body;
    parse_block(it, end, body);
    node->children.insert(node->children.end(), body.begin(), body.end());
    return node;
}

Node* Parser::parse_print_statement(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
    Node* node = new Node(NodeType::PRINT);
    ++it;  // Consume 'print'
    if (!consume(it, end, OPERATOR) || it->value != "(") {
        // Handle error: expected '('
        return node;
    }
    ++it;
    node->children.push_back(parse_expression(it, end));
    if (!consume(it, end, OPERATOR) || it->value != ")") {
        // Handle error: expected ')'
        return node;
    }
    ++it;
    return node;
}


Node* Parser::parse_assignment(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
    Node* node = new Node(NodeType::VARIABLE, it->value);
    ++it;
    if (!consume(it, end, OPERATOR) || it->value != "=") {
        // Handle error: expected '='
        return node;
    }
    ++it;
    node->children.push_back(parse_expression(it, end));
    return node;
}

Node* Parser::parse_if_statement(std::vector<Token>::iterator& it, std::vector<Token>::iterator end) {
    Node* node = new Node(NodeType::IF_LOOP);
    ++it;  // Consume 'if'
    node->children.push_back(parse_expression(it, end));
    std::vector<Node*> body;
    parse_block(it, end, body);
    node->children.insert(node->children.end(), body.begin(), body.end());
    if (consume(it, end, KEYWORD) && it->value == "else") {
        ++it;
        std::vector<Node*> else_body;
        parse_block(it, end, else_body);
        node->children.insert(node->children.end(), else_body.begin(), else_body.end());
    }
    return node;
}





// Implementations for parse_while_loop, parse_print_statement, parse_expression, parse_block, etc.



// You can now traverse the AST or perform further analysis or code generation

// ... (implementations for other parsing methods)

#endif
