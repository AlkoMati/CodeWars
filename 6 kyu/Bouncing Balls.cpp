/*
<6 kyu> Bouncing Balls
https://www.codewars.com/kata/5544c7a5cb454edb3c000047
*/

#include <iostream>
#include <string>
#include <cmath>

class Bouncingball {
public:
    static int bouncingBall(double h, double bounce, double window) {
        int result;
        if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) {
            result = -1;
        } else {
            result = 1;
            do {
                h = h * bounce;
                if (h > window) {
                    result += 2;
                }
            } while (h > window);
        }
        return result;
    }
};

int main() {

    Bouncingball myObj;

    std::cout << myObj.bouncingBall(3, 0.66, 1.5) << std::endl; // result is 3
    std::cout << myObj.bouncingBall(3, 1, 1.5) << std::endl; // result is -1 
    std::cout << myObj.bouncingBall(30, 0.66, 1.5) << std::endl; // result is 15

    return 0;
}