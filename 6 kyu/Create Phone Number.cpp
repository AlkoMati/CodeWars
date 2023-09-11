/*
<6 kyu> Create Phone Number
https://www.codewars.com/kata/525f50e3b73515a6db000b83
*/

#include <iostream>
#include <string>

std::string createPhoneNumber(const int arr[10]) {
    std::string number = "";
    for (int i = 0; i < 10; i++) {
        number += std::to_string(arr[i]);
    }
    number.insert(0, "(");
    number.insert(4, ") ");
    number.insert(9, "-");
    return number;
}

int main() {

    int phone1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(phone1) << std::endl; // "(123) 456-7890"

    int phone2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << createPhoneNumber(phone2) << std::endl; // "(111) 111-1111"

    int phone3[10] = {1, 2, 3, 4, 5, 6, 8, 8, 0, 0};
    std::cout << createPhoneNumber(phone3) << std::endl; // "(123) 456-8800"

    int phone4[10] = {0, 2, 3, 0, 5, 6, 0, 8, 9, 0};
    std::cout << createPhoneNumber(phone4) << std::endl; // "(023) 056-0890"

    int phone5[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << createPhoneNumber(phone5) << std::endl; // "(000) 000-0000"

    return 0;
}