/*
<7 kyu> Highest and Lowest
https://www.codewars.com/kata/554b4ac871d6813a03000035
*/

#include <iostream>
#include <string>
#include <sstream>

std::string highAndLow(const std::string& numbers) {
    int high;
    int low;
    std::istringstream is(numbers);
    int n;
    int i = 0;
    while (is >> n) {
        if (i == 0) {
            high = n;
            low = n;
        }
        if (n > high) {
            high = n;
        }
        if (n < low) {
            low = n;
        }
        i++;
    }
    std::string highString = std::to_string(high);
    std::string lowString = std::to_string(low);
    return highString + " " + lowString;
}

int main() {

    std::cout << highAndLow("1 2 3 4 5") << std::endl;  // return "5 1"
    std::cout << highAndLow("1 2 -3 4 5") << std::endl; // return "5 -3"
    std::cout << highAndLow("1 9 3 4 -5") << std::endl; // return "9 -5"

    return 0;
}