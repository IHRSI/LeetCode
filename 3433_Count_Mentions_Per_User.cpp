//Done(MED)[POTD]-sort(lambda),timestp,vec<str>,stoi,ss
//Let n be numberOfUsers, m be the length of events, and t be the maximum
//TC=O(nm+ mlogmlogt)
//Using custom sorting i.e lambda function
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ct(numberOfUsers);
        vector<int> of(numberOfUsers);
        sort(events.begin(),events.end(),
            [](vector<string> &v1,vector<string> &v2){
                int t1=stoi(v1[1]);
                int t2=stoi(v2[1]);
                if(t1==t2){
                    if(v2[0][1]=='O') return false;
                }
                return true;
            }
        );
        for(auto &eve: events){
            if(eve[0][0]=='M'){
                int ts=stoi(eve[1]);
                vector<string> ids;
                stringstream ss(eve[2]);
                string token;
                while(ss >> token) ids.push_back(token);
                if(ids.size()==1){
                    if(ids[0][0]=='A'){
                        for(int i=0;i<numberOfUsers;++i){
                            ++ct[i];
                        }
                    }
                    else{
                        for(int i=0;i<numberOfUsers;++i){
                            int ts=stoi(eve[1]);
                            if(of[i]==0 || (of[i]+60<=ts)) ++ct[i];
                        }
                    }
                }
                else{
                    for (string &tok : ids) {
                        int id = stoi(tok[2]);
                        if (of[id] == 0 || of[id] + 60 <= ts) {
                            ct[id]++;
                        }
                    }
                }
            }
            else{
                int ts=stoi(eve[1]);
                int id=stoi(eve[2]);
                of[id]=ts;
            }
        }
        return ct;
    }
};
