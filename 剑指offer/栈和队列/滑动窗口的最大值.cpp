/**
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
 * {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */
/**
 * 思路：
 * 使用一个双向队列保存滑动窗口，保证队首为滑动窗口最大值
 * 使用循环每次向队尾插入新值，若新值大于队尾值，则队尾位置的值永远不可能为滑动窗口最大值，从队尾剔除
 * 若队列不为空则一直比较直至遇到大于新值的元素。
 * 使用循环剔除不属于滑动窗口的队首，若队列不为空则一直查看队首直至遇到窗口内的元素
 * 通过这两步操作可保证队列元素降序排列并且队首在滑动窗口内
 * 此时队首即为当前滑动窗口最大值，直接输出即可
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;    //保存滑动窗口最大值
        if(num.size() == 0 || size > num.size() || size < 1)
            return res;
        deque<int> dq;      //保存滑动窗口的双向队列，保存数组索引，方便判断是否滑动窗口元素
        //预处理，将第一个滑动窗口内的元素插入队列
        for(int i = 0; i < size; ++i){
            while(!dq.empty() && num[i] >= num[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i = size; i < num.size(); ++i){
            res.push_back(num[dq.front()]);
            //剔除小于新值的元素
            while(!dq.empty() && num[i] >= num[dq.back()])
                dq.pop_back();
            //剔除不在窗口的队首
            if(!dq.empty() && dq.front() <= (int)(i - size))
                dq.pop_front();
            dq.push_back(i);
        }
        res.push_back(num[dq.front()]);
        return res;
    }
};