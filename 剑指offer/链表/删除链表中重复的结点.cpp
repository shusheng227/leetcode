/**
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==0 || pHead->next==0) return pHead;
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = pHead;
        ListNode *p1 = dummyhead;
        ListNode *p2 = pHead;
        ListNode *p3 = pHead->next;

        while(p3) {
            if(p2->val == p3->val) {
                while(p3 && p3->val == p2->val) {
                    ListNode *temp = p3;
                    p3 = p3->next;
                    p2->next = p3;
                    delete temp;
                }
                if(!p3) {
                    delete p2;
                    p1->next = p2 =0;
                    break;
                }
                else {
                    ListNode *temp = p2;
                    p2 = p3;
                    p3 = p3->next;
                    p1->next = p2; 
                    delete temp;
                }
            }
            else {
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
        }

        p1 = dummyhead->next;
        delete dummyhead;
        return p1;
    }
};

int main() {
    int a[] = {1,1,1,1,1};
    int len = 5;
    ListNode *head = new ListNode(a[0]);
    ListNode *p = head;
    for(int i=1; i<len; i++) {
        ListNode *temp = new ListNode(a[i]);
        p->next = temp;
        p = p->next;
    }
    Solution s;
    head = s.deleteDuplication(head);
    p = head;
    int i= 0;
    while(p && i<5){
        cout << p->val << ' ';
        p = p->next;
        i++;
    }
}