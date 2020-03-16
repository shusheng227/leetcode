/**
 * 统计一个数字在排序数组中出现的次数。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int res = 0;
        int size = data.size();
        for(int i=0; i<size; ++i) {
            if(data[i] == k) {
                int j = i;
                while(j < size && data[j++] == k) {
                    ++res;
                }
                break;
            }
        }
        return res;
    }
};