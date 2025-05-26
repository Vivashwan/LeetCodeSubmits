class Solution {
private:
    vector<int> func(vector<vector<int>>&adj, string& labels, vector<int>&res, int ind)
    {
        vector<int>labelCount(26, 0);

        res[ind]=1, labelCount[labels[ind]-'a']++;

        for(auto it: adj[ind])
        {
            if(!res[it])
            {
                vector<int>child=func(adj, labels, res, it);

                for(int i=0; i<26; i++)
                {
                    labelCount[i]+=child[i];
                }
            }
        }

        res[ind]=labelCount[labels[ind]-'a'];

        return labelCount;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>res(n, 0);

        vector<vector<int>>adj(n);

        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        func(adj, labels, res, 0);        

        return res;   
    }
};