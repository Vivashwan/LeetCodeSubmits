class Solution {
private:
    vector<int>ans1, ans2;
    int n;
public:
    Solution(vector<int>& nums) {
        ans1 = nums;
        ans2 = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return ans1;
    }
    
    vector<int> shuffle() {

        for (int i = 0; i < ans2.size(); i++) 
        {
            int j = i + rand() % (ans2.size() - i);
            swap(ans2[i], ans2[j]);
        }

        return ans2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */