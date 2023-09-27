/*
<5 kyu> Scramblies
https://www.codewars.com/kata/55c04b4cc56a697bb0000048
*/

#include <iostream>
#include <string>
#include <map>
// #include <algorithm>

bool scramble (const std::string& s1, const std::string& s2) {

    std::map <char, int> map;
    for (unsigned long i = 0; i < s1.size(); i++) {
        if (map[s1[i]] > 0) {
            map[s1[i]]++;
        } else {
            map[s1[i]] = 1;
        }
    }
    for (unsigned long i = 0; i < s2.size(); i++) {
        if (map[s2[i]] > 0) {
            map[s2[i]]--;
        } else {
            return false;
        }
    }

/*
    // best practice
    std::string str1 = s1;
    std::string str2 = s2;
    std::sort(begin(str1), end(str1));
    std::sort(begin(str2), end(str2));
    return std::includes(begin(str1), end(str1), begin(str2), end(str2));

    // use found algorithm
    std::string temp = s1;
    for (unsigned long i = 0; i < s2.size(); i++) {
        std::size_t found = temp.find(s2[i]);
        if (found == std::string::npos) {
            return false;
        } else {
            temp.erase(found, 1);
        }
    }

    // normal search
    std::string temp = s1;
    for (unsigned long i = 0; i < s2.size(); i++) {
        for (unsigned long j = 0; j < temp.size(); j++) {
            if (s2[i] == temp[j]) {
                temp.erase(j, 1);
                break;
            } else if (j == temp.size() - 1) {
                return false;
            }
        }
    }
*/
    return true;
}

int main() {

    std::cout << scramble("rkqodlw", "world") << std::endl; // true
    std::cout << scramble("cedewaraaossoqqyt", "codewars") << std::endl; // true
    std::cout << scramble("katas", "steak") << std::endl; // false
    std::cout << scramble("scriptjavx", "javascript") << std::endl; // false
    std::cout << scramble("scriptingjava", "javascript") << std::endl; // true
    std::cout << scramble("scriptsjava", "javascript") << std::endl; // true
    std::cout << scramble("javscripts", "javascript") << std::endl; // false
    std::cout << scramble("aabbcamaomsccdd", "commas") << std::endl; // true
    std::cout << scramble("commas", "commas") << std::endl; // true
    std::cout << scramble("sammoc", "commas") << std::endl; // true

    return 0;
}