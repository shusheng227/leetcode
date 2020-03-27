/**
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int size = array.size();
        int left = 0, right = size - 1;
        int mult = INT_MAX;
        bool flag = false;
        vector<int> res;

        while(left < right) {
            int l = array[left];
            int r = array[right];
            int s = array[left] + array[right];
            if(s == sum && l * r < mult) {
                if(!flag) {
                    res.resize(2);
                    flag = true;
                }
                mult = l * r;
                res[0] = l;
                res[1] = r;
                ++left;
                --right;
            } else if(s < sum) {
                ++left;
            } else {
                --right;
            }
        }

        return res;
    }
};