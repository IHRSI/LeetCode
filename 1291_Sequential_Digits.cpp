//Queue using bsf style
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {//TC=O(n), SC=O(n) - where n is no of seq digits btw low and high. As they are very few
                                                                        //as per constraints it is eventually O(1) both time and space.
        queue<int> q;
        for(int i=1;i<=8;++i) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            if(num>=low && num<=high) ans.push_back(num);
            else if(num>high) break;
            int lastdig=num%10;
            if(lastdig+1<=9) q.push(num*10+lastdig+1);
        }
        return ans;
    }
};

//Precompute
class Solution {
public:
    static constexpr int seqnums[]={12,23,34,45,56,67,78,89,
                             123,234,345,456,567,678,789,
                             1234,2345,3456,4567,5678,6789,
                             12345,23456,34567,45678,56789,
                             123456,234567,345678,456789,
                             1234567,2345678,3456789,
                             12345678,23456789,
                             123456789};
    vector<int> sequentialDigits(int low, int high) {//TC=O(1), SC=O(1)
        vector<int> ans;
        for(int num: seqnums){
            if(num>=low && num<=high) ans.push_back(num);
            if(num>high) break;
        }
        return ans;
    }
};
