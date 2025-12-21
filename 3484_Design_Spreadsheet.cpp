//Using Um - Each cell has a unique identifier, we can store cell values in a hash table.
class Spreadsheet {//TC=O(1), SC=O(cellsCount), as the hash table stores only non-zero cells.
public:
    unordered_map<string,int> grid;
    Spreadsheet(int rows) {//Initialisation is not needed as its UM
        
    }
    
    void setCell(string cell, int value) {
        grid[cell]=value;
    }
    
    void resetCell(string cell) {
        grid[cell]=0;
    }
    
    int getValue(string formula) {
        int i=formula.find('+');
        string x=formula.substr(1,i-1);
        string y=formula.substr(i+1);
        return ((isalpha(x[0]))?grid[x]: stoi(x))+((isalpha(y[0]))?grid[y]: stoi(y));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

//Using 2d matrix
class Spreadsheet {//SC=O(r*26)
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {//O(r*26)
        sheet=vector<vector<int>>(rows+1,vector<int>(26));
    }
    
    void setCell(string cell, int value) {//O(1)
        int r=stoi(cell.substr(1));
        int c=cell[0]-'A';
        sheet[r][c]=value;
    }
    
    void resetCell(string cell) {//O(1)
        int r=stoi(cell.substr(1));
        int c=cell[0]-'A';
        sheet[r][c]=0;
    }
    
    int getValue(string formula) {//O(1)
        int i=formula.find('+');
        string x=formula.substr(1,i-1);
        string y=formula.substr(i+1);
        return getval(x)+getval(y);
    }
    int getval(string s){//O(1)
        if(isalpha(s[0])){
            int r=stoi(s.substr(1));
            int c=s[0]-'A';
            return sheet[r][c];
        }
        return stoi(s);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
