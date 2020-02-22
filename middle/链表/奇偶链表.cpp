/**
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *head_uneven = new ListNode(0);    //奇数链表
        ListNode *head_even = new ListNode(0);      //偶数链表      
        ListNode *h = head;
        ListNode *h2 = head_uneven;
        ListNode *h3 = head_even;

        for(int i=1; h!=NULL; h=h->next,i++) {
            if(i%2) {
                h2->next = h;
                h2 = h;                     
            }
            else {
                h3->next = h;
                h3 = h;
            }
        }

        h2->next = head_even->next;
        h3->next = NULL;
        ListNode *dummy_head = head_uneven->next;
        delete head_uneven;
        delete head_even;
        return dummy_head;
    }
};
