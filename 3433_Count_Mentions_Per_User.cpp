//Let n be numberOfUsers, m be the length of events, and t be the maximum
//TC=O(mn+ mlogmlogt)
//Using custom sorting i.e lambda function
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {//SC=O(n)
        vector<int> ct(numberOfUsers);
        vector<int> of(numberOfUsers);
        sort(events.begin(),events.end(),
            [](vector<string> &v1,vector<string> &v2){
                int t1=stoi(v1[1]);
                int t2=stoi(v2[1]);
                if(t1!=t2) return t1<t2;
                if(v2[0][0]=='O') return false;
                return true;
            }
        );
        for(auto &eve: events){
            int ts=stoi(eve[1]);
            if(eve[0][0]=='M'){
                if(eve[2][0]=='A'){
                    for(int i=0;i<numberOfUsers;++i){
                        ++ct[i];
                    }
                }
                else if(eve[2][0]=='H'){
                    for(int i=0;i<numberOfUsers;++i){
                        if(of[i]==0 || (of[i]+60<=ts)) ++ct[i];
                    }
                }
                else{
                    stringstream ss(eve[2]);
                    string tok;
                    while(ss >> tok){
                        int id = stoi(tok.substr(2));
                        ct[id]++;
                    }
                }
            }
            else{
                int id=stoi(eve[2]);
                of[id]=ts;
            }
        }
        return ct;
    }
};
