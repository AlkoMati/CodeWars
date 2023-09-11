/*
<4 kyu> Roman Numerals Helper
https://www.codewars.com/kata/51b66044bce5799a7f000003
*/

#include <iostream>
#include <string>
#include <map>

class RomanHelper {
    public:

        int numbers[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        std::string letters[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        std::map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        std::string to_roman(unsigned int n) {
            int size = 12;
            std::string result;
            while (n > 0) {
                int value = n / numbers[size];
                n = n % numbers[size];
                while (value--) {
                    result += letters[size];
                }
                size--;
            }
            return result;
        }

        int from_roman(std::string rn) {
            int result = 0;
            int size = rn.size();
            for (int i = 0; i < size; i++) {
                if (map[rn[i]] < map[rn[i+1]]) {
                    result += map[rn[i+1]] - map[rn[i]];
                    i++;
                    continue;
                }
                result += map[rn[i]];
            }
            return result;
        }
} RomanNumerals;

int main() {

    RomanHelper myObj;

    std::cout << myObj.to_roman(2000) << std::endl; // MM
    std::cout << myObj.to_roman(1666) << std::endl; // MDCLXVI
    std::cout << myObj.to_roman(1000) << std::endl; // M
    std::cout << myObj.to_roman(400) << std::endl; // CD
    std::cout << myObj.to_roman(90) << std::endl; // XC
    std::cout << myObj.to_roman(40) << std::endl; // XL
    std::cout << myObj.to_roman(1) << std::endl; // I

    std::cout << myObj.from_roman("MM") << std::endl; // 2000
    std::cout << myObj.from_roman("MDCLXVI") << std::endl; // 1666
    std::cout << myObj.from_roman("M") << std::endl; // 1000
    std::cout << myObj.from_roman("CD") << std::endl; // 400
    std::cout << myObj.from_roman("XC") << std::endl; // 90
    std::cout << myObj.from_roman("XL") << std::endl; // 40
    std::cout << myObj.from_roman("I") << std::endl; // 1

    return 0;
}