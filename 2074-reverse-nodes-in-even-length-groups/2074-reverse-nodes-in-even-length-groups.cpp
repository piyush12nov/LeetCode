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
            while (k-- && head)
            {
                ListNode *temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            return prev;
        }
    ListNode* reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *f = head;
        ListNode *tt = new ListNode(0);
        ListNode *ans = tt;
        int n = 0, nn;
        while (f)
        {
            n++;
            f = f->next;
        }
        nn = n;
        int req = 1, kk;
        while (n >= req)
        {
            if (req % 2 == 1)
            {
                int qq = req;
                tt->next = head;
                while (qq--)
                {
                    head = head->next;
                    n--;
                    tt = tt->next;
                }
                req++;
            }
            else if (req % 2 == 0)
            {
                ListNode *temp = rev(head, req);
                tt->next = temp;
                kk = req;
                while (kk--) tt = tt->next;
                n = n - req;
                req++;
            }
        }
        ListNode *yt = head;
        int h = 0;
        while (yt)
        {
            yt = yt->next;
            h++;
        }
        if (h > 0 && h % 2 == 0)
        {
            ListNode *temp = rev(head, h);
            tt->next = temp;
        }
        else if (h > 0 && h % 2 == 1)
        {
            tt->next = head;
        }
        return ans->next;
    }
};