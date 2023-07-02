//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static cmp(pair<double,int>&p1,pair<double,int>&p2)
    {
        //if(p1.first>p2.first)return 1;
        return p1.first>p2.first;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double,int>>s;
        for(int i=0;i<n;i++)
        {
            s.push_back({(double)(((double)arr[i].value)/(double)(arr[i].weight)),i});
        }
        sort(s.begin(),s.end(),cmp);
        double ans=0;
        int i=0;
      //  for(auto x:s)cout<<x.first<<" "<<x.second<<endl;
        while(w>=1&&i<n)
        {
           // cout<<ans<<" "<<w<<" ";
            if(w-arr[s[i].second].weight>=0)
            {
                w=w-arr[s[i].second].weight;
                ans+=arr[s[i].second].value;
            }
            else
            {
                ans+=(double)s[i].first*w;
                w=0;
                
            }
          //  cout<<w<<" "<<ans<<endl;
            i++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends