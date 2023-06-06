class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            while(!(s[l]<='z'&&s[l]>='a')&&!(s[l]<='Z'&&s[l]>='A')&&l<r)l++;
            while(!(s[r]<='z'&&s[r]>='a')&&!(s[r]<='Z'&&s[r]>='A')&&l<r)r--;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};