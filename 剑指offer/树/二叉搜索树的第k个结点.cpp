/**
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如，（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
 */
/**
 * 思路：
 * 使用队列保存二叉搜索树遍历结果，由于中序遍历结果是升序排列，所以直接出列取出第k个结点即可
 */
#include <iostream>
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        Travel(pRoot);
        int i = 0;
        while(!q.empty()) {
            ++i;
            if(i == k) {
                return q.front();
            }
            else {
                q.pop();
            }
        }

        return nullptr;
    }

private:
    queue<TreeNode *> q;
    void Travel(TreeNode *root) {
        if(root == nullptr) return ;
       
        Travel(root->left);
        q.push(root);
        Travel(root->right);
    }
    
};