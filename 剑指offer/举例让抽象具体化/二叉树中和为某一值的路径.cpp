/**
 * 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
 */
#include <iostream>
#include <vector>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        int val = 0;

        if(root == nullptr) {
            return res;
        } else {
            val = root->val;
        }
        
        if(val < expectNumber) {
            //当前结点值小于要求值，继续向下递归查找
            vector<vector<int> > left = FindPath(root->left, expectNumber-val);
            vector<vector<int> > right = FindPath(root->right, expectNumber-val);
            res = merge(left, right);

            for(int i = 0; i < res.size(); ++i) {
                res[i].insert(res[i].begin(), val);
            }
        } else if(val == expectNumber && root->left == nullptr && root->right == nullptr) {
            //当前结点位叶结点并且结点值等于要求值，返回该路径
            vector<int> v = {expectNumber};
            res.push_back(v);
        }

        return res;
    }
private:
    //将两个二维数组根据长度排序合并
    vector<vector<int> > merge(vector<vector<int> > v1, vector<vector<int> > v2) {
        int index1 = 0;
        int index2 = 0;
        int size1 = v1.size();
        int size2 = v2.size();

        if(size1 == 0) {
            return v2;
        }
        if(size2 == 0) {
            return v1;
        }

        int length1 = v1[0].size();
        int length2 = v2[0].size(); 
        vector<vector<int> > res;

        while(length1 && length2) {
            if(length1 >= length2) {
                res.push_back(v1[index1++]);
                if(index1 < size1) {
                    length1 = v1[index1].size();
                }
                else {
                    length1 = 0;
                }
            } else {
                res.push_back(v2[index2++]);
                if(index2 < size2) {
                    ++index2;
                    length2 = v2[index2].size();
                }
                else {
                    length2 = 0;
                }
            }
        }

        for(int i = index1; i < size1; ++i) {
            res.push_back(v1[i]);
        }
        for(int i = index2; i < size2; ++i) {
            res.push_back(v2[i]);
        }

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(10);
    TreeNode *T1 = new TreeNode(5);
    TreeNode *T2 = new TreeNode(12);
    TreeNode *T3 = new TreeNode(4);
    TreeNode *T4 = new TreeNode(7);

    root->left = T1;
    root->right = T2;
    T1->left = T3;
    T1->right = T4;

    Solution s;
    vector<vector<int> > res = s.FindPath(root, 22);

    cout << "size:" << res.size() << endl;

    for(auto v: res) {
        for(auto a: v) {
            cout << a << " ";
        }
        cout << endl;
    }
}