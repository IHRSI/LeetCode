class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
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
