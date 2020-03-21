/**
 * 给出一个长度为n的由正整数构成的序列，你需要从中删除一个正整数，
 * 很显然你有很多种删除方式，你需要对删除这个正整数以后的序列求其最长上升子串，
 * 请问在所有删除方案中，最长的上升子串长度是多少。
 * 这里给出最长上升子串的定义：
 * 即对于序列中连续的若干个正整数，满足a_{i+1}>a_i，则称这连续的若干个整数构成的子串为上升子串，
 * 在所有的上升子串中，长度最长的称为最长上升子串。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long getLongest(vector<long long> v) {
        long long size = v.size();
        bool flag = false;
        long long res = 1;
        long long pre = 0;
        long long tail = 0;
        vector<long long> ascendingSub(size, 1);
        long long count = 1;
        //算出删除前所有上升子串长度
        for(int i = 1; i < size; ++i) {
            if(v[i] > v[i-1]) {
                ascendingSub[i] = (++count);
                res = max(res, count);
            }
            else {
                flag = true;
                ascendingSub[i] = count = 1;
            }
        }

        if(!flag) {
            return size-1;
        }
        for(long long i = 1; i < size-1; ++i) {
            if(ascendingSub[i] == 1 && v[i+1] > v[i-1]) {
                pre = ascendingSub[i-1];
                tail = 1;
                ++i;
                while(ascendingSub[i+1] > ascendingSub[i]) {
                    ++tail;
                    ++i;
                }
                res = max(res, pre + tail);
            }
            //cout << i << ":" << res << endl;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    long long n = 0;
    cin >> n;
    vector<long long> v(n);
    for(long long i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << s.getLongest(v) << endl;
}

    

