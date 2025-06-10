class Solution { //TC=O(nlogn) ; SC=O(n)
//Inserting and removing from the priority queue takes O(logn) per operation.
public:
    string clearStars(string s) {
        int n=s.length();
        priority_queue<char,vector<char>,greater<char>> pq;
        unordered_map<char,stack<int>> um;
        int i=-1;
        for(char c: s){
            i++;
            if(c=='*'){
                char small=pq.top();
                pq.pop();
                s[um[small].top()]='*';
                um[small].pop();
            }
            else{
                um[c].push(i);
                pq.push(c);
            }
        }
        string ans="";
        for(char c: s){
            if(c!='*') ans.push_back(c);
        }
        return ans;
    }
};

class Solution {// TC=O(n*26) , SC=O(n)
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

//Alternative - Same implementation as before usinf diff DS
class Solution {//TC=O(nlog26) ,SC=O(n)
public:
    string clearStars(string s) {

        map<char, vector<int>> pos;
        int n = s.size();
        vector<int> removed(n , 0);
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                for(auto & [ch, vecIndex]:pos){
                    if(vecIndex.size()>0){
                        // cout << ch << endl;
                        int indexToBeRemoved = vecIndex[vecIndex.size()-1]; 
                        vecIndex.pop_back();
                        removed[i] = 1;
                        removed[indexToBeRemoved] = 1;
                        break;
                    }
                }
            }else{
                pos[s[i]].push_back(i);
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(!removed[i]){
                ans.push_back(s[i]);
            }
        }

        return ans;

        
    }
};
