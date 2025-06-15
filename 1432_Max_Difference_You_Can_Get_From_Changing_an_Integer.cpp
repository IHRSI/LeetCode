//Best soln.(without seeing editorial) , greedy,math
class Solution {//TC=O(logn) eventually O(1) as no of digits can be 10 at max, logn is no. of digits, SC=O(logn)
public:
    int maxDiff(int num) {
        string max=to_string(num);
        string min=max;
        char replace_ele_a='0';
        for(char &c: max){
            if(c!='9'){
                replace_ele_a=c;
                break;
            }
        }
        replace(max.begin(),max.end(),replace_ele_a,'9');
        if(min[0]!='1'){
            char replace_ele_b=min[0];
            replace(min.begin(),min.end(),replace_ele_b,'1');
        }
        else{
            int n=min.size();
            for(int i=1;i<n;i++){//as break is there replace only works 1 time therefore TC=(logn+logn)=O(logn)
                if(min[i]!='0'&& min[i] != min[0]){//tricky for test case 1101057
                    char replace_ele_b=min[i];
                    replace(min.begin(),min.end(),replace_ele_b,'0');
                    break;
                }
            }
        }
        return stoi(max)-stoi(min);
    }
};
