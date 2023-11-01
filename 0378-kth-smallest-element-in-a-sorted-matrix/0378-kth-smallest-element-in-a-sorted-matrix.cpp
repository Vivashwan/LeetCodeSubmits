class Solution {
private:
    int countOfEleLesserOrEqualTo(vector<vector<int>>& matrix, int x)
    {
        int n = matrix.size(), m = matrix[0].size();
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        int low = matrix[0][0], high = matrix[n-1][m-1];

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(countOfEleLesserOrEqualTo(matrix, mid)>=k)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};