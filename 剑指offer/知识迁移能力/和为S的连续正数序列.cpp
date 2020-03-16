/**
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
 * 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
 * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
 * 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 */
/**
 * 本题可以使用类似队列的窗口实现，令left=right=1;
 * （1）若left到right之间的和小于sum，right加1；
 * （2）若left到right之间的和等于sum，输出left到right之间的数，并将left和right加1
 * （3）若left到right之间的和大于sum，left加1；
 * 当left大于right时结束循环
 */
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int> > v);
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int left = 1;
        int right = 2;
        int sumx = 3;
        
        while(left < right) {
            if(sumx < sum) {
                ++right;
                sumx += right;
            }
            else if(sumx == sum) {
                vector<int> v;
                for(int i=left; i<=right; ++i) {
                    v.push_back(i);
                }
                res.push_back(v);
                
                sumx -= left;
                ++left;
                ++right;
                sumx += right;
            }
            else {
                sumx -= left;
                ++left;
            }
        }

        return res;
    }
};

void print(vector<vector<int> > v) {
    for(int i=0; i<v.size(); ++i) {
        for(int j=0; j<v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > v;
    Solution s;
    v = s.FindContinuousSequence(3);
    print(v);
}