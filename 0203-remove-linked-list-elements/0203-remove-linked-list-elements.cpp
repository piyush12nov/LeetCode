/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int re_) {
        ListNode* te=head;
        ListNode* cur=head;
        ListNode* aa=new ListNode();
        ListNode* ans=aa;
        while(cur)
        {
            if(cur->val==re_){cur=cur->next;continue;}
            ListNode* te=new ListNode(cur->val);
            aa->next=te;
            aa=aa->next;
            cur=cur->next;
        }
        return ans->next;
    }
};