/**
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * A->1,B->2,...,Z->26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 **/

/**
 * 思路：
 * 使用动态规划，使用A[k]保存前n个字符的解码方式总数
 * 若A[k]和A[k-1]组成的数字小于26，则A[k+1]=A[k]+A[k-1]
 * 否则A[k+1]=A[k]
 **/

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        int A[len+1];       //A[k]保存前k个字符解码方法的总数

        //判空和初始化
        if(len==0 || s[0]=='0') return 0;
        if(len==1) return 1;
        A[0] = 1;
        A[1] = 1;

        for(int i=1; i<len; i++) {
            if(s[i]=='0') {
                if(s[i-1]=='0' || s[i-1]>'2'){
                    //若出现多个i连续的0或30、40、....，无法解码，直接返回0
                    return 0;
                }
                else {
                    A[i+1] = A[i-1];
                }
            }
            else if((s[i-1]=='1') || (s[i-1]=='2' && s[i]<='6')) {
                // 新的字符可以
                A[i+1] = A[i] + A[i-1];
            }
            else {
                A[i+1] = A[i];
            }
        }
        
        return A[len];
    }
};

int main() {
    string str = "123";
    Solution s;
    cout << s.numDecodings(str);
}