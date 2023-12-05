//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int, int> finishingTimeAndMeetingId[n + 1]; // Here, we create a finishingTimeAndMeetingId where first is the finishing time of that meet and second is the meet id

        for (int i = 0; i < n; i++)
        {
            finishingTimeAndMeetingId[i].first = end[i];
            finishingTimeAndMeetingId[i].second = i;
        }
    
        sort(finishingTimeAndMeetingId, finishingTimeAndMeetingId + n); // We sort them in ascending order according to their finishing time
    
        int finishTime = finishingTimeAndMeetingId[0].first; // Now, the meet with minimum finishing time is at the top, so, we store it's finishing time to finishTime variable.
    
        vector<int> meetingIdStorage; // In this vector we will store the meeting ids of meetings that can be performed in a room
    
        meetingIdStorage.push_back(finishingTimeAndMeetingId[0].second + 1); // +1 because of given 1-based indexing and as we are using 0-based indexing so we use +1 for 1-based indexing
        // Here, we also store the id i.e finishingTimeAndMeetingId[0].second of that first meeting cause it has the minimum finish time and also it finishes before any other meeting
        for (int i = 1; i < n; i++) // We run the loop from 1 because we have already store the 0th meeting above
        {
            if (start[finishingTimeAndMeetingId[i].second] > finishTime) // Now, we check if the starting time of the next meeting is greater than the finishing time of the previous meeting or not, if yes, this means this meeting start after the previous meeting ends
            {
                meetingIdStorage.push_back(finishingTimeAndMeetingId[i].second + 1); // So, we store this meeting's id and also add +1 to it for 1-based indexing
    
                finishTime = finishingTimeAndMeetingId[i].first; // Then, we update the finishTime to the finishing time of the current meeting that we just stored in.
            }
        }
    
        return meetingIdStorage.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends