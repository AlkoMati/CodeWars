/*
<7 kyu> Valid Parentheses
https://www.codewars.com/kata/6411b91a5e71b915d237332d
*/

#include <iostream>
#include <string>

bool validParentheses(const std::string& str) {
    // check first parenthese
    if (str[0] == ')') {
        return false;
    }
    // count parentheses
    int count = 0;
    for (char x : str) {
        x == '(' ? count++ : count--;
        if (count < 0) return false;
    }
    // last check
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {

    std::cout << validParentheses("()") << std::endl; // true
    std::cout << validParentheses(")(()))") << std::endl; // false
    std::cout << validParentheses("(") << std::endl; // false
    std::cout << validParentheses("(())((()())())") << std::endl; // true
    std::cout << validParentheses("())(()") << std::endl; // false

    return 0;
}