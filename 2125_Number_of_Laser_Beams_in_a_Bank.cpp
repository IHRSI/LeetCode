class Solution {
public:
    int numberOfBeams(vector<string>& bank) {//TC=O(n*m), SC=O(1)
        int ans=0,prev=0;
        for(auto c: bank){
            int curr=0;
            curr=count(c.begin(),c.end(),'1');
            if(curr!=0){
                ans+=prev*curr;
                prev=curr;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {//TC=O(n*m), SC=O(n)
        int ans=0,n=bank.size(),m=bank[0].size();
        vector<int> hsh(n);
        for(int i=0;i<n;++i){//TC=O(n*m)
            int ct1=0;
            ct1=count(bank[i].begin(),bank[i].end(),'1');
            hsh[i]=ct1;
        }
        for(int i=0;i<n;++i){//***- TC=O(n)
            if(hsh[i]!=0){
                for(int j=i+1;j<n;++j){
                    if(hsh[j]!=0){
                        ans+=hsh[i]*hsh[j];
                        i=j-1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
