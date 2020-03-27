/**
 * 汇编语言中有一种移位指令叫做循环左移（ROL），
 * 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */
/**
 * 思路：
 * 该题可以分为三步实现：
 * （1）将前n个字符翻转
 * （2）将整个字符串翻转
 * （3）将前len-n个字符翻转
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return str;
        
        reverse(str, 0, n-1);
        reverse(str, 0, len-1);
        reverse(str, 0, len-n-1);

        return str;
    }
private:
    //将str的第left~right位翻转
    void reverse(string &str, int left, int right) {
        char temp;

        while(left < right) {
            temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            ++left;
            --right;
        }
    }
};