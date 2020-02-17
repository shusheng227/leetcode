/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 **/

/**
 * 思路：
 * 使用递归，返回左子树的最大值和右子树的最小值
 * 然后与当前点进行判断，若符合条件返回true，否则返回false
 * 时间复杂度O(n),空间复杂度O(logn)
 **/
#include <iostream>
using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        int maxVal1 = INT_MIN;
        int minVal1 = INT_MAX;
        int maxVal2 = INT_MIN;
        int minVal2 = INT_MAX;
        //检索左子树
        if(root->left) {
            if(searchTree(root->left, maxVal1, minVal1) == false) return false;
            if(root->val <= maxVal1) return false;
        }
        //检索右子树
        if(root->right) {
            if(searchTree(root->right, maxVal2, minVal2) == false) return false;
            if(root->val >= minVal2)  return false;
        }

        return true;
    }

private:
    //对子树递归搜索，子树是否为二叉搜索树并将子树中的最小值写入变量minVal，最大值返回maxVal
    bool searchTree(TreeNode* root, int &maxVal, int &minVal) {
        int maxVal2 = INT_MIN;
        int minVal2 = INT_MAX;

        //检索左子树
        if(root->left) {
            if(searchTree(root->left, maxVal2, minVal) == false) return false;
            if(root->val <= maxVal2) return false;
        }
        else {
            minVal = root->val;
        }

        //检索右子树
        if(root->right) {
            if(searchTree(root->right, maxVal, minVal2) == false) return false;
            if(root->val >= minVal2)  return false;
        }
        else {
            maxVal = root->val;
        }

        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.isValidBST(root) << endl;
}
