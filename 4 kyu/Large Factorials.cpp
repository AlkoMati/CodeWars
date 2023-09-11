/*
<4 kyu> Large Factorials
https://www.codewars.com/kata/557f6437bf8dcdd135000010
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

std::string factorial(int factorial) {
    std::string result;
    if (factorial <= 1) {
        return "1";
    }
    for (int i = 2; i <= factorial; i++) {
        if (i == 2) {
            result = "2";
        } else {
            int length = result.length();
            std::string temp = result;
            std::string row;
            std::string array[length];
            // creating rows from multiplication
            for (int j = 0; j < length; j++) {
                int last = int(temp.back() - '0') * i;
                row = std::to_string(last);
                // add 0 to numbers end
                for (int k = 0; k < j; k++) {
                    row += "0";
                }
                array[j] = row;
                temp.pop_back();                
            }
            result = "";
            int sum = 0;
            // longest number 
            for (int j = 0; j < row.size(); j++) {
                // sum numbers in column
                for (int k = 0; k < length; k++) {
                    if (array[k].back() > 0) {
                        sum += int(array[k].back() - '0');
                        array[k].pop_back();
                    }
                }
                // when sum is double
                if (sum > 9) {
                    result += std::to_string(sum % 10);
                    sum = std::floor(sum / 10);
                } else {
                    result += std::to_string(sum);
                    sum = 0;
                }
                // or last
                if (sum > 0 && j == row.size() - 1) {
                    result += std::to_string(sum);
                }
            }
            reverse(result.begin(), result.end());
        }
    }
    return result;
}

int main() {

    int n = 25; // return 15511210043330985984000000

    std::cout << factorial(n);

    return 0;
}