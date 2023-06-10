/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*代码逻辑
开一个bool数组记录链表中每一个节点是否出现过
需记录判断是否需要删除节点的上一个节点,因为链表的结构
所以遍历时判断的是下一个节点是否需要删除,第一个节点需要特判
*/
class Solution {
public:
    ListNode* filterList(ListNode* head) {
        bool st[10001] = {};
        st[abs(head->val)] = true;
        for(auto p = head; p->next ; )
        {
            int x = abs(p->next->val);
            if(st[x])
            {
                auto q = p->next;
                p->next = q->next;
                delete q;
            }
            else
            {
                st[x] = true;
                p = p->next;
            }
        }
        return head;
    }
};
