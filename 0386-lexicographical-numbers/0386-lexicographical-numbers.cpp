class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string>st;
        vector<int>v;

        for(int i=1; i<=n; i++)
        {
            st.insert(to_string(i));
        }

        for(auto it: st)
        {
            v.push_back(stoi(it));
        }

        return v;
    }
};