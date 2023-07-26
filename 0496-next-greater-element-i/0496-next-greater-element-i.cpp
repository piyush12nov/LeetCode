class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        st.push(nums2[n-1]);
        map<int,int>pre;
        pre[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty()&&st.top()<nums2[i])
            {
                st.pop();
            }
            if(st.empty())pre[nums2[i]]=-1;
            else pre[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=pre[nums1[i]];
        }
        return nums1;
        
    }
};