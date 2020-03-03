/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;    //保存奇数
        vector<int> even;   //保存偶数

        for(int i=0; i<array.size(); ++i) {
            if(isOdd(array[i])) {
                odd.push_back(array[i]);
            }
            else {
                even.push_back(array[i]);
            }
        }
        array.assign(odd.begin(), odd.end());
        array.insert(array.end(), even.begin(), even.end());
    }

    bool isOdd(int n) {
        return (n & 1);
    }
};