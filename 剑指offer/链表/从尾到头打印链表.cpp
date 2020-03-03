/**
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 */
/**
 * 思路：
 * （1）使用vector的头部插入法
 * （2）使用stack
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) { }
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int> v;
        ListNode *h = head;
        for( ; h!=0; h=h->next) {
            v.insert(v.begin(), h->val);
        }
        return v;
    }
};