/**
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 **/

/**
 * 思路：
 * 整数相除，结果只有两种：①无限循环小数 ②有限循环小数
 * 但循环部分不一定是从小数点后开始的，所以本题的难度在于找出循环部分
 * 可以使用余数进行判断，当余数第二次出现时说明开始小数部位循环
 * 可以使用哈希表记录余数和余数的位置，第二次出现时直接截取即可
 * 本程序只实现简单算法，没考虑边界情况
 **/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int quotient = numerator/denominator;   //保存商
        int remainder = numerator%denominator;  //保存余数
        unordered_map<int,int> remainder_info;  //保存余数及其位置

        //cout << "first caculate finish..." << endl;
        string result = to_string(quotient);
        if(remainder) {
            //cout << "begin to caculate the decimal..." << endl;
            int len = result.length()+1;
            result.push_back('.');
            remainder_info[remainder] = len;

            //循环计算小数部分每一位
            while(1) {              
                //计算新的商和余数
                numerator = remainder*10;
                quotient = numerator/denominator;
                remainder = numerator%denominator;

                //cout << "the" << i++ << "th caculate..." << endl;
                //cout << "\t\t" << "thee remainder is " << remainder <<endl;
                len++;
                result += to_string(quotient);
                if(!remainder) break;       //除尽，有限小数，直接跳出

                if(remainder_info.count(remainder)) {
                    //余数出现过，循环部分结束，输出结果
                    result.insert(remainder_info[remainder], "(");
                    result += ')';
                    break;
                }
                else {
                    remainder_info[remainder] = len;
                }
            }           
        }

        return result;
    }
};

int main() {
    int numerator = 1;
    int denominator = 6;
    Solution s;
    cout << s.fractionToDecimal(numerator, denominator);
}