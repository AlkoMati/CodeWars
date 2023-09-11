/*
<6 kyu> Sums of Parts
https://www.codewars.com/kata/5ce399e0047a45001c853c2b
*/

#include <iostream>
#include <vector>

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
    size_t n = ls.size();
    std::vector<unsigned long long> sums(n + 1, 0);
    unsigned long long m = 0;
    while (n--) {
        sums[n] = m += ls[n];
    }
    return sums;
}

int main() {

    for (auto x : partsSum({0, 1, 3, 6, 10})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : partsSum({1, 2, 3, 4, 5, 6})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : partsSum({744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}