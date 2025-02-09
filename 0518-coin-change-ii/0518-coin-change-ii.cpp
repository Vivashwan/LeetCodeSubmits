class Solution {
private:
    int func(vector<int>& coins, int amount, int n, vector<vector<int>>&dp)
    {
        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=0; i<=amount; i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i] = 1;
            }
        }

        for(int ind=1; ind<n; ind++)
        {
            for(int target = 0; target<=amount; target++)
            {
                int notPick = 0, pick = 0;
                
                notPick += dp[ind-1][target];

                if(coins[ind]<=target)
                {
                    pick += dp[ind][target-coins[ind]];
                }

                dp[ind][target] = pick+notPick;
            }
        }

        return dp[n-1][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, 0));

        return func(coins, amount, n, dp);
    }
};