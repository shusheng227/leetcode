/**
 * 请实现一个函数按照之字形打印二叉树，
 * 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 */
/**
 * 思路：
 * 本题主要考察树的层次遍历，树的层次遍历主要使用队列实现，不过队列只能实现从左到右遍历
 * 本题可以使用两个栈，一个保存奇数层结点，一个保存偶数层结点
 * 由于栈是后进先出结构，取出时和放入时顺序相反，所以两层之间遍历顺序不同
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        stack<TreeNode *> oddStack;     //保存奇数层结点
        stack<TreeNode *> evenStack;    //保存偶数层结点
        vector<vector<int> > res;

        if(pRoot) oddStack.push(pRoot);
        while(!oddStack.empty() || !evenStack.empty()) {
            vector<int> v;
            TreeNode *p = 0;
            if(evenStack.empty()) {
                //偶数层栈为空，遍历奇数层栈               
                while(!oddStack.empty()) {
                    p = oddStack.top();
                    oddStack.pop();
                    if(p->left) evenStack.push(p->left);
                    if(p->right) evenStack.push(p->right);
                    v.push_back(p->val);
                }
            }
            else {
                //奇数数层栈为空，遍历偶数层栈
                while(!evenStack.empty()) {
                    p = evenStack.top();
                    evenStack.pop();
                    if(p->right) oddStack.push(p->right);
                    if(p->left) oddStack.push(p->left);
                    v.push_back(p->val);
                }
            }
            res.push_back(v);
        }

        return res;
    }  
};