/*
<6 kyu> Imaginary Base Conversion
https://www.codewars.com/kata/583a47342fb0ba1418000060
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<int> convert(std::string n) {
	std::vector<int> ans(2);
	for (int i = 0; i < n.length(); i++) {
		if (n[n.length() - i - 1] == '1') {
            ans[i & 1] += i % 4 > 1 ? -1 : 1;
        }
    }
	return ans;
}

int main() {

    for (int i = 0; i < convert("1111000110110000110").size(); i++) {
        std::cout << convert("1111000110110000110")[i] << " ";
    }

    return 0;
}