/*
<5 kyu> Moving Zeros To The End
https://www.codewars.com/kata/52597aa56021e91c93000cb0
*/

#include <iostream>
#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> result;
    int i = 0;
    for (auto x : input) {
        if (x != 0) {
            result.push_back(x);
        } else {
            i++;
        }
    }
    for (int j = 1; j <= i; j++) {
        result.push_back(0);
    }
    return result;
}

int main() {

    for (auto x : move_zeroes({1, 0, 1, 2, 0, 1, 3})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : move_zeroes({0, 0, 0, 0, 0, 0})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto x : move_zeroes({1, 2, 5, 1, 5, 1, 5, 3, 2, 1})) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}