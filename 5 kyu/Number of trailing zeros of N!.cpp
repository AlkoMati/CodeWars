/*
<5 kyu> Number of trailing zeros of N!
https://www.codewars.com/kata/52f787eb172a8b4ae1000a34
*/

#include <iostream>
#include <cmath>

long zeros (long n) {
    int count = 0;
    long max = 0;
    // count 5^i < n
    if (n >= 5) {
        for (int i = 1; max < n; i++) {
            max = pow(5, i);
            if (max < n) {
                count = i;
            } 
        }
    }
    int zeros = 0;
    // count zeros
    for (int i = 1; i <= count; i++) {
        zeros += std::floor(n / pow(5, i));
    }
    return zeros;
}

int main() {

    std::cout << zeros(0) << std::endl; // 0
    std::cout << zeros(6) << std::endl; // 1
    std::cout << zeros(30) << std::endl; // 7
    std::cout << zeros(100) << std::endl; // 24
    std::cout << zeros(1000) << std::endl; // 249
    std::cout << zeros(100000) << std::endl; // 24999
    std::cout << zeros(1000000000) << std::endl; // 249999998

    return 0;
}