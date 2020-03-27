/**
 * 输入两个链表，找出它们的第一个公共结点。
 * （注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
 */
/**
 * 思路：
 * 刚开始想到的时两重循环进行判断，但这种方法时间太长
 * 可以使用hashmap，先记录第一个链表的指针，再跟第二个进行比较
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        map<ListNode *, int> m;
        ListNode *p = pHead1;

        while(p) {
            ++m[p];
            p = p->next;
        }
        p = pHead2;
        while(p) {
            if(m[p]) {
                return p;
            }
            p = p->next;
        }

        return nullptr;
    }
};