/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
/**
 * 思路：
 * （1）使用哈希表进行统计
 * （2）使用异或，同一数字异或为0，将所有数字异或后结果为num1和num异或的结果，接着根据结果为1的比特位将数组拆分
 *      则num1和num2会分到两个数组，然后分别异或即可得到num1和num2
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> m;
        bool flag = false;
        for(int i=0; i<data.size(); ++i) {
            ++m[data[i]];
        }
        for(auto i: data) {
            if(m[i] == 1) {
                if(flag == false) {
                    flag = true;
                    *num1 = i;
                }
                else {
                    *num2 = i;
                }
            }
        }
    }
};