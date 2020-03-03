/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 */
/**
 * 思路：
 * 可以使用动态规划，设数组count[k]表示跳上一个k即的台阶的跳法种数，则count[n]=count[n-1]+count[n-2]
 */
#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2) return number;
        int i = 1;
        int j = 2;
        int res = 0;

        for(int k=2; k<number; ++k) {
            res = i + j;
            i = j;
            j = res;
        }

        return res;
    }
};