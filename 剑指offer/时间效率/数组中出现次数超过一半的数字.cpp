/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */
 /**
  * 思路：
  * 类似选举，每个支持者采用“牺牲”的方式，牺牲自己的同时带走一个非支持者。
  * 用preValue记录上一次访问的值，count表明当前值出现的次数，
  * 如果下一个值和当前值相同那么count++；如果不同count--，减到0的时候就要更换新的preValue值了，
  * 因为如果存在超过数组长度一半的值，那么最后preValue一定会是该值。
  */
 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if(size == 0)  return 0;
        int prevalue = numbers[0];
        int count = 1;

        for(int i = 1; i < size; ++i) {
            if(prevalue == numbers[i]) {
                ++count;
            } else {
                --count;
                if(count == 0) {
                    prevalue = numbers[i];
                    ++count;
                }
            }
        }

        //验证prevalue是否为次数超过一半的数字，防止数组长度为奇数等产生的错误
        count = 0;
        for(int i = 0; i < size; ++i) {
            if(prevalue == numbers[i]) {
                ++count;
            }
        }
        return (count > size/2)? prevalue: 0;
    }
};

