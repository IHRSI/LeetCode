//Prefix Sum
class Solution {
public:
    int countValidSelections(vector<int>& nums) {//TC=O(n), SC=O(1)
        int lsum=0;
        int ct=0,n=nums.size();
        int rsum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                if(lsum==rsum) ct+=2;
                else if(lsum==rsum-1 || rsum==lsum-1) ++ct;//or else if(abs(lsum-rsum)==1) ++ct; 
            }
            else{
                lsum+=nums[i];
                rsum-=nums[i];
            }
        }
        return ct;
    }
};

//Simulation
class Solution {
public:
    int countValidSelections(vector<int>& nums) {//TC=O(n*nm), SC=O(n)
        int ct=0;
        int n=nums.size(),non0=0;
        for(int e:nums) if(e!=0) ++non0;
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                if(isvalid(nums,non0,i,1)) ++ct;
                if(isvalid(nums,non0,i,-1)) ++ct;
            }
        }
        return ct;
    }
private:
    bool isvalid(vector<int>& nums,int non0,int idx,int dir){//TC=O(nm)- m is max ele in the array
        int n=nums.size();
        vector<int> temp(nums);
        int curr=idx;
        while(curr>=0 && curr<n && non0>0){
            if(temp[curr]>0){
                temp[curr]--;
                if(temp[curr]==0) --non0;
                dir*=-1;
            }
            curr+=dir;
        }
        return non0==0;
    }
};
