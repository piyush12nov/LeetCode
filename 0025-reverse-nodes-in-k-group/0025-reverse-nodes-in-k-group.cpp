/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}

 *    ListNode(int x) : val(x), next(nullptr) {}

 *    ListNode(int x, ListNode *next) : val(x), next(next) {}

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
				ListNode *temp = head->next;
				head->next = prev;
				prev = head;
				head = temp;
			}

			return prev;
		}

	ListNode* reverseKGroup(ListNode *head, int k)
	{
		ListNode *ans = new ListNode(0);
		ListNode *at = ans;
		while (head)
		{
			ListNode *yt = head;
			int h = k;
			while (yt && h--)
			{
				yt = yt->next;
			}

			if (h <= 0)
			{
				ans->next = rev(head,k);
				while (ans->next)
				{
					ans = ans->next;
				}
			}
			else
			{
				ans->next = head;
				break;
			}
		}

		return at->next;
	}
};
