/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
/**
 * 思路：
 * 可以使用动态规划，设数组count[k]表示跳上一个k即的台阶的跳法种数，
 * 则count[n]=count[0]+count[1]+……+count[n-1]，即count[n] = 2*count[n-1]
 */
#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {  
        return (1 << (number-1));
    }
};