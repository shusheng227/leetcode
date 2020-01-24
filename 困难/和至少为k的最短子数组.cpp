/*
 * 返回 A 的最短的非空连续子数组的长度，该子数组的和至少为 K 。
 * 如果没有和至少为 K 的非空子数组，返回 -1 。 
 */ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
		int len = A.size(), minRes = INT_MAX;//minRes记录最短子数组
        int sum = 0, left = 0;//sum记录当前窗口中的元素和，left左边界
        //right为右边界
        for (int right = 0; right < len; ++right) {
            if (A[right] >= K) {
                //如果单个元素超过了K，则最优解必定是1
                return 1;
            }
            sum += A[right];//放入滑动窗口
            if (sum < 1) {
                //如果窗口sum小于1，则说明窗口中的元素都是在做无用功，因为我们需要找到大于K的最短子数组
                sum = 0;//清空窗口
                left = right + 1;//移动左边界，方便下一个窗口的形成
                continue;
            }
            //特殊操作，如果当前右边界附近出现一连串的负值，则把他们累加转到他们之前的正值上
            //这样处理并不会影响窗口求和，但是在缩小左边界时候将会起到巨大的作用，比如A[i] << 0 造成A[left] + A[left + 1] + .. + A[i] <= 0
            for (int j = right - 1; j>=-1 && A[j + 1] < 0; --j) {
                A[j] += A[j + 1];//将负值转移到它前一个元素上
                A[j + 1] = 0;//自己清空
            }
            if (sum >= K) {
                //窗口sum不小于K，这时我们尝试右移左边界left，尽量减小窗口大小
                while (sum - A[left] >= K || A[left] <= 0) {
                    sum -= A[left++];
                }
                minRes = min(minRes, right - left + 1);//right - left + 1表示窗口大小
            }
        }
        return minRes == INT_MAX ? -1 : minRes;
	}
};


int main() {
	int a[] = {2,-1,2};
	vector<int> A(a,a+3);
	Solution s;
	int len = s.shortestSubarray(A,3);
	cout << len <<endl;
} 
