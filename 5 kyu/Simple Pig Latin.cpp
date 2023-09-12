/*
<5 kyu> Simple Pig Latin
https://www.codewars.com/kata/520b9d2ad5c005041100000f
*/

#include <iostream>     // std::cout
#include <string>       // std::string
#include <sstream>      // std::stringstream

std::string pig_it (std::string str) {
    std::stringstream ss(str);
    std::string word;
    std::string result;
    while (ss >> word) {
        if ((word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z')) {
            word.push_back(word[0]);
            word += "ay";
            word.erase(0, 1);
        }
        result += word + ' ';
    }
    result.pop_back();
    return result;
}

int main() {

    std::cout << pig_it("Pig latin is cool") << std::endl; // igPay atinlay siay oolcay
    std::cout << pig_it("Hello world !") << std::endl; // elloHay orldway !

    return 0;
}