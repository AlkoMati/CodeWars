/*
<4 kyu> So Many Permutations!
https://www.codewars.com/kata/5254ca2719453dcc0b00027d
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> permutations(std::string s) {
    std::vector<std::string> result;
    std::sort(s.begin(), s.end());
    do result.push_back(s);
    while (std::next_permutation(s.begin(), s.end()));
    return result;
}

int main() {

    for (auto x : permutations("a")) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : permutations("ab")) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : permutations("aabb")) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}