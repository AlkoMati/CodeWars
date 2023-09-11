/*
<8 kyu> Square(n) Sum
https://www.codewars.com/kata/515e271a311df0350d00000f
*/

#include <iostream>
#include <vector>

int square_sum(const std::vector<int>& numbers) {
    int sum = 0;
    for (auto x : numbers) {
        sum += x * x;
    }
    return sum;
}

int main() {

    std::cout << square_sum({1, 2, 2}) << std::endl;

    return 0;
}