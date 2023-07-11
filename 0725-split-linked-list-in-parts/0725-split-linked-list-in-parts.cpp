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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* g = head;
        int n=0;
        while(g)
        {
            g=g->next;
            n++;
        }
        int req=n/k;
        int obb=n%k;
        vector<ListNode*>ans;
        while(n>0)
        {
            int rr=req;
            if(obb>0)
            {
                rr++;
                obb--;
            }
            n=n-rr;
            cout<<rr<<" ";
            ListNode* s=head;
            ListNode* ss=s;
            rr--;
            head=head->next;
            
            while(rr--&&s)
            {
                s=s->next;
                head=head->next;
            }
            if(s!=nullptr)
            s->next=nullptr;
            ans.push_back(ss);
        }
        while(ans.size()<k)
        {
            ListNode* t=nullptr;
            ans.push_back(t);
        }
        return ans;
    }
};