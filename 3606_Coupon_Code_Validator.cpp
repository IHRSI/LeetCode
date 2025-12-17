class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {//TC=O(n∗m+n+Klogk*S), SC=O(n+n*L)=O(n*L)
        int n=code.size();
        vector<int> valid;//O(n)
        for(int i=0;i<n;++i){//O(n)
            if(!isActive[i]) continue;
            else{
                string s=businessLine[i];
                if(s=="electronics" || s=="grocery" || s=="pharmacy" || s=="restaurant"){
                    if(code[i].size()==0) continue;
                    bool check=true;
                    for(char c:code[i]){//O(m)
                        if(c=='_' || isalnum(c)) continue;
                        else{
                            check=false;
                            break;
                        }
                    }
                    if(check) valid.push_back(i);
                }
                else continue;
            }
        }
        vector<string> grps[4];//O(n*L)
        for(int i:valid){//O(n)
            if(businessLine[i][0]=='e') grps[0].push_back(code[i]);
            else if(businessLine[i][0]=='g') grps[1].push_back(code[i]);
            else if(businessLine[i][0]=='p') grps[2].push_back(code[i]);
            else grps[3].push_back(code[i]);
        }
        vector<string> validcodes;//O(n*L)
        //Worst case: all coupons fall into one group. Sorting k strings: Comparisons: O(k log k)
        //S = average length of a coupon code
        for(auto a:grps){//O(klogk*S)
            sort(a.begin(),a.end());//O(klogk)
            for(auto c:a){
                validcodes.push_back(c);
            }
        }
        return validcodes;
    }
};
