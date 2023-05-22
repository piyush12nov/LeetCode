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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        ListNode* cur=head;
        int c=0;
        for(;cur!=nullptr;)
        {
            c=0;
            while(cur!=nullptr&&cur->val==0)cur=cur->next;
            while(cur!=nullptr&&cur->val!=0){c+=cur->val;cur=cur->next;}
            if(c!=0){
            ListNode* temp=new ListNode(c);
            ans->next=temp;
            ans=ans->next;}
        }
        return res->next;
    }
};