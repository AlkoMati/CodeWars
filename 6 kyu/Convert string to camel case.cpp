/*
<6 kyu> Convert string to camel case
https://www.codewars.com/kata/517abf86da9663f1d2000003
*/

#include <iostream>
#include <string>

std::string to_camel_case(std::string text) {
    std::string word;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '-' || text[i] == '_') {
            text[i+1] = toupper(text[i+1]);
            i++;
        }
        word += text[i];
    }
    return word;
}

int main() {

    std::cout << to_camel_case("") << std::endl; // Should return ""
    std::cout << to_camel_case("the_stealth_warrior") << std::endl; // Should return "theStealthWarrior"
    std::cout << to_camel_case("The-Stealth-Warrior") << std::endl; // Should return "TheStealthWarrior"
    std::cout << to_camel_case("A-B-C") << std::endl; // Should return "ABC"

    return 0;
}