/*
<8 kyu> Opposites Attract
https://www.codewars.com/kata/555086d53eac039a2a000083
*/

#include <iostream>

bool lovefunc (int f1, int f2) {
    if ((f1 + f2) % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

int main() {

    std::cout << lovefunc(1, 2) << std::endl; // true
    std::cout << lovefunc(0, 3) << std::endl; // true
    std::cout << lovefunc(99, 198) << std::endl; // true

    std::cout << lovefunc(0, 0) << std::endl; // false
    std::cout << lovefunc(2, 2) << std::endl; // false
    std::cout << lovefunc(101, 101) << std::endl; // false

    return 0;
}