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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev=nullptr;
        while(head)
        {
            ListNode* pp=head->next;
            head->next=prev;
            prev=head;
            head=pp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* on=rev(l1);
        ListNode* tw=rev(l2);
        ListNode* aa=new ListNode();
        ListNode* ans=aa;
        int c=0;
        while(on&&tw)
        {
            int x=on->val+tw->val+c;
            c=x/10;
            x=x%10;
            ListNode* tt=new ListNode(x);
            aa->next=tt;
            aa=aa->next;
            on=on->next;
            tw=tw->next;
        }
        while(on)
        {
            int x=on->val+c;
            c=x/10;
            x=x%10;
            ListNode* tt=new ListNode(x);
            aa->next=tt;
            aa=aa->next;
            on=on->next;            
        }
        while(tw)
        {
            int x=tw->val+c;
            c=x/10;
            x=x%10;
            ListNode* tt=new ListNode(x);
            aa->next=tt;
            aa=aa->next;
            tw=tw->next;
        }
        if(c!=0)
        {
            ListNode* tt=new ListNode(c);
            aa->next=tt;
            aa=aa->next;
        }
        return rev(ans->next);
    }
};