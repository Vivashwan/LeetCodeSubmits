//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int mis[n];

        for (int i = 0; i < n; i++) {
            mis[i] = a[i];
        }

        int maxIncreasingSequenceSum = a[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && a[i] + mis[j] > mis[i]) {
                    mis[i] = a[i] + mis[j];
                    maxIncreasingSequenceSum = std::max(maxIncreasingSequenceSum, mis[i]);
                }
            }
        }

        return maxIncreasingSequenceSum;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends