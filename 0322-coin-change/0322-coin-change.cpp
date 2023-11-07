class Solution {
public:
    int func(vector<int>&coins, int n, int amount, vector<vector<int>>&dp)
    {
        for(int i=0; i<=amount; i++)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i]=i/coins[0];
            }
            else dp[0][i] = 1e9;
        }

        for(int ind=1; ind<n; ind++)
        {
            for(int target=0; target<=amount; target++)
            {
                int notPick = 0+dp[ind-1][target];

                int pick = 1e9;
                if(coins[ind]<=target)
                {
                    pick = 1+dp[ind][target-coins[ind]];
                }
                
                dp[ind][target] = min(pick, notPick); 

            }
        }

        return dp[n-1][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, 0));

        int ans = func(coins, n, amount, dp);

        if(ans>=1e9)
        {
            return -1;
        }
        else return ans;
    }
};