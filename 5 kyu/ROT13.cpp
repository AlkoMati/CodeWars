/*
<5 kyu> ROT13
https://www.codewars.com/kata/52223df9e8f98c7aa7000062
*/

#include <iostream>
#include <string>

std::string rot13 (const std::string& str) {
    std::string input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    std::string result;
    for (auto x : str) {
        if (isalpha(x)) {
            std::size_t found = input.find(x);
            result += output[found];
        } else {
            result += x;
        }
    }
    return result;
}

/*
// best practice
std::string rot13 (std::string msg) {
    for (auto& x : msg) {
        if (islower(x)) x = 'a' + (x - 'a' + 13) % 26; 
        else if (isupper(x)) x = 'A' + (x - 'A' + 13) % 26;
    }
    return msg;
}
*/

int main() {

    std::cout << rot13("EBG13 rknzcyr.") << std::endl; // "ROT13 example."
    std::cout << rot13("This is my first ROT13 excercise!") << std::endl; // "Guvf vf zl svefg EBG13 rkprepvfr!""
    std::cout << rot13("Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.") << std::endl;

    return 0;
}