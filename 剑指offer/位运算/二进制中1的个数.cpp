/**
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
/**
 * 思路：
 * 由于该整数有可能为负数，所以不能使用右移操作
 * 可以使用1，将1不断左移，然后与整数相与，若为1说明该位为1，否则为0
 */
#include <iostream>

class Solution {
public:
     int  NumberOf1(int n) {
        int flag = 1;   //标志位，用来与n相与查看某一位是否为1
        int res = 0;

        while(flag) {
            if((n&flag)) ++res;
            flag = flag << 1;
        }

        return res;
     }
};