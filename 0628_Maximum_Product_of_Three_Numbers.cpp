class Solution {
public:
    int maximumProduct(vector<int>& nums) {//TC=O(n), SC=O(1)
        int m1=-1001,m2=-1001,m3=-1001;
        int n1=1001,n2=1001;
        int n=nums.size();
        for(int i=0;i<n;++i){
            int num=nums[i];
            if(num>m1){
                m3=m2;
                m2=m1;
                m1=num;
            }
            else if(num>m2){
                m3=m2;
                m2=num;
            }
            else if(num>m3) m3=num;
            if(num<n1){
                n2=n1;
                n1=num;
            }
            else if(num<n2) n2=num;
        }
        return max(m1*m2*m3,n1*n2*m1);
    }
};
