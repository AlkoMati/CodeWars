/*
<4 kyu> Twice linear
https://www.codewars.com/kata/5672682212c8ecf83e000050
*/

#include <iostream>
#include <vector>

class DoubleLinear {
public:
    static int dblLinear(int n) {

        std::vector<int> vec = {1};
        int y = 0, z = 0, count_y = 0, count_z = 0;

        for (int i = 0; i < n; i++) {

            y = 2 * vec[count_y] + 1;
            z = 3 * vec[count_z] + 1;

            if (y > z) {
                vec.push_back(z);
                count_z += 1;
            } else if (y < z) {
                vec.push_back(y);
                count_y += 1;
            } else {
                vec.push_back(y);
                count_y += 1;
                count_z += 1;
            }            
        }

        return vec[n];
    }
};

int main() {

    DoubleLinear myObj;

    std::cout << myObj.dblLinear(10) << std::endl; // 22
    std::cout << myObj.dblLinear(20) << std::endl; // 57
    std::cout << myObj.dblLinear(30) << std::endl; // 91
    std::cout << myObj.dblLinear(50) << std::endl; // 175
    std::cout << myObj.dblLinear(100) << std::endl; // 447
    std::cout << myObj.dblLinear(86057) << std::endl; // 2467102

    return 0;
}