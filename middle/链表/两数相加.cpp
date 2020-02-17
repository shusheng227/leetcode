/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        int val1 = l1->val, val2 = l2->val, val = val1+val2;
        int carry = val>=10; //是否有进位的标志
        ListNode *head = new ListNode(val%10);   //保存返回结果
        ListNode *tail = head;
        ListNode *t1=l1->next, *t2=l2->next;

        while(t1||t2) {
            //初始化加数
            if(!t1) val1 = 0;
            else val1 = t1->val;
            if(!t2) val2 = 0;
            else val2 = t2->val;

            //处理加法结果
            val = val1 + val2 + carry;
            carry = val>=10;
            ListNode *temp = new ListNode(val%10);
            tail->next = temp;
            tail = temp;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }

        // 若最后一次相加结果有进位，链表最前面加个1
        if(carry) {
            ListNode *temp = new ListNode(1);
            tail->next = temp;
            tail = temp;
        }

        return head;
    }
};


