/**
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *h = dummyHead;
        ListNode *p = pHead1;
        ListNode *q = pHead2;

        while(p && q) {
            if(p->val < q->val) {
                h->next = p;
                p = p->next;
            }
            else {
                h->next = q;
                q = q->next;
            }
            h = h->next;
        }
        if(p) h->next = p;
        else h->next = q;

        h = dummyHead->next;
        delete dummyHead;
        return h;

    }
};