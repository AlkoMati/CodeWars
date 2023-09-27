/*
<5 kyu> RGB To Hex Conversion
https://www.codewars.com/kata/513e08acc600c94f01000001
*/

#include <iostream>
#include <vector>
#include <map>

class RGBToHex {
    public:
    static std::string hex (int number) {
        std::map <int, std::string> map = {
            {10, "A"},
            {11, "B"},
            {12, "C"},
            {13, "D"},
            {14, "E"},
            {15, "F"}
        };
        return number > 9 ? map[number] : std::to_string(number);
    }
    static std::string rgb(int r, int g, int b) {
        std::vector<int> data = {r, g, b};
        std::string result;
        for (int i = 0; i < 3; i++) {
            if (data[i] > 255) {
                result += "FF";
                continue;
            }
            if (data[i] < 1) {
                result += "00";
                continue;
            }
            result += hex(data[i] / 16);
            result += hex(data[i] % 16);
        }
        return result;
  }
};

int main() {

    RGBToHex myObj;

    std::cout << myObj.rgb(255, 255, 255) << std::endl; // FFFFFF
    std::cout << myObj.rgb(255, 255, 300) << std::endl; // FFFFFF
    std::cout << myObj.rgb(0, 0, 0) << std::endl; // 000000
    std::cout << myObj.rgb(148, 0, 211) << std::endl; // 9400D3
    std::cout << myObj.rgb(-20, 275, 125) << std::endl; // 00FF7D

    return 0;
}