/**
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 */

/**
 * 思路：
 * 以头节点为"标兵"，将之后的节点于头节点对比
 * 如值大于头节点值，排到头节点后面，否则排至头节点前面
 */

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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        ListNode *h = head->next;
        ListNode *pre = head;   //排序后的链表的头指针
        head->next = NULL;

        while(h) {
            int val = h->val;
            ListNode *temp = head;          
            if(head->val > h->val) {
                //当前节点值小于头节点值
                if(pre->val > h->val) {
                    //当前节点值小于排序后头节点值，将当前节点移至头节点
                    ListNode *temp2 = h;
                    h = h->next;
                    temp2->next = pre;
                    pre = temp2;
                    continue ;
                }
                temp = pre;               
            }
            //索引当前节点排序后节点位置
            while(temp->next && (temp->next->val < val)) {
                temp = temp->next;
            }
            ListNode *temp2 = h;
            h = h->next;
            temp2->next = temp->next;
            temp->next = temp2; 
        }

    }
};