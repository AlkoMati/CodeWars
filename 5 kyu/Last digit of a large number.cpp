/*
<5 kyu> Last digit of a large number
https://www.codewars.com/kata/5511b2f550906349a70004e1
*/

#include <iostream>
#include <string>

int last_digit (const std::string &str1, const std::string &str2) {

    int last [10][4] = {
        {0, 0, 0, 0}, // 0
        {1, 1, 1, 1}, // 1
        {6, 2, 4, 8}, // 2
        {1, 3, 9, 7}, // 3
        {6, 4, 6, 4}, // 4
        {5, 5, 5, 5}, // 5
        {6, 6, 6, 6}, // 6
        {1, 7, 9, 3}, // 7
        {6, 8, 4, 2}, // 8
        {1, 9, 1, 9}  // 9
      // 0  1  2  3
    };

    if (str2 == "0") {
        return 1;
    }

    int row = str1[str1.size() - 1] - 48;
    int column;
    if (str2.size() > 2) {
        column = std::stoi(str2.substr(str2.size() - 2)) % 4;
    } else {
        column = std::stoi(str2) % 4;
    }

    return last[row][column];
}

int main() {

    std::string str1 = "1606938044258990275541962092341162602522202993782792835301376";
    std::string str2 = "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376";

    std::cout << last_digit(str1, str2);

    return 0;
}