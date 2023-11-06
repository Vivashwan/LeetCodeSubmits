class Solution {
    private:
    bool func(vector<int>&nums, int n, int sum, vector<vector<bool>>&dp)
    {
        for(int i=0; i<n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= sum)
            dp[0][nums[0]] = true;

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                bool pick = false;
                if(nums[i]<=j)
                {
                    pick = dp[i-1][j-nums[i]];
                }
                bool notPick = dp[i-1][j];

                dp[i][j] = pick || notPick;
            }
        }

        return dp[n-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();

        int sum = 0;

        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }

        int k = sum/2;
        vector<vector<bool>>dp(n, vector<bool>(k+1, false));
        if(sum%2==1)
        {
            return false;
        }
        else return func(nums, n, k, dp);         
    }
};