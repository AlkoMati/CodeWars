/*
<4 kyu> Human readable duration format
https://www.codewars.com/kata/52742f58faf5485cae000b9a
*/

#include <iostream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {

    std::string result;
    int time = seconds;
    std::vector<std::pair<std::string, int>> array = {
        {"year", 60*60*24*365},
        {"day", 60*60*24},
        {"hour", 60*60},
        {"minute", 60},
        {"second", 1}
    };

    if (seconds == 0) {
        result += "now, ";
    } else {
        for (auto data : array) {
            if (seconds > 0) {
                int number = seconds / data.second;
                if (number != 0) {
                    result += std::to_string(number) + " " + data.first + ((number > 1) ? "s, " : ", ");
                    seconds -= number * data.second;
                }
            }
        }
    }

    result = result.substr(0, result.size()-2);

    // change last sign "," to " and"
    std::size_t found = result.find_last_of(",");
    if (found <= time) {    
        result = result.replace(result.find_last_of(","), 1, " and");
    }

    return result;
}

int main() {

    std::cout << format_duration(0) << std::endl; // result is "now"
    std::cout << format_duration(1) << std::endl; // result is "1 second"
    std::cout << format_duration(62) << std::endl; // result is "1 minute and 2 seconds"
    std::cout << format_duration(120) << std::endl; // result is "2 minutes"
    std::cout << format_duration(3662) << std::endl; // result is "1 hour, 1 minute and 2 seconds"

    return 0;
}