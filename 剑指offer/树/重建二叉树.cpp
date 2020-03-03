/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */
/**
 * 思路：
 * 首先先序遍历第一个结点为树的根结点，中序遍历第一个结点为树的最左结点
 * 中序遍历根结点前面的全是左子树结点，根结点后面的全是右子树结点
 * 找出中序遍历中根结点的位置，假设根结点的索引序号为x
 * 则左子树的中序遍历序列为vin[0~x-1]，左子树的先序遍历序列为pre[1~x]
 * 同理右子树的中序遍历序列为vin[x+1~end]，右子树的先序遍历序列为pre[x+1~end]
 * 使用递归每次找出一个子树的根结点，然后将左子树和右子树的任务交给后续递归函数
 */
#include <iostream>
#include <vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int size = pre.size();
        if(size == 0) return NULL;
        cout << "enter " << pre[0] << endl;
        TreeNode *T = new TreeNode(pre[0]);
        if(size == 1) {          
            return T;
        }

        int headval = pre[0];
        int len = 0;    //根结点在中序遍历序列中的位置
        for(int i=0; vin[i]!=headval; ++i) ++len;
        vector<int> pre_left(pre.begin()+1, pre.begin()+len+1);
        vector<int> vin_left(vin.begin(), vin.begin()+len);
        vector<int> pre_right(pre.begin()+len+1, pre.end());
        vector<int> vin_right(vin.begin()+len+1, vin.end());

        T->left = reConstructBinaryTree(pre_left, vin_left);
        T->right = reConstructBinaryTree(pre_right, vin_right);

        return T;
    }
};
void Travel(TreeNode *T);
int main() {
    vector<int> pre = {1,2,4,7};
    vector<int> vin = {4,7,2,1};
    Solution s;
    TreeNode *T = s.reConstructBinaryTree(pre,vin);
    Travel(T);
}

void Travel(TreeNode *T) {
    if(!T) return ;
    cout << T->val << " ";
    Travel(T->left);
    Travel(T->right);
}