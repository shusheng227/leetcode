/**
 * 给你一个01字符串，定义答案=该串中最长的连续1的长度，现在你有至多K次机会，每次机会可以将串中的某个0改成1，现在问最大的可能答案
 */
/**
 * 思路：
 * 使用双指针模拟滑动窗口，一次遍历即可
 * 使用l表示左指针，r表示右指针。
 * （1）当k非0时，让右指针一直右移，遇到0时k减1
 * （2）当k为0时，右指针遇到0时移动左指针，直至左指针遇到0
 * 左指针和右指针之间的距离即为1的最长串
 */
#include <iostream>
#include <vector>
using namespace std;

long getNum(vector<char> num, long n, long k) {
    long l = 0, r = 0;
    long res = 0;
    while(r < n) {
        if(num[r] == 1) {
            ++r;
        } else if(k > 0) {
            --k;
            ++r;
        } else {
            res = max(res, r-l);
            while(num[l] != 0 && l < r) {
                ++l;
            }
            ++r;
            ++l;
        }
    }
    res = max(res, r-l);
    return res;
}

int main() {
    
}