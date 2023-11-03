class Solution {
private:
    int func(vector<int>&nums, int target, vector<int>&dp)
    {
        if(target==0)
        {
            return 1;
        }

        if(dp[target]!=-1)
        {
            return dp[target];
        }

        dp[target] = 0; 

        for(auto it: nums)
        {
            if(it<=target)
            {
                dp[target]+= func(nums, target-it, dp);
            }
        }

        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>dp(target+1, -1);

        return func(nums, target, dp);
    }
};