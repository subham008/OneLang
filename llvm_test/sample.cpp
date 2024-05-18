#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::istringstream iss(sentence);
    std::vector<std::string> words;
    std::string word;

    // Split the sentence into words
    while (iss >> word) {
        words.push_back(word);
    }

    std::cout << "Words in the sentence: " << std::endl;
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}