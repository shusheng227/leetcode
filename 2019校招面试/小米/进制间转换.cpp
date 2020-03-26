/**
 * 设计一个函数， 可以将任意十进制的数， 转换成任意2到9的进制表示的形式
 * 输入描述：需要转换的数字x(0<=x<=1e18) 转换使用的进制k(2<=k<=9)
 * 输出描述：对应进制的结果
 */
#include <iostream>
#include <string>
using namespace std;

string decimal_Conversion(long long decimal, int k) {
    int temp = 0;
    string res;
    do {
        temp = decimal % k;
        decimal = decimal / k;
        res = to_string(temp) + res;
    } while(decimal);
    return res;
}

int main() {
    long long x;
    int k;
    cin >> x >> k;
    cout << decimal_Conversion(x, k);
}