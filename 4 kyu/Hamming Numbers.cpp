/*
<4 kyu> Hamming Numbers
https://www.codewars.com/kata/526d84b98f428f14a60008da
*/

#include <iostream>
#include <cstdint> // alternative use: typedef unsigned long long uint64_t;
#include <algorithm>
#include <vector>

uint64_t hamber (int n) {
    const uint64_t umax = 0xFFFFFFFFFFFFFFFF; // max range hex
    // create vector with all Hamming numbers
    std::vector<uint64_t> vec;
    for (uint64_t k = 1;; k *= 2) {
        for (uint64_t l = k;; l *= 3) {
            for (uint64_t m = l;; m *= 5) {
                vec.push_back(m);
                if (m > umax / 5) break;
            }
            if (l > umax / 3) break;
        }
        if (k > umax / 2) break;
    }
    std::sort(vec.begin(), vec.end());
    return vec[n-1];
}

int main() {

    std::cout << hamber(11) << std::endl; // 15
    std::cout << hamber(20) << std::endl; // 36
    std::cout << hamber(50) << std::endl; // 243
    std::cout << hamber(62) << std::endl; // 405
    std::cout << hamber(260) << std::endl; // 46656
    std::cout << hamber(1701) << std::endl; // 2239488000
    std::cout << hamber(2810) << std::endl; // 153055008000
    std::cout << hamber(2644) << std::endl; // 87890625000

    return 0;
}