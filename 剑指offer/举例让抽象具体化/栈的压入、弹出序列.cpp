/**
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 */
/**
 * 思路：
 * 使用一个辅助栈，根据栈的压入和弹出顺序进行模拟，若结束时栈为空，则表示序列正确
 * 注意：若压栈数字有可能相等，则无法根据本方法判断弹出的是哪个数字，
 * 但本题中标明所有数字均不相等，故可以直接判断
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size = pushV.size();
        if(size == 0) return false;
        int popIndex = 0;
        stack<int> s;

        for(int i = 0; i < size; ++i) {
            s.push(pushV[i]);

            while(!s.empty() && s.top() == popV[popIndex]) {
                s.pop();
                ++popIndex;
            }
            
        }

        return s.empty();
    }
};

int main() {
    vector<int> pushV = {1, 2, 3, 4, 5};
    vector<int> popV = {4, 3, 5, 1, 2};
    Solution s;
    cout << s.IsPopOrder(pushV, popV) << endl;
}