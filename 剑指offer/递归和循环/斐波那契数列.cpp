/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 
 * n<=39
 */
#include <iostream>
 
 class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 1) return n;

        int i = 0;
        int j = 1;
        int res = 0;

        for(int k=2; k<=n; ++k) {
            res = i + j;
            i = j;
            j = res;
        }

        return res;

    }
};