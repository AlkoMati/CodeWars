/*
<6 kyu> Mexican Wave
https://www.codewars.com/kata/58f5c63f1e26ecda7e000029
*/

#include <iostream>
#include <vector>

std::vector<std::string> wave(std::string y) {
    std::vector<std::string> text;
    int length = y.length();
    for (int i = 0; i < length; i++) {
        std::string word = y;
        if (!isspace(word[i])) {
            word[i] = (char) toupper(word[i]);
            text.push_back(word);
        }
    }
    return text;
}

int main() {

    for (auto x : wave("hello")) {
        std::cout << x << " ";
    }

    return 0;
}