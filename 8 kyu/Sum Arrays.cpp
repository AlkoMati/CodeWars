/*
<8 kyu> Sum Arrays
https://www.codewars.com/kata/53dc54212259ed3d4f00071c
*/

#include <iostream>
#include <vector>

int sum(std::vector<int> nums) {
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    return sum;
}

int main() {

    std::cout << sum({}) << std::endl; // 0
    std::cout << sum({5}) << std::endl; // 5
    std::cout << sum({-5}) << std::endl; // -5
    std::cout << sum({1, 2, 3, 4}) << std::endl; // 10
    std::cout << sum({1, 2, -3, 3, 4}) << std::endl; // 7

    return 0;
}