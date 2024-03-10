//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool compare(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        //only one meeting at a time and the end time  of a meeting should not be equal 
        // to the start time of another meeting:
        vector<pair<int,int> > a;
        for(int i=0;i<n;i++){
            a.push_back({start[i],end[i]});
        }
        
        sort( a.begin() , a.end() , [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
        int count=1;
        int ansend=a[0].second;
        for(int i=1;i<n;i++){
            if(a[i].first > ansend){
                count++;
                ansend=a[i].second;
            }
        }
        return count;
        
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
