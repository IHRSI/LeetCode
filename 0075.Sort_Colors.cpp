class Solution {//TC=O(nlogn) SC=O(n)
public:
    void sortColors(vector<int>& nums) {
        multiset<int> ms;
        for(int i=0;i<nums.size();++i){
            ms.insert(nums[i]);
        }
        int i=0;
        for(auto ele: ms){
            nums[i]=ele;
            i++;
        }
        return;
    }
};

class Solution {//TC=O(n) SC=O(1)
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int a[3];
        for(int i=0;i<nums.size();++i){
            a[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(a[0]!=0){
                nums[i]=0;
                --a[0];
            }
            else if(a[1]!=0){
                nums[i]=1;
                --a[1];
            }
            else{
                nums[i]=2;
            }
        }
        return;
    }
};
