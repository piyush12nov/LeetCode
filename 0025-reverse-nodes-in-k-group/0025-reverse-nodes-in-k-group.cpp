/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* rev(ListNode* &head, int k)
        {
            ListNode *prev = nullptr;
            while (head && k--)
            {
                ListNode *rr = head->next;
                head->next = prev;
                prev = head;
                head = rr;
            }
            return prev;
        }
    ListNode* reverseKGroup(ListNode *head, int k)
    {

        ListNode *f = head;
        ListNode *aa = new ListNode(0);
        ListNode *you = aa;
        int n = 0;
        while (f)
        {
            n++;
            f = f->next;
        }
        int kk, nn = n;
        while (n >= k)
        {
            ListNode *temp = rev(head, k);
            aa->next = temp;
            kk = k;
            while (kk--) aa = aa->next;
            n = n - k;
        }
        if (nn % k != 0)
            aa->next = head;

        return you->next;
    }
};