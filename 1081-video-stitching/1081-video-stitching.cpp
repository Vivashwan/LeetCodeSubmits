class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();

        sort(clips.begin(), clips.end());

        for(auto it: clips)
        {
            cout<<"{"<<it[0]<<","<<it[1]<<"}, ";
        }

        int count=0, end=0, i=0;

        while(end<time)
        {
            int curr=end;

            while(i<n && clips[i][0]<=end)
            {
                curr=max(curr, clips[i][1]);
                i++;
            }

            if(curr==end)
            {
                return -1;
            }

            end=curr;
            count++;
        }

        return count;
    }
};