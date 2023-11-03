class Solution {
public:
    
    int dp[1005][2];
    
    int helper(vector<int>& nums, int i, int n, bool flag)
    {
        // if one element is present
        
        if(i == n - 1)
            return 1;
        
        // if already calculated
        
        if(dp[i][flag] != -1)
            return dp[i][flag];
        
        int ans = 0;
        
        if(flag)  // we need positive diff.
        {
            if(nums[i + 1] > nums[i])  // include
            {
                ans = max(ans, 1 + helper(nums, i + 1, n, false));
            }
            else  // exclude
            {
                ans = max(ans, helper(nums, i + 1, n, true));
            }
        }
        else   // we need negative diff
        {
            if(nums[i + 1] < nums[i])   // include
            {
                ans = max(ans, 1 + helper(nums, i + 1, n, true));
            }
            else  // exclude
            {
                ans = max(ans, helper(nums, i + 1, n, false));
            }
        }
        
        // store the ans in dp
        
        return dp[i][flag] = ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = INT_MIN;
        
        memset(dp, -1, sizeof(dp));
        
        // by taking positive as first diff.
        
        ans = max(ans, helper(nums, 0, n, true));
        
        memset(dp, -1, sizeof(dp));
        
        // by taking negative as first diff.
        
        ans = max(ans, helper(nums, 0, n, false));
        
        return ans;
    }
};