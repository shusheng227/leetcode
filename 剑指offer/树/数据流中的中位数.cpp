/**
 * 如何得到一个数据流中的中位数？
 * 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 */
/**
 * 思路：
 * 用一个最大堆来维护当前前n/2小的元素，那么每次找中位数只到取出堆顶就可以了。
 * 但是，有一个问题，数据要动态增长，有可能之前被替换掉的元素随着元素的增加又跑回来了，
 * 所以我们可以再用一个最小化堆来存前n/2大的元素。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> min; //数组中的后一半元素组成一个最小化堆，前n/2大元素
        vector<int> max; //数组中的前一半元素组成一个最大化堆，前n/2小元素
    public:
        void Insert(int num) {
            if(((min.size()+max.size()) & 1) == 0) {  //偶数数据的情况下，则在最小堆中插入元素
                if(max.size() > 0 && num < max[0]) {
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<int>());
                    //首先数组push_back插入元素，然后再调用push_heap，它会使最后一个元素插到合适位置
                    num=max[0];
                    pop_heap(max.begin(), max.end(), less<int>());
                    //它会将堆顶元素（即为数组第一个位置）和数组最后一个位置对调，然后你可以调用数组pop_back，删除这个元素
                    max.pop_back();
                }
                min.push_back(num); //把前一半找到的最大值放到后一半中
                push_heap(min.begin(), min.end(), greater<int>());
            } else {
                if(min.size() > 0 && num > min[0]) {   //奇数数据的情况下，则在最大堆中插入元素
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<int>());
                    num=min[0];
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back(); 
                }
                max.push_back(num); //把后一半找到的最大值放到前一半中
                push_heap(max.begin(), max.end(), less<int>());
            }
        }

        double GetMedian() { 
            int size=min.size() + max.size();
            if(size==0) return -1;
            double median = 0;
            if((size&1) != 0) {
                median = (double) min[0];
            } else {
                median = (double) (max[0] + min[0]) / 2;
            }
            return median;
        }
};

int main() {
    Solution s;
    vector<int> v{5,2,3,4,1,6,7,0,8};
    for (int i = 0; i < v.size(); ++i) {
        s.Insert(v[i]);
        cout << s.GetMedian() << endl;
    }
    return 0;
}

/**
 * 最大堆中所有元素小于最小堆元素，
 * 当偶数数据时，插入一个元素则变为奇数数据，即中位数为最小堆堆顶元素
 * 所以需要先将数据插入最大堆，取出最大元素放入最小堆，最小堆排序后堆顶即为中位数
 * 
 * 当奇数数据时，插入一个元素则变为偶数数据，即中位数为两个堆顶元素平均数
 * 插入前最小堆比最大堆多一个元素，即需要将数据插入最大堆，
 * 所以需要先将数据插入最小堆，取出最小元素放入最大堆
 */