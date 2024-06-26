class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        
        if (k >= n - 1) {
            return *max_element(arr.begin(), arr.end());
        }
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            q.push(arr[i]);
        }

        int count = 0;
        int maxVal = q.front();
        q.pop();
        
        while (count < k) {
            int val2 = q.front();
            q.pop();
            
            if (maxVal > val2) {
                count++;
                q.push(val2);
            } else {
                q.push(maxVal);
                maxVal = val2;
                count = 1;
            }
        }
        
        return maxVal;
    }
};