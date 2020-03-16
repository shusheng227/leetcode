/**
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */
/**
 * 思路：
 * 根据后续遍历的规律，根结点在最后一位，所以可根据最后一位将前面部分切割
 * 由于是二叉搜索树，所以左子树所有结点值小于根结点，右子树所有结点值大于根结点，
 * 据次可从第一个元素遍历，将小于根结点的结点归为左子树，直至遇到大于根结点的结点
 * 此时对后面所有结点遍历，若小于根结点则返回false，否则归为右子树
 * 接着使用递归对左子树和右子树进行遍历
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        else {
            return helper(sequence);
        }
    }

private:
    bool helper(vector<int> sequence) {
        //print(sequence);
        int size = sequence.size();
        if(size <= 2) return true;
        int val = sequence[size-1]; //根结点
        vector<int> left;
        vector<int> right;
        int i = 0;

        while(sequence[i] < val) {
            left.push_back(sequence[i++]);
        }
        for( ; i < size-1; ++i) {
            if(sequence[i] < val) return false;
            right.push_back(sequence[i]);
        }

        return helper(left) && helper(right);
    }
};