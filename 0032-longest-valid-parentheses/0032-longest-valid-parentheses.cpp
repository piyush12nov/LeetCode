class Solution
{
    public:

        int longestValidParentheses(string s)
        {
            vector<pair<int, int>> v;
            stack<pair<char, int>> st;
            for (int i = 0; i < s.size(); i++)
            {
                char ch = '1';
                int ind = -1;
                if (!st.empty())
                {
                    ch = st.top().first;
                    ind = st.top().second;
                }
                int kk = i;
                int flag = 0;
                if (!st.empty() && s[i] == ')' && ch == '(')
                {
                    st.pop();
                    flag = 1;
                }
                if (flag)
                {
                    v.push_back({ ind, kk });
                }
                if (flag == 0 && s[i] == '(')
                {
                    st.push(make_pair('(', i));
                }
            }
            sort(v.begin(), v.end());
          
            int ans = 0, nn = v.size();
            
            for (int i = 0; i < nn; i++)
            {
                int a = v[i].first;
                int b = v[i].second;

                while (i + 1 < nn && v[i + 1].first <= b + 1)
                {

                    a = min(v[i + 1].first, a);
                    b = max(v[i + 1].second, b);
                    i++;
                }
                ans = max(ans, b - a + 1);
            }

            return ans;
        }
};