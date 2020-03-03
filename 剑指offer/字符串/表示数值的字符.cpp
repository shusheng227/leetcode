/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
/**
 * 思路：
 * 除了'123'这种纯数字的情况外的特殊情况有：
 * ①开头有'+'或'-'符号  ②有小数点   ③有'e'或'E'
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        bool have_e = false;    //是否已出现e或E的标志
        bool have_decimal = false;  //是否已出现小数点的标志
        int len = strlen(string);
        int i = 0;
        char *s = string;

        if(s[len-1] < '0' || s[len-1] > '9') return false;
        if(*s == '+' || *s == '-') {
            i = 1;
        }

        for( ; i<len; i++) {
            char c = s[i];  //多次使用s[i]，使用c替代，减少内存访问，减少运行时间
            if(c >='0' && c <= '9') continue;
            else if(c == '.') {
                if(have_e || have_decimal) return false;
                else have_decimal = true;
            }
            else if(c == 'e' || c == 'E') {
                if(have_e) return false;
                else have_e = true;
            }
            else if(c == '+' || c == '-') {
                if(s[i-1] == 'e' || s[i-1] == 'E') continue;
                else return false;
            }
            else return false;
        }

        return true;    
    }
};