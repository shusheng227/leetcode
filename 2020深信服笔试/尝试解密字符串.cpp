#include <bits/stdc++.h>
using namespace std;

map<char, char> m;

//获取加密规律
void fun1(string s1, string s2) {
    long len = s1.length();
    for(long i = 0; i < len; ++i) {
        m[s1[i]] = s2[i];
    }
}

bool isZF(char c) {
    if('a' <= c && 'z' >= c) return true;
    if('A' <= c && 'Z' >= c) return true;
    if('0' <= c && '9' >= c) return true;
    if(c == '_') return true;
    return false;
}

//解密
void fun2(string s1, string &s2, long n) {
    for(long i = 0; i < n; ++i) {
        if(isZF(s1[i])) {
            s2[i] = m[s1[i]];
        }
        else {
            s2 = "error";
            return ;
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    fun1(s1, s2);
    long N;
    cin >> N;
    string s[N];
    for(long i = 0; i < N; ++i) {
        cin >> s[i];
    }

    for(long i = 0; i < N; ++i) {
        long len = s[i].length();
        string str;
        str.resize(len);
        fun2(s[i], str, len);
        cout << str << endl;
    }
}