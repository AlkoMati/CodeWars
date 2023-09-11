/*
<6 kyu> Multiples of 3 or 5
https://www.codewars.com/kata/514b92a657cdc65150000006
*/

#include <iostream>

int solution(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (i % 3 == 0) {
            sum += i;
            continue;
        }
        if (i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {

    std::cout << solution(10) << std::endl; // 23

    return 0;
}