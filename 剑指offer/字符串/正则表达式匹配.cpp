/**
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。
 */
/**
 * 思路：
 * 一. 特殊情况
 *     ①str和pattern都是空字符串，匹配，返回true
 *     ②pattern为空，str不为空，不匹配，返回false
 * 二. 判断下一个字符是否为'*'
 *     （1）下一个字符不是'*'
 *          这种情况直接比较当前字符即可，相同则递归向下判断，不同直接返回false
 *     （2）下一个字符是'*'
 *          ①当前字符不同，由于'*'可以为0次，pattern直接向后走两个字符，继续判断
 *          ②abc和模式ab*bc,当前字符匹配，模式的后面的字符还与其匹配
 *          ③abbc和模式ab*c，当前匹配，字符串的下一个字符还与其匹配
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
   {
        if(*str == '\0' && *pattern == '\0')    return true;
        if(*str != '\0' && *pattern == '\0')    return false;

        //如果下一个字符不是'*'
        if(*(pattern+1) != '*')
        {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
            //加入*str！=‘\0’是为了防止abc与模式abc.这样的情况出现，这两个是不匹配的。
                return match(str+1, pattern+1);
            else
                return false;
        }

        //如果下一个字符是'*'
        if(*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match(str, pattern+2) || match(str+1, pattern);  ///遇到*号，str中重复字符从前往后不断递减，防止匹配式中该字符再次出现
        //分别对应abc和模式ab*bc、abbc和模式ab*c
        else return match(str, pattern+2);
    }
};


int main() {
    char str[] = "";
    char pattern[] = "";
    Solution s;
    cout << s.match(str, pattern);
}