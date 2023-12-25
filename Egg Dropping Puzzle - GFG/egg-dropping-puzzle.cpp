//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        
        for(int egg=1; egg<=n; egg++)
        {
            for(int floor=1; floor<=k; floor++)
            {
                if(egg==1)
                {
                    dp[egg][floor]=floor;
                }
                else if(floor==1)
                {
                    dp[egg][floor]=1;
                }
                else
                {
                    int bestMini = INT_MAX;
                    for(int curr = floor-1, prev=0; curr>=0; curr--, prev++)
                    {
                        int prevFloorWorst = dp[egg][curr]; // Egg survives
                        int myFloorWorst = dp[egg-1][prev]; // Egg breaks
                        
                        int worst = max(prevFloorWorst, myFloorWorst);
                        bestMini = min(bestMini, worst);
                    }
                    
                    dp[egg][floor] = bestMini+1;
                }
            }
        }
        
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends