/**
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 * 注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
 */
/**
 * 思路：
 * 由于随着出栈、进栈，栈中的数据再不断变化，所以最小值也再不断变化
 * 因此需要将随着进栈产生的所有最小值全部保存，随着出栈丢失的最小值全部删除
 * 综上，可以使用一个栈保存最小值，当进栈的值不大于最小值栈的栈顶元素时，将入栈元素插入最小值栈，
 * 出栈时，若出栈元素与最小值栈栈顶元素相等，对最小值栈进行出栈操作
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        if(mins.empty() || value <= mins.top()) {
            mins.push(value);
        }
        s.push(value);
    }
    void pop() {
        if(mins.top() == s.top()) {
            mins.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
private:
    stack<int> s;
    stack<int> mins;
};