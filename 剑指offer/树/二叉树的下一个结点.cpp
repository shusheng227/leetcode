/**
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */
/**
 * 思路：
 * 主要分为两种情况：
 * （1）该结点有右子树，则右子树的最左结点为下一结点
 * （2）该结点无右子树，向上遍历，直至父结点不存在或当前结点是父结点的左结点；
 *      若无父结点，说明该结点时最右结点，返回NULL；否则返回父结点
 */
#include<iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode->right) {
            TreeLinkNode *p = pNode;
            while(p->next && p == p->next->right) p = p->next;
            if(!p->next) return NULL;
            else return p->next;
        }
        else {
            TreeLinkNode *p = pNode->right;
            while(p->left) p = p->left;
            return p;
        }
    }
};