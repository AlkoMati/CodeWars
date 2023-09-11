/*
<4 kyu> Sum Strings as Numbers
https://www.codewars.com/kata/5324945e2ece5e1f32000370
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

std::string sum_strings(const std::string& a, const std::string& b) {
    std::string result;
    std::string temp1 = a;
    std::string temp2 = b;
    // longer test
    int size;
    if (a.size() > b.size()) {
        size = a.size();
    } else {
        size = b.size();
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        // sum two numbers or set one number
        if (temp1.back() > 0 && temp2.back() > 0) {
            sum += int(temp1.back() - '0') + int(temp2.back() - '0');
            temp1.pop_back();
            temp2.pop_back();
        } else {
            if (temp1.back() > 0) {
                sum += int(temp1.back() - '0');
                temp1.pop_back();
            } else {
                sum += int(temp2.back() - '0');
                temp2.pop_back();
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
        // to end add last sum value
        if (i == size - 1 && sum > 0) {
            result += std::to_string(sum);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {

    std::string a = "6878877733478076581521128086400388087094430922744283933254550087543272286117699361822533715284232848324341489840505";
    std::string b = "1798049039038050891606632810456457551";

    std::cout << sum_strings(a, b);

    return 0;
}