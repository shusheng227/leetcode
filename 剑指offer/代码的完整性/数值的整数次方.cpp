/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 保证base和exponent不同时为0
 */
#include <iostream>

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0) return 1;
        if(base == 0) return 0;
        double res = 1;
        if(exponent > 0) {
            for(int i=0; i<exponent; ++i) res *= base;
        }
        else {
            for(int i=0; i<-exponent; ++i) res /= base;
        }
        
        return res;
    }
};
