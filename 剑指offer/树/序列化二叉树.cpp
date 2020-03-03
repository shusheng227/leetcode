/**
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 * 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
 * 序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，
 * 序列化时通过某种符号表示空节点（#），以 ！表示一个结点值的结束（value!）。
 * 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
 */

#include <iostream>
#include <cstring>
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
    char* Serialize(TreeNode *root) {
        if(root == nullptr) return nullptr; 

        string *reshelper = new string();
        SerializeHelper(root, *reshelper);

        return (char *)(*reshelper).c_str();
    }
    
    TreeNode* Deserialize(char *str) {
        if(str == nullptr) return nullptr;

        TreeNode *T = nullptr;
        DeserializeHelper(&T, &str);

        return T;
    }

private:
    void SerializeHelper(TreeNode *root, string &res) {
        if(!root) {
            res.append("#!");
        }
        else {
            res.append(to_string(root->val) + "!");
            SerializeHelper(root->left, res);
            SerializeHelper(root->right, res);
        }
    }

    void DeserializeHelper(TreeNode **root, char** str) {
        char *begin = *str;
        char *end = strchr(begin, '!');
        if(end == nullptr) return ;

        //拷贝当前结点数据
        int len = end - begin;
        char val[10] = {0};
        strncpy(val, begin, len);
        *str = end + 1;

        if(val[0] == '#') {
            *root = nullptr;
        }
        else {
            *root = new TreeNode(atoi(val));
            DeserializeHelper(&((*root)->left), str);
            DeserializeHelper(&((*root)->right), str);
        }

    }
};

int main() {
    TreeNode *T1 = new TreeNode(1);
    T1->left = new TreeNode(2);
    T1->right = new TreeNode(3);

    TreeNode *T2 = new TreeNode(4);
    T2->left = new TreeNode(5);

    TreeNode *T = new TreeNode(0);
    T->left = T1;
    T->right = T2;

    Solution s;
    char *res = s.Serialize(T);
    cout << res <<endl;
        
}