/**
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */
/**
 * 思路：
 * 假设原来链表为A->B->C，则先复制链表为A->A'->B->B'->C->C'；
 * 根据A、B、C关系将A'、B'、C'的随机指针拷贝，接着将链表恢复原状并将A'、B'、C'提取出来
 **/
#include <iostream>
using namespace std;

struct RandomListNode {
    int val;
    RandomListNode* next;
    RandomListNode* random;
    
    RandomListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        //复制链表，将链表扩充
        RandomListNode *h = pHead;
        while(h) {
            RandomListNode *temp = new RandomListNode(h->label);
            temp->next = h->next;
            h->next = temp;
            h = h->next->next;
        }

        //复制随机指针
        h = pHead;
        while(h) {
            if(h->random) {
                h->next->random = h->random->next;
            }

            h=h->next->next;
        }
        //cout << "finish copy2！" << endl;

        //复原链表，提取出新链表
        RandomListNode *h1 = pHead->next;
        RandomListNode *p = h1;
        h = pHead->next = p->next;
        while(h) {
            p->next = h->next;
            h->next = h->next->next;
            h = h->next;
            p = p->next;
        }

        return h1;
    }
};