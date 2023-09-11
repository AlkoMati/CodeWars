/*
<8 kyu> You only need one - Beginner
https://www.codewars.com/kata/57cc975ed542d3148f00015b
*/

#include <iostream>
#include <vector>
#include <string>

bool check(const std::vector<std::string>& seq, const std::string& elem) {
    for (auto i : seq) {
        if (i == elem) {
            return true;
        }
    }
    return false;
}

int main() {

    std::cout << check({ }, "a") << std::endl; // false
    std::cout << check({ "a", "b", "c"}, "b") << std::endl; // true
    std::cout << check({ "a", "b", "c" }, "e") << std::endl; // false

    return 0;
}