/**
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 说明：
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
 **/

/**
 * 思路:
 * 除法可以转化为减法，商即为除数减去被除数的次数，但每次减一太慢，可以改进为减去被除数*2^n
 * dividend = divisor*2^n +...+ divisor*2^k +...+ divisor*2^0
 * ans = 2^n +...+ 2^k +...+ 2^0
 **/
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long res = 0;
        long a = labs(dividend), b = labs(divisor);
        while(a >= b){
            long times = 1, temp = b; //times为被除数增大的倍数，temp为除数的中间变量
            while(a >= (temp << 1)){
                times <<= 1; //左移一位表示增大一倍
                temp <<= 1;
            }
            res += times;
            a -= temp;
        }
        res = ((dividend > 0) ^ (divisor > 0)) ? -res : res; //异或操作判断符号
        return (res > INT_MAX || res < INT_MIN) ? INT_MAX : res;
    }
};

int main() {
    int dividend = 150;
    int divisor = 14;
    Solution s;
    cout << s.divide(dividend, divisor);
}

