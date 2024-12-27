class Solution { //TC- O(n) SC- O(n)
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(int &ele : answers){
            m[ele]+=1;
        }
        int total=0;
        for(auto &i : m){
            int grpsize= i.first+1;
            int grps= (int)ceil(i.second*1.0/grpsize);
            total+=grps*grpsize;
        }
        return total;
    }
};

//Alternative logic
for (auto it : mp) {
            if (it.first==0) {
                // If the answer is 0, each rabbit is alone
                ans+=it.second;
            }
            if (it.second<(it.first+1) && it.first!=0) {
                // If the number of rabbits giving the 
                //answer is less than the group size
                ans+=(it.first+1);
            }
            if ((it.first+1==it.second) && it.first!=0) {
                // If the number of rabbits giving 
                //the answer exactly matches the group size
                ans += it.second;
            }
            if (it.second>(it.first + 1) && it.first!=0) {
                // If the number of rabbits giving 
                //the answer exceeds the group size
                int groups=(it.second+it.first)/(it.first+1); 
                ans+=groups*(it.first+1);
            }
