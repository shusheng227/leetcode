#include <bits/stdc++.h>
using namespace std;

long fun(string s){
    long len = s.length();
    vector<bool> flag(len);
    long res = len;
    long i = 1;
    long r = 1;
    char c = s[0];
    while(i < len) {
        if(flag[i] == false) {
            ++i;
            continue;
        }
        if(s[i] == c) {
            ++r;
            ++i;
        }
        else {
            if(r>=3) 
            res -= r;
            long j = 0;
            while(j < r) {
                if(flag[s[i-j]] == true) {
                    flag[s[i-j]] == false;
                    ++j;
                }
            }
            for(j = 0; j < len; ++j) {
                if(flag[j] == true) {
                    c = s[j];
                    i = j+1;
                }
            }
            if(j > len-3) return res;
            r = 1;
        }
    }
    if(r >= 3) res-=r;
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << fun(s) << endl;
}