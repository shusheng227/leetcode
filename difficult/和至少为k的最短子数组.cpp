/*
 * ���� A ����̵ķǿ�����������ĳ��ȣ���������ĺ�����Ϊ K ��
 * ���û�к�����Ϊ K �ķǿ������飬���� -1 �� 
 */ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
		int len = A.size(), minRes = INT_MAX;//minRes��¼���������
        int sum = 0, left = 0;//sum��¼��ǰ�����е�Ԫ�غͣ�left��߽�
        //rightΪ�ұ߽�
        for (int right = 0; right < len; ++right) {
            if (A[right] >= K) {
                //�������Ԫ�س�����K�������Ž�ض���1
                return 1;
            }
            sum += A[right];//���뻬������
            if (sum < 1) {
                //�������sumС��1����˵�������е�Ԫ�ض����������ù�����Ϊ������Ҫ�ҵ�����K�����������
                sum = 0;//��մ���
                left = right + 1;//�ƶ���߽磬������һ�����ڵ��γ�
                continue;
            }
            //��������������ǰ�ұ߽總������һ�����ĸ�ֵ����������ۼ�ת������֮ǰ����ֵ��
            //��������������Ӱ�촰����ͣ���������С��߽�ʱ�򽫻��𵽾޴�����ã�����A[i] << 0 ���A[left] + A[left + 1] + .. + A[i] <= 0
            for (int j = right - 1; j>=-1 && A[j + 1] < 0; --j) {
                A[j] += A[j + 1];//����ֵת�Ƶ���ǰһ��Ԫ����
                A[j + 1] = 0;//�Լ����
            }
            if (sum >= K) {
                //����sum��С��K����ʱ���ǳ���������߽�left��������С���ڴ�С
                while (sum - A[left] >= K || A[left] <= 0) {
                    sum -= A[left++];
                }
                minRes = min(minRes, right - left + 1);//right - left + 1��ʾ���ڴ�С
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
