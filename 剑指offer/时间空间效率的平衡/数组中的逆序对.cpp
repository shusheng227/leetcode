/**
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 */
/**
 * 思路：
 * 求逆序对的过程可以看作排序，排序时每交换一次说明有一个逆序对
 * 即逆序对的数量等于排序的交换次数
 * 为了减少时间复杂度，可以使用归并排序
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        long num = 0;
        long size = data.size();
        mergesort(data, 0, size-1, num);
        return num%1000000007;
    }
private:
    //数组v[L~mid]、v[mid+1~R]分别数有序的，将两者合并未一个有序数组
    void merge(vector<int> &v, long L, long mid, long R, long &num) {
        long i = L, j = mid+1;
        vector<int> res;

        while(i <= mid && j <= R) {
            if(v[i] < v[j]) {
                res.push_back(v[i++]);
            } else {
                res.push_back(v[j++]);
                num += (mid - i + 1);
            }
        }
        while(i <= mid) {
            res.push_back(v[i++]);
        }
        while(j <= R) {
            res.push_back(v[j++]);
        }

        i = L;
        j = 0;
        while(i <= R) {
            v[i++] = res[j++];
        }
    }
    // 归并排序
    void mergesort(vector<int> &v, long low, long high, long &num) {
        if(high <= low) {
            return ;
        }

        long mid = (high + low)/2;
        mergesort(v, low, mid, num);
        mergesort(v, mid+1, high, num);
        merge(v, low, mid, high, num);
    }
};