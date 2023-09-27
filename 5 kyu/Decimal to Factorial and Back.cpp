/*
<5 kyu> Decimal to Factorial and Back
https://www.codewars.com/kata/54e320dcebe1e583250008fd
*/

#include <iostream>
#include <string>

class Dec2Fact {
public:
    // decimal number encoded to factorial string
    static std::string dec2FactString (long long nb) {
        std::string result;
        int i = 1;
        std::string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while (nb != 0) {
            result = letters[(nb % i)] + result;
            nb /= i;
            i++;
        }
        return result;
    }
    // factorial string decoded to number
    static long long factString2Dec (const std::string &str) {
        long long result = 0;
        std::string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int size = str.size();
        for (int i = 0; i < size; i++) {
            long long n = 1;
            // factorial calculation
            for (int j = 1; j <= size - 1 - i; j++) {
                n *= j;
            }
            size_t found = letters.find(str[i]);
            result += found * n;
        }
        return result;
    }
};

int main() {

    Dec2Fact myObj;

    std::cout << myObj.dec2FactString (463) << std::endl; // 341010
    std::cout << myObj.dec2FactString (2982) << std::endl; // 4041000
    std::cout << myObj.dec2FactString (36288000) << std::endl; // A0000000000
    std::cout << myObj.dec2FactString (999999999) << std::endl; // 2105644512110

    std::cout << myObj.dec2FactString (3595156160) << std::endl; // 7607244231100
    std::cout << myObj.factString2Dec ("7607244231100") << std::endl; // 3595156160

    std::cout << myObj.factString2Dec ("13573044440000") << std::endl; // 7890123456

    return 0;
}