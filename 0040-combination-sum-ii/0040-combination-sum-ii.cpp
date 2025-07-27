class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, vector<int>& candidates, int target, int start) 
    {
        if(target==0) 
        {
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++) 
        {
            if(i>start && candidates[i]==candidates[i-1])
            { 
                continue;
            }

            if(candidates[i]>target)
            { 
                break;
            }

            temp.push_back(candidates[i]);

            backtrack(ans, temp, candidates, target-candidates[i], i+1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        sort(candidates.begin(), candidates.end());

        backtrack(ans, temp, candidates, target, 0);

        return ans;
    }
};
