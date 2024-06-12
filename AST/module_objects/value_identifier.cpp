#ifndef _VALUE_IDENTIFIER_
 #define  _VALUE_IDENTIFIER_

  #include <iostream>
  #include <string>
  #include <limits>
#include <cmath>
#include <cfloat>

  bool isInteger(const std::string& str) {
    try {
        std::size_t pos;
        int num = std::stoi(str, &pos);
        // Check if there are any non-numeric characters after the number
        return pos == str.length();
    } catch (std::invalid_argument& e) {
        // Not an integer
        return false;
    } catch (std::out_of_range& e) {
        // Number out of range
        return false;
    }
}




bool isFloat(const std::string& str) {
    if (str.empty() || str.back() != 'f') {
        return false;
    }

    std::string numberPart = str.substr(0, str.size() - 1);
    try {
        std::size_t pos;
        double num = std::stod(numberPart, &pos);

        // Check if there are any non-numeric characters in the number part
        if (pos != numberPart.length()) {
            return false;
        }

        // Check for float range limits explicitly
        if (num < -FLT_MAX || num > FLT_MAX) {
            return false;
        }
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }

    return true;
}






bool isDouble(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    try {
        std::size_t pos;
        double num = std::stod(str, &pos);

        // Check if there are any non-numeric characters in the number part
        if (pos != str.length()) {
            return false;
        }

        // Check for double range limits explicitly
        if (num < -DBL_MAX || num > DBL_MAX) {
            return false;
        }
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }

    return true;
}



int main(int argc , const char* argv[]) {
    std::string testStr1 = argv[1];
    

    std::cout << testStr1 << " is " << (isFloat(testStr1) ? "" : "not ") << "a valid float." << std::endl;
    
    return 0;
}
#endif