#include <bits/stdc++.h>
using namespace std;

long fun(string s) {
    long len = s.length();
    long res = 1;
    long maxlen = 1;

    for(long i = 1; i < len; ++i) {
        if(s[i] == s[i-1] + 1) {
            //cout << i << ":" << s[i] << " " << s[i-1] << endl;
            ++maxlen;
            res = max(res, maxlen);
        } else {
            maxlen = 1;
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    cout << fun(s) << endl;
}