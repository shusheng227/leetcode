/**
 * 题目描述：
 * 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int cutRope(int number) {
        if(number==1 || number==2) return 1;
        int k[number+1];
        k[0] = k[1] = 1;
        k[number] = INT_MIN;
        int temp = 0;
        for(int i=2; i<number; ++i) {
            k[i] = i;
            for(int j=1; j<i; ++j) {
                temp = k[j] * k[i-j];
                k[i] = max(k[i],temp);
            }
        }
        for(int i=1; i<number; ++i) {
            k[number] = max(k[number], k[i]*k[number-i]);
        }

        return k[number];
    }
};

int main() {
    Solution s;
    cout << s.cutRope(4);
}