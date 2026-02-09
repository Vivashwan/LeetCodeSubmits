class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;

        stack<int>st;

        for(auto it: nums)
        {
            while(!st.empty() && st.top()>it)
            {
                res++;
                st.pop();
            }

            if(it>0 && (st.empty() || st.top()<it))
            {
                st.push(it);
            }
        }

        res+=st.size();

        return res;
    }
};