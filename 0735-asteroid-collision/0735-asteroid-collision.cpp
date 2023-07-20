class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &a)
        {
            stack<int> s;
            int n = a.size(), i, flag = 1;
            vector<int> ans;
            s.push(a[0]);
            for (i = 1; i < n; i++)
            {
                flag = 1;
                while (!s.empty() && s.top() > 0 && a[i] < 0)
                {
                    if (s.top() < abs(a[i]))
                    {
                        s.pop();
                    }
                    else if (s.top() == abs(a[i]))
                    {
                        flag = 2;
                        s.pop();
                        break;
                    }
                    else if (s.top() > abs(a[i]))
                    {
                        flag = 2;
                        break;
                    }
                }
                if (flag == 1) s.push(a[i]);
            }
            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};