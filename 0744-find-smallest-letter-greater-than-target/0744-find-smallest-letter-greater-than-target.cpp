class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mm=INT_MAX;
        char ans=letters[0];
        for(auto x:letters)
        {
            if(target-x<0)
            {
                if(abs(target-x)<mm)
                {
                    ans=x;
                    mm=abs(target-x);
                }
            }
        }
        return ans;
    }
};