/*
<7 kyu> Find the stray number
https://www.codewars.com/kata/57f609022f4d534f05000024
*/

#include <iostream>
#include <vector>
#include <algorithm>

int stray (std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end());
    return numbers[0] == numbers[1] ? numbers.back() : numbers.front();
}

int main() {

    std::cout << stray({1, 1, 2}) << std::endl; // 2
    std::cout << stray({17, 17, 3, 17, 17, 17, 17}) << std::endl; // 3

    return 0;
}