/**
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
 */
/**
 * 思路：
 * 由于需要选择最小的K个数，所以该问题应基于排序的思想解决
 * （1）完全排序：先进行排序，再输出前K个数，时间复杂度为O(n*logn)，
 *               该方法简单明了，但容易预见，当K相对n较小时，代价过大
 * （2）部分选择排序：使用选择排序，但只需要进行K次即可，该方法时间复杂度为O(k*n)，代价仍然太大，
 * （3）最大堆：维持一个大小为k的最大堆，对数组进行一次循环，当有值小于最大堆堆顶元素时，更新最大堆
 *             该算法时间复杂度为O(n*logk)，不管K如何变化，只需要循环一次即可，但维持最大堆会花销logk时间
 * （4）基于快排的算法：设下标为location的元素为loc，快排每次将数组分为两部分，大于loc的和小于loc的，不断分治，直至location<=k，
 *             若location等于k，小于loc的即为最小的K个数之一；若location小于k，对大于loc的数继续分割，直至location等于k
 *             该算法时间复杂度与快排相同，为O(n)，K对算法的影响较小，
 * 综上，根据n和K的变化，后两种算法会各有优劣，但相较前两种算法，时间效率大大提高
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int low, int high)
    {
        int pivot = arr[high]; // 选最后一个元素作为枢纽元
        int location = low; // location放置的是最新的比枢纽元小的元素
        for (int i = low; i < high; i++) // 比枢纽元小的元素依次放在前半部分
            if (arr[i] < pivot)
                swap(arr[i], arr[location++]); // 移动location
        swap(arr[high], arr[location]); // 最后交换的是arr[high]，不是pivot
        return location;
    }
    void quick_sort(vector<int>& arr, int low, int high, int k)
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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int sz = input.size();
        vector<int> vec;
        if (sz == 0 || k <= 0 || sz < k)
            return vec;
        quick_sort(input, 0, input.size() - 1, k);
        for (int i = 0; i < k; ++i)
        {
            vec.push_back(input[i]);
        }
        return vec;
    }
};
