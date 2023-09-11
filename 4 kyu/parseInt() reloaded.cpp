/*
<4 kyu> parseInt() reloaded
https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

long parse_int(std::string number) {

    std::map <std::string, int> data = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19},
        {"twenty", 20},
        {"thirty", 30},
        {"forty", 40},
        {"fifty", 50},
        {"sixty", 60},
        {"seventy", 70},
        {"eighty", 80},
        {"ninety", 90},
        {"hundred", 100},
        {"thousand", 1000},
        {"million", 1000000}
    };

    int i = 0;
    std::vector<std::string> words;
    words.push_back("");
    for (auto x : number) {
        if (x == ' ' || x == '-') {
            i++;
            words.push_back("");
        } else {
            words[i] +=x;
        }
    }
    int cout = i;

    int sum = 0;
    for (int i = 0; i <= cout; i++) {
        if (words[i] == "zero" || words[i] == "million") {
            sum = data[words[i]];
        } else {
            if (i < cout) {
                if (words[i + 1] == "hundred") {
                    sum += data[words[i]] * data[words[i+1]];
                    i++;
                    continue;
                }
            }
            if (words[i] == "thousand") {
                sum *= data[words[i]];
            } else {
                sum += data[words[i]];
            }
        }
    }

    return sum;
}

int main() {

    std::cout << parse_int("one") << std::endl; // 1
    std::cout << parse_int("twenty") << std::endl; // 20
    std::cout << parse_int("two hundred forty-six") << std::endl; // 246
    std::cout << parse_int("seven hundred eighty-three thousand nine hundred and nineteen") << std::endl; // 783919

    return 0;
}