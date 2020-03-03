/**
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 * （注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
 */
/**
 * 思路：
 * 将乘积分为两部分，数组C保存左边的乘积部分，数组D保存右边的乘积部分
 * 即C[i] = A[0]*A[1]*……*A[i-1], D[i] = A[i+1]*A[i+2]*A[n-1]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> B(size, 1);
        vector<int> C(size, 1);
        vector<int> D(size, 1);

        for(int i=1; i<size; i++) {
            C[i] = C[i-1]*A[i-1];
        }
        for(int i=size-2; i>=0; i--) {
            D[i] = D[i+1]*A[i+1];
        }
        for(int i=0; i<size; i++) {
            B[i] = C[i]*D[i];
        }

        return B;
    }
};

int main() {
    vector<int> A = {1,2,3,4,5};
    Solution s;
    s.multiply(A);
}