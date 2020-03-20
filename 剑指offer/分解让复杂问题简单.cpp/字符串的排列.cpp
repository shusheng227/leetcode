/**
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * 输入描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 */
/**
 * 思路：
 * 该问题可分为3步解决：
 * （1）将字符串排序
 * （2）从后往前不断交换字符得到新字符串
 * （3）比较所有字符串，遇到相同字符串删除一个
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        
    }
};
