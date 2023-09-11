/*
<7 kyu> Two to One
https://www.codewars.com/kata/5656b6906de340bd1b0000ac
*/

#include <iostream>
#include <algorithm>

class TwoToOne {
public:
    static std::string longest(const std::string &s1, const std::string &s2) {
        std::string sum = s1 + s2;
        if (sum.length() > 0) {
            std::string sort = sum;
            std::sort(sort.begin(), sort.end());
            char temp;
            std::string result;
            for (int i = 0; i < sort.length(); i++) {
                if (temp != sort[i]) {
                    temp = sort[i];
                    result += sort[i];
                }                
            }
            return result;
        } else {
            return 0;
        }
    }
};

int main() {

    TwoToOne myObj;

    std::cout << myObj.longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << std::endl; // abcdefklmopqwxy
    std::cout << myObj.longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << std::endl; // abcdefghijklmnopqrstuvwxyz

    return 0;
}