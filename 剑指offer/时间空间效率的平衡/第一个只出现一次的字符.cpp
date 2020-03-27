/**
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
 * 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> m;
        int len = str.length();

        for(int i = 0; i < len; ++i) {
            ++m[str[i]];
        }

        for(int i = 0; i < len; ++i) {
            if(m[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};