/**
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */

#include <iostream>
#include <vector>
#include <queue>
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
        queue<TreeNode *> oddQueue;     //保存奇数层结点
        queue<TreeNode *> evenQueue;    //保存偶数层结点
        vector<vector<int> > res;
        if(pRoot) oddQueue.push(pRoot);

        while(!oddQueue.empty() || !evenQueue.empty()) {
            vector<int> v;
            TreeNode *p = 0;
            if(evenQueue.empty()) {
                //偶数层为空，遍历奇数层             
                while(!oddQueue.empty()) {
                    p = oddQueue.front();
                    oddQueue.pop();
                    if(p->left) evenQueue.push(p->left);
                    if(p->right) evenQueue.push(p->right);
                    v.push_back(p->val);
                }
            }
            else {
                //奇数数层为空，遍历偶数层
                while(!evenQueue.empty()) {
                    p = evenQueue.front();
                    evenQueue.pop();
                    if(p->left) oddQueue.push(p->left);
                    if(p->right) oddQueue.push(p->right);
                    v.push_back(p->val);
                }
            }
            res.push_back(v);
        }

        return res;
    }   
};