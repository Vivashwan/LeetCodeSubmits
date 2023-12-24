//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isPalindrome(int i, int j, string& str)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                return false;
            }

            i++, j--;
        }

        return true;
    }

    int func(string& s, int n, vector<int>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            int mini = INT_MAX;

            for(int j=ind; j<n; j++)
            {    
                if(isPalindrome(ind, j, s))
                {
                    int ans = 1 + dp[j+1];
                    mini = min(mini,ans);
                }
            }

            dp[ind] = mini;
        }

        return dp[0];
    }

public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();

        vector<int>dp(n+1, 0);

        return func(str, n, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends