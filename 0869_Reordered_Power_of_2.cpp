class Solution {
public:
    bool reorderedPowerOf2(int n) {//TC=O(30*10)~O(1), SC=O(300)~O(1)
      //Precomputing
        const int x = log(1e9) / log(2);
        int hsh[x + 1][10];//O(300)
        for (int i = 0; i <= x; ++i) {//O(x*log(val))
            int val = 1 << i;
            while (val > 0) {//O(log(val))
                hsh[i][val % 10]++;
                val /= 10;
            }
        }
        int arr[10];//O(10)
        while (n > 0) {//O(logn)
            arr[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i <= x; ++i) {//O(x*10) , max val of x=30
            bool flag = true;
            for (int j = 0; j < 10; ++j) {//O(10)
                if (arr[j] != hsh[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return 1;
        }
        return 0;
    }
};

//Used str convirsion followed by sorting
class Solution {//TC=O(30*10log(10))=O(300)=O(1) , SC=O(1)
public:
    bool reorderedPowerOf2(int n) {
        auto sortDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = sortDigits(n);
        for (int i = 0; i < 31; i++) {
            if (sortDigits(1 << i) == target) return true;
        }
        return false;
    }
};

//Used precomputation for better efficiency- The code is same just the precompute function contains
//the precomputed part which runs only once.
const int x = 29;
int hsh[x + 1][10];
bool computed = false;
void precompute() {
    computed=true;
    for (int i = 0; i <= x; ++i) {
        int val = 1 << i;
        while (val > 0) {
            hsh[i][val % 10]++;
            val /= 10;
        }
    }
}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(!computed) precompute();
        int arr[10];
        while (n > 0) {
            arr[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i <= x; ++i) {
            bool flag = true;
            for (int j = 0; j < 10; ++j) {
                if (arr[j] != hsh[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return 1;
        }
        return 0;
    }
};
