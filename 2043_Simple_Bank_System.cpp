class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {//TC=O(n), SC=O(n)
        this->balance=balance;
    }
    bool transfer(int account1, int account2, long long money) {//TC=O(1), SC=O(1)
        if(account1<=balance.size() && account2<=balance.size() && money<=balance[account1-1]){
            balance[account1-1]-=money;
            balance[account2-1]+=money;
            return 1;
        }
        return 0;
    }
    bool deposit(int account, long long money) {//TC=O(1), SC=O(1)
        if(account<=balance.size()){
            balance[account-1]+=money;
            return 1;
        }
        return 0;
    }
    bool withdraw(int account, long long money) {//TC=O(1), SC=O(1)
        if(account<=balance.size()&& money<=balance[account-1]){
            balance[account-1]-=money;
            return 1;
        }
        return 0;
    }
};
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
