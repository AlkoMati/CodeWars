/*
<6 kyu> Who likes it?
https://www.codewars.com/kata/5266876b8f4bf2da9b000362
*/

#include <iostream>
#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &names) {
    switch (names.size()) {
        case 0: return "no one likes this";
        case 1: return names[0] + " likes this";
        case 2: return names[0] + " and " + names[1] + " like this";
        case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

int main() {

    std::cout << likes({}) << std::endl; // "no one likes this"
    std::cout << likes({"Peter"}) << std::endl; // "Peter likes this"
    std::cout << likes({"Jacob", "Alex"}) << std::endl; // "Jacob and Alex like this"
    std::cout << likes({"Max", "John", "Mark"}) << std::endl; // "Max, John and Mark like this"
    std::cout << likes({"Alex", "Jacob", "Mark", "Max"}) << std::endl; // "Alex, Jacob and 2 others like this"

    return 0;
}