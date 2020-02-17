/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 **/

/**
 * 思路：
 * 使用中序遍历，根据二叉搜索树定义，中序遍历结果是升序的
 * 若出现i<j，但v[j]<v[i]，则说明不是二叉搜索树
 **/
#include <iostream>
#include <vector>
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
        vector<int> v;        //保存中序遍历结果
        inorderTravel(root, v);

        for(int i=0; i<v.size()-1; i++) {
            if(v[i]>=v[i+1]) return false;
        }

        return true;
    }

private:
    void inorderTravel(TreeNode* root, vector<int> &v) {
        if(root == NULL) return ;
        
        inorderTravel(root->left, v);
        v.push_back(root->val); 
        inorderTravel(root->right, v);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.isValidBST(root) << endl;
}
