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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ans=list1;
        a--;
        ListNode* aa=list1;
        while(b>=0){aa=aa->next;b--;}
        while(a>0)
        {
            list1=list1->next;
            a--;
        }
        list1->next=list2;
        int req=abs(a-b)+1;
        while(list2)
        {
            list2=list2->next;
            list1=list1->next;
        }
        list1->next=aa;
        return ans;
    }
};