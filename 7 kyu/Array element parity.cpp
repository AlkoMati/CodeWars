/*
<7 kyu> Array element parity
https://www.codewars.com/kata/5a092d9e46d843b9db000064
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solve (std::vector<int> v){
    int result = 0;
    for (int x : v) {
        int search = -x;
        if (std::find(v.begin(), v.end(), search) == v.end()) {
            result = x;
        }
    }
    return result;
}

int main() {

    std::cout << solve({1, -1, 2, -2, 3}) << std::endl; // 3
    std::cout << solve({-3, 1, 2, 3, -1, -4, -2}) << std::endl; // -4
    std::cout << solve({1, -1, 2, -2, 3, 3}) << std::endl; // 3

    return 0;
}