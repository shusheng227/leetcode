/**
 * 扎金花是一种非常受欢迎的纸牌游戏。而在游戏界有一种于扎金花类似的玩法，叫做扎银花。
 * 相比于扎金花的牌型多变，扎银花就简单多了，虽然同样是三张牌比大小，在扎银花的规则里只需要把三张牌的点数相加再进行大小比较即可，点数大的人获胜。
 * 今天我们玩的不是扑克牌，而是一种取值范围在1-10^9以内的简单牌，两个人一开始各自有n张牌，他们会想办法组合出最大的牌，请你计算出获胜的一方的三张牌的点数之和。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long partition(vector<long long>& arr, long long low, long long high)
    {
        long long pivot = arr[high]; // 选最后一个元素作为枢纽元
        long long location = low; // location放置的是最新的比枢纽元小的元素
        for (long long i = low; i < high; i++) // 比枢纽元小的元素依次放在前半部分
            if (arr[i] > pivot)
                swap(arr[i], arr[location++]); // 移动location
        swap(arr[high], arr[location]); // 最后交换的是arr[high]，不是pivot
        return location;
    }
    void quick_sort(vector<long long>& arr, long long low, long long high, int k)
    {
        if (low < high)
        {
            int middle = partition(arr, low, high);
            // 如果middle大于k-1，则说明arr[middle]右边的元素都大于k，于是只递归arr[low, middle-1]即可
            if (middle > k - 1)
                quick_sort(arr, low, middle-1, k);
            // 如果middle小于k-1，则说明arr[middle]左边的元素都小于k，于是只递归arr[middle+1, high]即可
            if (middle < k - 1)
                quick_sort(arr, middle+1, high, k);
            // 如果middle等于k-1说明前k个元素已经找到
            if (middle == k - 1)
                return;
        }
    }
    long long GetLagerSum_Solution(vector<long long> input, int k) {  
        quick_sort(input, 0, input.size() - 1, k);
        long long res = 0;
        for(long long i = 0; i < k; ++i) {
            res += input[i];
        }
        return res;
    }
    long long getSum(vector<long long> v1, vector<long long> v2, int k) {
        long long res1 = GetLagerSum_Solution(v1, k);
        long long res2 = GetLagerSum_Solution(v2, k);
        return max(res1, res2);
    }
};

int main() {
    Solution s;
    long long n = 0;
    cin >> n;
    vector<long long> v1(n);
    vector<long long> v2(n);
    for(long long i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    for(long long i = 0; i < n; ++i) {
        cin >> v2[i];
    }
    int k = (n>3)? 3: n;
    cout << s.getSum(v1, v2, k);
}

    