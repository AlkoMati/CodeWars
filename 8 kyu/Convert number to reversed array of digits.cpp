/*
<8 kyu> Convert number to reversed array of digits
https://www.codewars.com/kata/5583090cbe83f4fd8c000051
*/

#include <iostream>
#include <vector>

std::vector<int> digitize(unsigned long n) {        
    int number = std::to_string(n).length();
    std::vector<int> vec;
    for (int i = number; i > 0; i--) {
        vec.push_back(n % 10);
        n /= 10;
    }
    return vec;
}

int main() {

    for (auto x : digitize(35231)) {
        std::cout << x << " ";
    }

    return 0;
}