/**
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */
/**
 * 思路：
 * 将数字当作二进制数看待，二进制异或为相加结果、想与为相加进位
 */

class Solution {
public:
    int Add(int num1, int num2)
    {
        return num2==0? num1:Add(num1^num2, (unsigned int)(num1&num2)<<1);
    }
};