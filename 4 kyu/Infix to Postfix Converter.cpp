/*
<4 kyu> Infix to Postfix Converter
https://www.codewars.com/kata/52e864d1ffb6ac25db00017f
*/

#include <iostream>
#include <string>
#include <map>

std::string to_postfix(std::string infix) {

    std::string result;
    std::string stack;

    std::map <char, int> map = {
        {'(', 0},
        {'+', 1}, {'-', 1}, {')', 1},
        {'*', 2}, {'/', 2}, {'%', 2},
        {'^', 3}
    };

    for(auto x : infix) {
        if (std::isdigit(x) != 0) {
            result += x;
        } else {
            if (x == '(' || map[x] > map[stack.back()] || x == '^') {
                stack += x;
            }
            else if (x == ')') {
                do {
                    result += stack.back();
                    stack.pop_back();
                } while (stack.back() != '(');
                stack.pop_back();
            }
            else if (map[stack.back()] >= map[x] && x != '^') {
                do {
                    result += stack.back();
                    stack.pop_back();
                } while (map[stack.back()] >= map[x]);
                stack += x;
            }
        }
    }

    for (int i = stack.size(); i >= 0; i--) {
        if (stack[i] > 0) {
            result.push_back(stack[i]);
        }
    }

    return result;
}

int main() {

    std::cout << to_postfix("2+7*5") << std::endl; // Should return "275*+"
    std::cout << to_postfix("3*3/(7+1)") << std::endl; // Should return "33*71+/"
    std::cout << to_postfix("5+(6-2)*9+3^(7-1)") << std::endl; // Should return "562-9*+371-^+"
    std::cout << to_postfix("1^2^3") << std::endl; // Should return "123^^"

    return 0;
}