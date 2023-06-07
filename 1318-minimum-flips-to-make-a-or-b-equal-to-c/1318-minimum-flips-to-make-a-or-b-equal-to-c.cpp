class Solution
{
    public:
        int minFlips(int x, int y, int z)
        {
            int i,a,b,c, ans = 0;  
            
            for (;(x||y||z);)
            {
                a = x % 2;
                x = x / 2;
                b = y % 2;
                y = y / 2;
                c = z % 2;
                z = z / 2;
                if (a + b == 1 && c == 0) ans++;
                if (a + b == 2 && c == 0) ans += 2;
                if (a + b == 0 && c == 1) ans++;
            }
            
            return ans;
        }
};