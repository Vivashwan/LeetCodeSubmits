class Solution {
public:
    int func(vector<int>&coins, int ind, int amount, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        
        if(ind==0)
        {
            if(amount % coins[0] == 0)
            {
                return amount / coins[0]; 
            }
            else
            {
                return 1e9;
            }
        }

        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }

        int notPick = 0+func(coins, ind-1, amount, dp);

        int pick = 1e9;
        if(coins[ind]<=amount)
        {
            pick = 1+func(coins, ind, amount-coins[ind], dp);
        }
        
        dp[ind][amount] = min(pick, notPick); 

        return min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int ans = func(coins, n-1, amount, dp);

        if(ans>=1e9)
        {
            return -1;
        }
        else return ans;
    }
};