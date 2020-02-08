/**
 * ����һ������ n ������Ҫ�ҵ���������Ļ���������������������
 **/
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n), res, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) 
        {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len%2), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (long a : s) 
        {
        	
            long diff = abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            } else if (diff == minDiff) {
            	res = min(res, a);
			}     
			 
        }
        return to_string(res);
    }
};

int main() {
	string str = "100";
	Solution s;
	string result = s.nearestPalindromic(str);
	cout << result << endl;
}
