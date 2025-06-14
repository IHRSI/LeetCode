//This is classic greedy thinking:
//"To maximize the number, make the biggest impactful change early.
class Solution {//TC=O(logn) : n=no of digits , SC=O(logn)
public:
    int minMaxDifference(int num) {
        string max=to_string(num);//O(logn)
        int n=max.length();
        string min=max;
        char max_ele='0';
        char fst_ele=min[0];
        for(int i=0;i<n;++i){//O(logn)
            if(max[i]=='9') continue;
            else{
                max_ele=max[i];
                break;
            }
        }
        for(int i=0;i<n;++i){//O(logn)
            if(fst_ele==min[i]) min[i]='0';
            if(max_ele==max[i]) max[i]='9';
        }

        return stoi(max)-stoi(min);//O(logn)
    }
};
