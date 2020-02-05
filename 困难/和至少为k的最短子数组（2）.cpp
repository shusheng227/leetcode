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
		int minlen = INT_MAX;		// 保存最短子数组长度
		vector<int> temp(0); 
		vector<int> pre(A.size()+1);	// 保存前n个值的和
		pre[0] = 0;
		for(int i=0; i<A.size(); i++) {
			pre[i+1] = pre[i]+A[i];
		}
		for(int i=0; i<=A.size(); i++) {
			while((!temp.empty()) && (pre[temp.back()]>=pre[i])) {
				// 若pre[i]>pre[j],则可用i取代j
				// temp中对应的pre数组值是从小到大的 
				temp.pop_back();
			}
			while((!temp.empty()) && (pre[i]-pre[temp.front()]>=K)) {
				// 从第一个开始，寻找当前最短的子数组 
				int newlen = i-temp.front();
				temp.erase(temp.begin());
				minlen = min(minlen, newlen);
			} 
			temp.push_back(i);
		}
		
		return (minlen==INT_MAX)?-1:minlen;
	}
};


int main() {
	int a[] = {2,-1,2,3};
	vector<int> A(a,a+4);
	Solution s;
	int len = s.shortestSubarray(A,3);
	cout << len <<endl;
} 
