class Solution {
private:
    int func(vector<int>& coins, int amount, int n, int ind, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }

        if(ind==0)
        {
            return (amount%coins[ind]==0);
        }

        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }

        int notPick = 0, pick = 0;
        
        notPick += func(coins, amount, n, ind-1, dp);

        if(coins[ind]<=amount)
        {
            pick += func(coins, amount-coins[ind], n, ind, dp);
        }

        dp[ind][amount] = pick+notPick;

        return pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        return func(coins, amount, n, n-1, dp);
    }
};