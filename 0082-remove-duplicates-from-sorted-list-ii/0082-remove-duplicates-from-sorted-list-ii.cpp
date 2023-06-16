/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            if (!head) return head;
            ListNode *tt = new ListNode(0);
            ListNode *ans = tt;
            while (head)
            {
                int flag = 1;
                while (head->next != nullptr && head->val == head->next->val)
                {
                    flag = 0;
                    head = head->next;
                    if (!head->next)
                    {
                        flag = 2;
                        break;
                    }
                }

                if (flag == 1)
                {
                    tt->next = head;
                    tt = tt->next;
                }
                if (flag == 2)
                {
                    tt->next = nullptr;
                }
                head = head->next;
            }
            return ans->next;
        }
};