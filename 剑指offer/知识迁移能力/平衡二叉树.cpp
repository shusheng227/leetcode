/**
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
#include <iostream>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(getDepth(pRoot) == -1) return false;
        else return true;
    }
private:
    int getDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = getDepth(root->left);
        if (left == -1) return -1;
        int right = getDepth(root->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};