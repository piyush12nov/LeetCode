class Solution
{
    public:
        double myPow(double x, int n)
        {
            double y;
            if (n == 0) return 1;
            y = myPow(x, n / 2);
            if (n % 2 == 0) return y * y;
            else
            {
                if (n > 0) return x *y * y;
                else return (y *y) / x;
            }
        }
};