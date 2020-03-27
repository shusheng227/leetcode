/**
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
		TreeNode *tail;
		helper(pRootOfTree, tail);
		//print(pRootOfTree);
		return pRootOfTree;
    }
private:
	//输出双向链表
	void print(TreeNode *pRoot) {
		TreeNode *p = pRoot;
		
		while(p != nullptr) {
			cout << p->val << "-->";
			p = p->right;
		} 
		cout << "NULL" << endl;
	}
	//将二叉树转化为双向链表并返回首、尾结点
	void helper(TreeNode *&pRoot, TreeNode *&tail) {
		if(pRoot == nullptr) {
			return ;
		}
		TreeNode *l = pRoot->left;
		TreeNode *tl = nullptr;
		TreeNode *r = pRoot->right;
		TreeNode *tr = nullptr;
		TreeNode *root = pRoot;
		helper(l, tl);
		helper(r, tr);
		//cout << pRoot->val << ": ";
		
		if(tl != nullptr) {
			tl->right = pRoot;
			pRoot->left = tl;
			pRoot = l;
		} else {
			pRoot->left = nullptr;
		}	
		if(r != nullptr) {
			r->left = root;
			root->right = r;
			tail = tr;
		} else {
			root->right = nullptr;
			tail = root;
		}
		//print(pRoot);
	}
};