/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */
#include <iostream>
#include <map>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<ListNode *, int> m;
        ListNode *p = pHead;

        for( ; p!=0; p=p->next) {
            if(m.count(p)) return p;
            else ++m[p];
        }

        return NULL;
    }
};