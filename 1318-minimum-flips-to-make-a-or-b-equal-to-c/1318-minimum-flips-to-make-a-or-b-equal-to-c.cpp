class Solution
{
    public:
        int minFlips(int x, int y, int z)
        {
            int i, ans = 0;
            
            vector<int> a(32, 0), b(32, 0), c(32, 0);
            
            for (i = 0; i < 32; i++)
            {
                a[i] = x % 2;
                x = x / 2;
                b[i] = y % 2;
                y = y / 2;
                c[i] = z % 2;
                z = z / 2;
            }
            
            for (i = 0; i < 32; i++)
            {
                if (a[i] + b[i] == 1 && c[i] == 0) ans++;
                if (a[i] + b[i] == 2 && c[i] == 0) ans += 2;
                if (a[i] + b[i] == 0 && c[i] == 1) ans++;
            }
            
            return ans;
        }
};