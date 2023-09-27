/*
<5 kyu> String incrementer
https://www.codewars.com/kata/54a91a4883a7de5d7800009c
*/

#include <iostream>
#include <string>

std::string incrementString (const std::string &str) {
    std::string result = str;
    // empty
    if (result.empty()) return "1";
    for (int i = result.size() - 1; i >= 0; i--) {
        // char == 9
        if (result[i] == '9') {
            result[i] = '0';
        } else {
            // char 0-8
            if (result[i] < '9') {
                result[i]++;
                break;
            }
            // no number
            if (result[i] > '9') {
                result.insert(i + 1, "1");
                break;
            }
        }
    }
    return result;
}

int main() {

    std::cout << incrementString("foo") << std::endl; // foo1
    std::cout << incrementString("foobar23") << std::endl; // foobar24
    std::cout << incrementString("foo0042") << std::endl; // foo0043
    std::cout << incrementString("foo9") << std::endl; // foo10
    std::cout << incrementString("foo099") << std::endl; // foo100
    std::cout << incrementString("") << std::endl; // 1
    std::cout << incrementString("oyxhcxizjhmlxakkwljpqqnhhzjrzqoj318") << std::endl; // oyxhcxizjhmlxakkwljpqqnhhzjrzqoj319

    return 0;
}