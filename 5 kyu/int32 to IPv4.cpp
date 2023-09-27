/*
<5 kyu> int32 to IPv4
https://www.codewars.com/kata/52e88b39ffb6ac53a400022e
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::string uint32_to_ip(uint32_t ip) {
    std::string result;
    // binary representation
    std::string bin;
    for (int i = 0; i < 32; i++) {
        bin += std::to_string(ip % 2);
        ip /= 2;
    }
    std::reverse(bin.begin(), bin.end());
    // convert to ip
    int number = 0, count = 1;
    for (int i = 0; i < 32; i++) {
        number += int(bin[i] - '0') * 128 / std::pow(2, count - 1);
        if (count % 8 == 0) {
            result += std::to_string(number) + ".";
            number = 0;
            count = 0;
        }
        count++;
    }
    result.pop_back();
    return result;
}

// std::string uint32_to_ip(uint32_t ip) {
//     return std::to_string(ip >> 24 & 255) + "." + 
//            std::to_string(ip >> 16 & 255) + "." +
//            std::to_string(ip >> 8 & 255) + "." +
//            std::to_string(ip & 255);
// }

int main() {

    std::cout << uint32_to_ip(2149583361) << std::endl; // "128.32.10.1"
    std::cout << uint32_to_ip(32) << std::endl; // "0.0.0.32"
    std::cout << uint32_to_ip(0) << std::endl; // "0.0.0.0"

    return 0;
}