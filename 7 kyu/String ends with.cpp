/*
<7 kyu> String ends with?
https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d
*/

#include <iostream>
#include <string>
bool solution(std::string const &str, std::string const &ending) {
    if (str.length() >= ending.length()) {
        if (str.compare(str.length() - ending.length(), ending.length(), ending) == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {

    std::cout << solution("abcde", "cde") << std::endl; // true
    std::cout << solution("abcde", "abc") << std::endl; // false
    std::cout << solution("abc", "") << std::endl; // true

    return 0;
}