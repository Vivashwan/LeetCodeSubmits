class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        int n = arr.size();

        int res = 0, totalSum = 0, givenSum = 0, nextSum = 0;

        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
            givenSum += i * arr[i];
        }

        res = givenSum;

        for (int i = n-1; i >= 1; i--)
        {
            givenSum = givenSum + totalSum - n * arr[i];
            res = max(res, givenSum);
        }

        return res;
    }
};