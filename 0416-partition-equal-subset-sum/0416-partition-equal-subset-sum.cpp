class Solution {
    private:
    bool func(vector<int>&nums, int ind, int sum, vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(nums[ind]==sum)
            {
                return true;
            }
            else return false;
        }

        if(sum==0)
        {
            return true;
        }

        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }

        bool pick = false;
        if(sum-nums[ind]>=0)
        {
            pick = func(nums, ind-1, sum-nums[ind], dp);
        }
        bool notPick = func(nums, ind-1, sum, dp);

        dp[ind][sum] = pick || notPick;

        return pick || notPick;
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

        vector<vector<int>>dp(n, vector<int>(sum/2+1, -1));
        if(sum%2==1)
        {
            return false;
        }
        else return func(nums, n-1, sum/2, dp);         
    }
};