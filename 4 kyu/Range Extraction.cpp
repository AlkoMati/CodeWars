/*
<4 kyu> Range Extraction
https://www.codewars.com/kata/51ba717bb08c1cd60f00002f
*/

#include <iostream>
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
    int size = args.size();
    std::string result;

    for (int i = 0; i < size; i++) {
        int count = 1;

        if (args[i] == args[i + count] - count) {
            int temp_begin;
            int temp_end;

            do {
                temp_begin = args[i];
                temp_end = args[i + count];
                count++;
            } while (args[i] == args[i + count] - count);

            i += count - 1;
            result += std::to_string(temp_begin) + ((count == 2) ? "," : "-") + std::to_string(temp_end) + ",";
        
        } else {
            result += std::to_string(args[i]) + ",";
        }      
    }
    
    return result.substr(0, result.size()-1);
}

int main() {

    std::cout << range_extraction({-10,-9,-8,-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}) << std::endl; //  returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
    std::cout << range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}) << std::endl; //  returns "-6,-3-1,3-5,7-11,14,15,17-20"
    std::cout << range_extraction({-3,-2,-1,2,10,15,16,18,19,20}) << std::endl; //  returns "-3--1,2,10,15,16,18-20"

    return 0;
}