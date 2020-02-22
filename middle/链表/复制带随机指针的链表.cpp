/**
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 要求返回这个链表的 深拷贝。
 */
/**
 * 思路：
 * 假设原来链表为A->B->C，则先复制链表为A->A'->B->B'->C->C'；
 * 根据A、B、C关系将A'、B'、C'的随机指针拷贝，接着将链表恢复原状并将A'、B'、C'提取出来
 **/

#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        //复制链表，将链表扩充
        Node *h = head;
        while(h) {
            //cout << "begin copy " << h->val << endl;
            Node *temp = new Node(h->val);
            temp->next = h->next;
            h->next = temp;
            h = h->next->next;
        }
        //cout << "finish copy1！" << endl;

        //复制随机指针
        h = head;
        while(h) {
            if(h->random) {
                h->next->random = h->random->next;
            }

            h=h->next->next;
        }
        //cout << "finish copy2！" << endl;

        //复原链表，提取出新链表
        Node *h1 = head->next;
        Node *p = h1;
        h = head->next = p->next;
        while(h) {
            p->next = h->next;
            h->next = h->next->next;
            h = h->next;
            p = p->next;
        }
        //cout << "finish recover！" << endl;

        return h1;
    }
};

int main() {
    Node *head = new Node(0);
    Node *h = head;
    for(int i=1; i<3; i++) {
        Node *temp = new Node(i);
        h->next = temp;
        h = h->next;
    }

    //0->1,1->0,2->0
    h = head;
    h->random = head->next;
    h = h->next;
    h->random = head;
    h = h->next;
    h->random = head;

    Solution s;
    Node *result = s.copyRandomList(head);
}