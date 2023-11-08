class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();

        if(k>n)
        {
            return 0;
        }

        unordered_map<char, int>mp;

        int i;
        for(i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        for (int i = 0; i < n; i++) 
        {
            if (mp[s[i]] < k) 
            {
                int j = i + 1;
                while (j < n && mp[s[j]] < k) 
                {
                    j++;
                }
                return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(j), k));
            }
        }

        return n;
    }
};