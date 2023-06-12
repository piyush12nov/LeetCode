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

	ListNode* rotateRight(ListNode *head, int k)
	{
		int n = 0;
		ListNode *f = head;
		ListNode *ss = new ListNode(0);
		ListNode *ans = ss;
		while (f)
		{
			f = f->next;
			n++;
		}

		if (n == 0) return head;
		
        ListNode *hh = rev(head, n);
		k = k % n;
		
        ListNode *temp = rev(hh, k);
		ss->next = temp;
		int kk = k;
		
        while (kk--) ss = ss->next;
		ListNode *ttemp = rev(hh, n - k);
		ss->next = ttemp;

		return ans->next;
	}
};
