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
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            int prev = head->val, curr;
            head = head->next;
            ListNode *aa = head;
            int i = 1, amin = INT_MAX, amax = INT_MIN, cur=head->val,nex;
            vector<int> v, ans(2,INT_MAX);
            while (aa && aa->next)
            {
                cur=aa->val;
                if (aa->next)
                   nex = aa->next->val;
                if (prev > cur && cur < nex)
                {
                    v.push_back(i);
                    cout << prev << " " << cur << " " << nex << endl;
                }
                else if (prev < cur && cur > nex)
                {
                    v.push_back(i);
                    cout << prev << " " << cur << " " << nex << endl;
                }
                prev = cur;
                i++;
                aa = aa->next;
            }
            if(v.size()<=1)return {-1,-1};
           	for(int i=0;i < v.size()-1;i++)
           	{
           	    cout<<v[i]<<" ";
           	    ans[0]=min(ans[0],v[i+1]-v[i]);
           	}
           	ans[1]=v[v.size()-1]-v[0];

         return ans;
        }
};