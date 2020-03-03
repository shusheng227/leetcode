/**
 * 输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k <= 0) return nullptr;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = pListHead;
        ListNode *pre = dummyHead;
        ListNode *vin = dummyHead;

        for(int i=0; i<k && pre!=nullptr; ++i) {
            pre = pre->next;
        }
        if(pre == nullptr) return nullptr;
        while(pre) {
            pre = pre->next;
            vin = vin->next;
        }
        return vin;
    }
};