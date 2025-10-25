//Backtracking soln
class Solution {//TC=O(9^d), d=no. of digits in n, SC=O(1)
public:
    vector<int> hsh{0,1,2,3,4,5,6,7,8,9};
    int bt(int n,int curr,int len){
        if(len==0){
            for(int i=1;i<=9;++i){
                if(hsh[i]!=0 && hsh[i]!=i) return 0;
            }
            return curr>n?curr:0;
        }
        int res=0;
        for(int digit = 1; digit <= 9; digit++) {
            if(hsh[digit] > 0 && hsh[digit] <= len) {
                hsh[digit]--;
                res = bt(n, curr*10+digit, len-1);
                hsh[digit]++;
            }
            if(res != 0) {
                break;
            }
        }
        return res;
    }
    int nextBeautifulNumber(int n) {
        int ans=0;
        int len=to_string(n).size();
        ans=bt(n,0,len);
        if(ans==0) ans=bt(n,0,len+1);
        return ans;
    }
};

//We get different runtime and space usage dur to use of array in one and vector in other otherwise everything is same
//Runtime = 55ms, space 8mb
class Solution {
public:
    int nextBeautifulNumber(int n) {//TC=O((1224444-n)*(logn+10)), SC=O(10)~O(1)
        for(int i=n+1;i<=1224444;++i){
            int num=i;
            int v[10]={0};
            while(num>0){
                ++v[num%10];
                num/=10;
            }
            int check=true;
            for(int k=0;k<10;++k){
                if(v[k]>0 && v[k]!=k){
                    check=false;
                    break;
                }
            }
            if(check) return i;
        }
        return 0;
    }
};

//Runtime = 550ms, space 255mb
class Solution {
public:
    int nextBeautifulNumber(int n) {//TC=O(1224444*(logn+10)), SC=O(10)~O(1)
        for(int i=n+1;i<=1224444;++i){
            int num=i;
            vector<int> v(10);
            while(num>0){
                ++v[num%10];
                num/=10;
            }
            int check=true;
            for(int k=0;k<10;++k){
                if(v[k]>0 && v[k]!=k){
                    check=false;
                    break;
                }
            }
            if(check) return i;
        }
        return 0;
    }
};

/*
Why vector<int> v(10) is much slower & heavier than int v[10] = {0};
Heap Allocation Overhead –
vector allocates memory on the heap every loop iteration → millions of slow allocations.
int[10] is stack-allocated → instant and reused.
Constructor/Destructor Cost –
Each vector calls a constructor (to init elements) and destructor (to free heap memory).
Zero Initialization Cost –
vector<int>(10) default-initializes elements dynamically;
int v[10]={0} is optimized at compile time.
Memory Fragmentation / Allocator Overhead –
Frequent heap alloc/free causes allocator metadata buildup → higher peak memory.
Cache Locality –
Stack arrays sit contiguously in L1 cache; heap allocations are scattered → more cache misses.
Memory Measurement (LeetCode SC) –
Reported “255 MB” = allocator holding heap pages; stack arrays don’t affect this metric.
✅ Bottom line:
Use int v[10] (stack) for fixed small arrays — it’s ~10× faster and ~30× lighter than vector<int>(10) in tight loops.
*/

class Solution {//Not intuitive
public:
    const vector<int> balance{
        1,      22,     122,    212,    221,    333,    1333,   3133,   3313,
        3331,   4444,   14444,  22333,  23233,  23323,  23332,  32233,  32323,
        32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,
        122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232,
        133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313,
        223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
        233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442,
        312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332,
        322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321,
        331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
        333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
        442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551,
        666666, 1224444};

    int nextBeautifulNumber(int n) {//TC=O(log110), SC=O(110)
        return *upper_bound(balance.begin(), balance.end(), n);
    }
};
