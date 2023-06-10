/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*代码逻辑
用两个指针分别遍历两端链表,则在终点前两个指针必然能相遇在公共节点
当上下两个链表长度a,b不一样长时,不妨设a > b,则必然下面的指针快于上面的指针,但是由于最终必然会相遇,所以必然相遇才公共节点
若a = b 则第一次就能相遇
若无公共节点，模拟一下，代码也适用。
*/
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while(p != q)
        {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
