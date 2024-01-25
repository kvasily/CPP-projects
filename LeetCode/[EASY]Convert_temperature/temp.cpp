#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This is the best solution
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double C_to_F = (celsius * 1.80 + 32.00);
        double C_to_K = (celsius + 273.15);

        vector<double> result;
        result.push_back(C_to_K);
        result.push_back(C_to_F);

        return result;

    }
};
// https://leetcode.com/problems/convert-the-temperature/