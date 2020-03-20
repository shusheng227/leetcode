/**
 * HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
 * 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
 * 当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
 * 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 * 给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
 */
/**
 * 思路：
 * 该题是个常规问题，只需要使用滑动窗口即可
 * 从左向右滑动，不断相加，记录最大值，若某一窗口值为负数，直接舍弃
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int size = array.size();
        if(size == 0) return 0;
        int left = 0, right = 0;
        int res = array[0];
        int val = array[0];
        for( ; right < size; ++right) {
            val += array[right];
            res = max(res, val);
            if(val < 0) {
                left = right + 1;
                val = 0;
            } 
        }
        return res;
    }
};