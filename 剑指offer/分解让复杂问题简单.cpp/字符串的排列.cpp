/**
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * 输入描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 */
/**
 * 思路：
 * 该问题可分为3步解决：
 * （1）将字符串排序
 * （2）固定第一个字符，得到后面几个字符的所有排列，和第一个相加得到所有排列
 * （3）将后面字符与第一个一一交换，重复第（2）步
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        int len = str.length();
        sort(str.begin(), str.end());
        vector<string> res = helper(str, len);
        return res;
    }
private:
    vector<string> helper(string str, int len) {
        vector<string> res;
        if(len == 1) {
            res.push_back(str);
        } else {
            for(int i = 0; i < len; ++i) {
                if(i!=0 && str[0] == str[i]) continue;
                swap(str[0],str[i]);
                string temp = str.substr(1, len-1);
                vector<string> v = helper(temp, len-1);
                long size = v.size();
                char s = str[0];
                for(int j = 0; j < size; ++j) {
                    res.push_back(s + v[j]);
                }
            }
        }
        return res;
    }
};