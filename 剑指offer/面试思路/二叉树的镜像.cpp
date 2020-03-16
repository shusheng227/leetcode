/**
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr) return ;
        TreeNode *p = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = p;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};