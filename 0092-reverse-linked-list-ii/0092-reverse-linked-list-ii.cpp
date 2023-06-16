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
        ListNode* rev(ListNode*& head, int k)
        {
            ListNode *prev = nullptr;
            while (head && k--)
            {
                ListNode *temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            return prev;
        }
    ListNode* reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *tt = new ListNode(0);
        ListNode *ans = tt;
        int n;
        n = 0;
        while (head)
        {
            n++;
            if (left == n)
            {
                ListNode *tm = rev(head, right - left + 1);
                tt->next = tm;
                int kk = right - left + 1;
                while (kk--)
                {
                    n++;
                //    head = head->next;
                    tt = tt->next;
                }
            }
            else
            {
                tt->next = head;
                tt = tt->next;
                head = head->next;
            }
        }
        return ans->next;
    }
};