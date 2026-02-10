#include <bits/stdc++.h>
using namespace std;

// Logically, store the pairs of end and start together and then sort using the end-time as base. That is sort according to meetings that end early. 
// Now iterate into the array. Check if the currMeetingStartTime is strictly gretaer than the prevMeetingEndTime, if yes then include the meeting
// Else, we skip the current meeting. Now for the upcomming meeting, this meeting will appear as if it doesn't exist, so to do so, update the cuurMeeting to prevMeeting, this will cause the upcoming meeting to treate the prev as the lastMeetingThatWas actually held

//. T.C -> O(n*log(n))
//. S.C -> O(n)
int maxMeetings(vector<int>& start, vector<int>& end) {
        
    // Store endTime, startTime
    vector<pair<int, int>>arr;
    
    for (int i = 0; i < start.size(); i++) {
        arr.push_back({end[i], start[i]});
    }
    
    // Sort according to meetings that end early
    sort(arr.begin(), arr.end());
    
    // Alwahys consider the first meeting
    int ans = 1;
    
    for (int i = 1; i < arr.size(); i++) {
        
        int currStart = arr[i].second;
        int prevEnd = arr[i-1].first;
        
        // If it is true, then definitely consider the current meeting
        if (currStart > prevEnd) ans++;

        // Else, we skip the current meeting, so just update this element ot the prevOne (which was acutally considered in our answer), this ensures the previous in the upcoing meeting means the previousMeetingThatWasIncludedInt+TheAnswer (hope it makes sense)
        else {
            arr[i] = arr[i-1];
        }
        
    }
    
    return ans;
        
}