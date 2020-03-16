/**
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
 * 输入描述：输入一个字符串,包括数字字母符号,可以为空
 * 输出描述：如果是合法的数值表达则返回该数字，否则返回0
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty() || str.compare("") == 0) return 0;
        int i = 0;
        int size = str.size();
        long long res = 0;
        bool isNegative = false;


        if(str[0]=='+') {
            i = 1;
        }
        else if(str[0] == '-') {
            i = 1;
            isNegative = true;
        }
        for( ; i<size; ++i) {
            if(str[i] < '0' || str[i] > '9') {
                return 0;
            }
            res *= 10;
            res += str[i]-'0';
            if(res>(long long)INT_MAX && !isNegative) return 0;
            else if(res>((long long)INT_MAX+1) && isNegative) return 0;
        }
        
        return isNegative? -res: res;
    }
};

int main() {
    string str("-123");
    Solution s;
    cout << s.StrToInt(str) << endl;
}