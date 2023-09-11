/*
<6 kyu> Tortoise racing
https://www.codewars.com/kata/55e2adece53b4cdcb900006c
*/

#include <iostream>
#include <vector>
#include <cmath>

class Tortoise {
public:
    static std::vector<int> race(int v1, int v2, int g) {
        std::vector<int> time;
        if (v1 >= v2) {
            time = {-1, -1, -1};
        } else {
            float speed = v2 - v1;
            int hour = floor(g / speed);
            int min = floor(g / speed * 60) - hour * 60;
            int sec = floor(g / speed * 60 * 60) - min * 60 - hour * 60 * 60;
            time = {hour, min, sec};
        }
        return time;
    }
};

int main() {

    Tortoise myObj;

    for (auto x : myObj.race(720, 850, 70)) {
        std::cout << x << " ";
    } // "0 32 18"
    std::cout << std::endl;

    for (auto x : myObj.race(80, 91, 37)) {
        std::cout << x << " ";
    } // "3 21 49"
    std::cout << std::endl;

    return 0;
}