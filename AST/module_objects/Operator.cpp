#ifndef _OPERATOR_
#define  _OPERATOR_

enum Operator{
   //ARITHMATIC_OPERATOR    return type in any number type
   PLUS_OP, // +
   MINUS_OP, // -
   MULTI_OP, // *
   POWER_OP, // **
   DIVIDE_OP, // /
   MOD_OP, // %

   //COMPARISON OPERATOR    return type is boolean
   EQUAL_OP, // ==
   NOT_EQUAL, // !=
   GREATER_THAN_OP, // >
   LESS_THAN_OP, // <
   GREATER_THAN_OR_EQUAL_OP, // >=
   LESS_THAN_OR_EQUAL_OP, // <=

   //LOGICAL OPERATORS return type is boolean
   AND_OP, // &&
   OR_OP, // ||
   NOT_OP, // !
   //BITWISE OP // return type is any number
   AND_BIT_OP, // &
   OR_BIT_OP, // |
   XOR_BIT_OP, // ^
   NOT_BIT_OP,// !
   LEFT_SHIFT_OP, // <<
   RIGHT_SHIFT_OP, // >>


   //ASSIGNMENT OPERATOR return type is depend on either side
   ASSIGN_OP, // =
   ADD_ASSIGN_OP, // +=
   SUB_ASSING_OP, // -=
   MULTI_ASSIGN_OP, // *=
   DIVIDE_ASSIGN_OP, // /=
   MODULUS_ASSIGN_OP, // %=
   POWER_AND_ASSIGN, // **=
   AND_BIT_ASSIGN_OP, // &=
   OR_BIT_ASSIGN_OP, // |=
   XOR_BIT_ASSIGN_OP, // ^=
   LEFT_SHIFT_ASSIGN_OP, // <<=
   RIGHT_SHIFT_ASSIGN_OP, // >>=

};



std::string getOperator(Operator op){
       return "+";
}



#endif