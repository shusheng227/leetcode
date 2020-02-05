/*
 * ���� A ����̵ķǿ�����������ĳ��ȣ���������ĺ�����Ϊ K ��
 * ���û�к�����Ϊ K �ķǿ������飬���� -1 �� 
 */ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
		int minlen = INT_MAX;		// ������������鳤��
		vector<int> temp(0); 
		vector<int> pre(A.size()+1);	// ����ǰn��ֵ�ĺ�
		pre[0] = 0;
		for(int i=0; i<A.size(); i++) {
			pre[i+1] = pre[i]+A[i];
		}
		for(int i=0; i<=A.size(); i++) {
			while((!temp.empty()) && (pre[temp.back()]>=pre[i])) {
				// ��pre[i]>pre[j],�����iȡ��j
				// temp�ж�Ӧ��pre����ֵ�Ǵ�С����� 
				temp.pop_back();
			}
			while((!temp.empty()) && (pre[i]-pre[temp.front()]>=K)) {
				// �ӵ�һ����ʼ��Ѱ�ҵ�ǰ��̵������� 
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
