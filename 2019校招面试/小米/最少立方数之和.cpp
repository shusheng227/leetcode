/**
 * 给出一个数字N（0<N<1000000）,将N写成立方数和的形式，求出需要的最少立方数个数。
 * 例如N=17，1+8+8 = 17，最少需要3个立方数，则输出3。
 * N= 28,1+1+1+1+8+8+8=28, 需要7个立方数，1+27=28,需要2个立方数，所以最少立方数为2，则输出2。
 * 输入描述：一个数字N（0<N<1000000）
 * 输出描述：最少立方数个数
 */
/**
 * 思路：
 * 使用动态规划，得到减少一个立方数情况下的dp数，进行比较，选取最小的加1
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int least_cubicNumber(int n) {
    vector<int> dp(n+1, 0);
    vector<int> cube(100);
    int len = 0;
    while(cube[len++] < n) {
        cube[len] = len * len * len;
    }
    --len;
    
    for(int i = 1; i <= n; ++i) {
        int minNumber = INT_MAX;
        for(int j = 1; cube[j] <= i; ++j) {
            minNumber = min(minNumber, dp[i-cube[j]]);
        }
        dp[i] = minNumber + 1;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << least_cubicNumber(n);
}