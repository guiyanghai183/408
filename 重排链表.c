/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*代码逻辑
1 计算链表节点数量
2 将链表分成两段
3 倒序重排后面的链表
4 将两段链表接起来
*/
class Solution {
public:
    void rearrangedList(ListNode* head) {
        if(!head->next) return;
        int n = 0;
        for(auto p = head; p; p = p->next) n ++ ;
        int left = (n + 1) / 2;
        auto a = head;
        for(int i = 0; i < left - 1; i ++ ) a = a->next;
        auto b = a -> next, c = b -> next;
        
        a->next = b->next = NULL;
        while(c)
        {
            auto p = c->next;
            c->next = b;
            b = c, c = p;
        }
        
        for(auto p = head, q = b; q;)
        {
            auto o = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            q = o;
        }
    }
};
