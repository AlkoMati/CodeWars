/*
<4 kyu> Multiplying numbers as strings
https://www.codewars.com/kata/55911ef14065454c75000062
*/

#include <iostream>
#include <string>
#include <vector>
 
std::string multiply(std::string a, std::string b) {

    int size1 = a.size();
    int size2 = b.size();
    if (size1 == 0 || size2 == 0) {
        return "0";
    }
 
    std::vector<int> result(size1 + size2, 0);
    int i1 = 0;
    int i2 = 0;

    for (int i = size1 - 1; i >= 0; i--) {
        int temp = 0;
        int n1 = a[i] - '0';
        i2 = 0;
                 
        for (int j = size2 - 1; j >= 0; j--) {
            int n2 = b[j] - '0';
            int sum = n1 * n2 + result[i1 + i2] + temp;
            temp = sum / 10;
            result[i1 + i2] = sum % 10;
            i2++;
        }
 
        if (temp > 0) {
            result[i1 + i2] += temp;
        }
        i1++;
    }
 
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }
 
    if (i == -1) {
        return "0";
    }
 
    std::string number = "";
     
    while (i >= 0) {
        number += std::to_string(result[i--]);
    }
 
    return number;
}

int main() {

    std::cout << multiply("0000001", "3") << std::endl; // result is "3"
    std::cout << multiply("1009", "03") << std::endl; // result is "3027"
    std::cout << multiply("98765", "56894") << std::endl; // result is "5619135910"
    std::cout << multiply("1020303004875647366210", "2774537626200857473632627613") << std::endl; // result is "2830869077153280552556547081187254342445169156730"
    std::cout << multiply("58608473622772837728372827", "7586374672263726736374") << std::endl; // result is "3444625839871840560024489175424316205566214109298"
    std::cout << multiply("9007199254740991", "9007199254740991") << std::endl; // result is "81129638414606663681390495662081"

    return 0;
}