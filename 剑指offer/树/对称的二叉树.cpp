/**
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */
#include <iostream>

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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == 0) return true;
        return helper(pRoot->left, pRoot->right);
    }

private:
    //比较两个二叉树是否对称
    bool helper(TreeNode *pRoot1, TreeNode *pRoot2) {
        if(!pRoot1  && !pRoot2) {
            return true;
        }
        if(!pRoot1 || !pRoot2) {
            return false;
        }

        if(pRoot1->val != pRoot2->val) return false;
        if(!helper(pRoot1->left, pRoot2->right)) return false;
        if(!helper(pRoot1->right, pRoot2->left)) return false;
        return true;
    }

};