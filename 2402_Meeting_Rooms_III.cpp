//Intution is normal but implementation was tricky.
/*
Let N be the number of rooms.
Let M be the number of meetings.
Time complexity: O(M⋅logM+M⋅logN). Sorting meetings will incur a time complexity of O(M⋅logM).
Popping and pushing into the priority queue will each cost O(logN).
These priority queue operations run inside a for loop that runs at most M times leading to a time complexity of O(M⋅logN).
The inner nested loop will incur a time complexity of O(logN). 
The combined time complexity will be O(M⋅logM+M⋅logN). As per the constraints N is small, the term O(M⋅logM) will dominate.
Note: Initializing unused_rooms will cost O(N) in ruby and python. But will cost O(N⋅logN) in C++ and Java due to the implementation.
Space complexity: O(N+sort). Initializing unused_rooms and meeting_count will incur a space complexity of O(N).
Some extra space is used when we sort an array of size N in place. The space complexity of the sorting algorithm depends on the programming language.
*/
//Used 2 min heap
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {//TC= O(M⋅logM+M⋅logN) , SC=O(3N+logM)~(N+logM) , logM goes in sorting in worst case
        vector<int> meet_ct(n,0);
        priority_queue<int,vector<int>,greater<int>> unused_rooms;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> busy_rooms;
        for(int i=0;i<n;++i) unused_rooms.push(i);
        sort(meetings.begin(),meetings.end());

        for(auto meet: meetings){
            int start=meet[0],end=meet[1];
            while(!busy_rooms.empty() && busy_rooms.top().first<=start){
                int room=busy_rooms.top().second;
                busy_rooms.pop();
                unused_rooms.push(room);
            }
            if(!unused_rooms.empty()){
                int room=unused_rooms.top();
                unused_rooms.pop();
                busy_rooms.push({end,room});
                ++meet_ct[room];
            }else{
                auto [room_free_time,room]=busy_rooms.top();
                busy_rooms.pop();
                busy_rooms.push({room_free_time+end-start,room});
                ++meet_ct[room];
            }
        }

        int most_busy_room_ct=*max_element(meet_ct.begin(),meet_ct.end());
        int max_busy_room=0;
        for(int i=0;i<n;++i){
            if(most_busy_room_ct==meet_ct[i]){
                max_busy_room=i;
                break;
            }
        }
        return max_busy_room;
    }
};

//Without min heap. Used indexes for room no.
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {//TC= O(M⋅logM+M*N) , SC=O(2N+logM)~(N+logM) , logM goes in sorting in worst case
        vector<long long> roomAvailabilityTime(n, 0);
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());
        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;
            for (int i = 0; i < n; i++) {
                if (roomAvailabilityTime[i] <= start) {
                    foundUnusedRoom = true;
                    meetingCount[i]++;
                    roomAvailabilityTime[i] = end;
                    break;
                }
                if (minRoomAvailabilityTime > roomAvailabilityTime[i]) {
                    minRoomAvailabilityTime = roomAvailabilityTime[i];
                    minAvailableTimeRoom = i;
                }
            }
            if (!foundUnusedRoom) {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }
        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
