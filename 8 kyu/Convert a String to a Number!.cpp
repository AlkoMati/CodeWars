/*
<8 kyu> Convert a String to a Number!
https://www.codewars.com/kata/544675c6f971f7399a000e79
*/

#include <iostream>
#include <string>

int string_to_number(const std::string& s) {
    int number = stoi(s);
    return number;
}

int main() {

    std::cout << string_to_number("123456") << std::endl;
    std::cout << string_to_number("352605") << std::endl;
    std::cout << string_to_number("321405") << std::endl;
    std::cout << string_to_number("-7") << std::endl;
    std::cout << string_to_number("0") << std::endl;
    std::cout << string_to_number("-0") << std::endl;

    return 0;
}