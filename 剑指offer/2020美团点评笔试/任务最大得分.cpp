#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    long long getLarge(long long n, long long k, long long m, long long p, long long q, vector<long long> tim) {
        
    }
};

int main() {
    long long n, k, m, p, q;
    cin >> n >> k >> m >> p >> q;
    vector<long long> tim(k);
    for(long long i = 0; i < k; ++i) {
        cin >> tim[i];
    }
    sort(tim.begin(), tim.end());
}