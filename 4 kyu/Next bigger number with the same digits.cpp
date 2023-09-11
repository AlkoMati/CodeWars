/*
<4 kyu> Next bigger number with the same digits
https://www.codewars.com/kata/55983863da40caa2c900004e
*/

#include <iostream>
#include <string>
#include <algorithm>

long nextBigger(long n) {
    long result = -1;
    std::string temp = std::to_string (n);
    long number;
    do {
        number = std::stol(temp);
        if (number > n) {
            result = number;
            break;
        } 
    } while (std::next_permutation(temp.begin(), temp.end()));
    return result;
}

int main() {

    long n = 2017;

    std::cout << nextBigger(n);

    return 0;
}