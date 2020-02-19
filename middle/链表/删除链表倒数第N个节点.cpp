/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 */

/**
 * 思路:
 * 定义两个指针p和q，p和q最开始都指向链表头节点
 * 先将q移动n个节点，此时p和q相差n个节点
 * 接着将p和q同时移动，当q指向NULL时，p指向倒数第n个节点
 **/
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //定义用于返回的头指针
        ListNode* pre = new ListNode(0);
        pre->next = head;

        //移动指针
        ListNode* p = pre, *q = pre;
        for(int i=0; i<n+1; i++) {
            q = q->next;
        }
        while(q){
            q = q->next;
            p = p->next;
        }

        //删除倒数第n个节点
        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;

        //重新定义头指针，防止head指针被删除
        ListNode *h = pre->next;
        delete pre;
        return h;

    }
};

