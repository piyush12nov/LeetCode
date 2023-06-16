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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode* down=new ListNode(0);
        ListNode* up=new ListNode(0);
        ListNode* uu=up;
        ListNode* ans=down;
        while(head)
        {
            while(head&&head->val>=x)
            {
                up->next=head;
                up=up->next;
                head=head->next;
            }
            while(head&&head->val<x)
            {
                down->next=head;
                down=down->next;
                head=head->next;
            }
        }
        up->next=nullptr;
        down->next=uu->next;
        return ans->next;
    }
};