/**
 * 输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return nullptr;
        ListNode *newHead = pHead;
        ListNode *p = pHead->next;
        newHead->next = nullptr;
        ListNode *t = 0;

        while(p) {
            t = p;
            p = p->next;
            t->next = newHead;
            newHead = t;
        }

        return newHead;
    }
};

int main() {
    ListNode *L1 = new ListNode(0);
    ListNode *L2 = new ListNode(1);
    L1->next = L2;
    Solution s;
    ListNode *L = s.ReverseList(L1);
    while(L) {
        cout << L->val << " ";
        L = L->next;
    }
}