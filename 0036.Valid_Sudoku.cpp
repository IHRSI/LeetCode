//used Q-2133 concept
class Solution { //TC=O(81)=O(1) , SC=0(81+9+9)=O(1)as n=9 is const
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //vector<bool> box(9,false)[9]; Worng representation
        vector<vector<bool>> box(9, vector<bool>(9, false));//81
        for (int r = 0; r < 9; ++r) {
            vector<bool> row(9,false);//9
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int value=board[r][c]-'1';
                int boxindex= (r/3)*3 + (c/3);
                if(row[value]==true || box[boxindex][value]==true) return 0;
                row[value]=true;
                box[boxindex][value]=true;
            }
            
        }
        for (int r = 0; r < 9; ++r) {
            vector<bool> col(9,false);//9
            for (int c = 0; c < 9; ++c) {
                if (board[c][r] == '.') {
                    continue;
                }
                int value2=board[c][r]-'1';
                if(col[value2]==true) return 0;
                col[value2]=true;
            }
        }
        return 1;
    }
};
/*
Breakdown: logic for box indexing

(r / 3) and (c / 3) are used to get the sub-box indexes from the 9x9 box's rows & columns. This means you'll get these values for the sub-boxes (r/3,c/3):
0,0 0,1 0,2
1,0 1,1 1,2
2,0 2,1 2,2
Eg.
r=2 c=2 -> 2/3 =0, 2/3=0 -> r=2 c=2 belongs to the first sub-box.
r=4 c=0 -> 4/3=1, 0/3=0 -> r=4 c=0 belongs to the 4th sub-box (1,0).
now you just need to find a way to number each of these sub-boxes as an int incrementally
-- 0, 1, 2
-- 3, 4, 5
-- 6, 7, 8
You can see that the int is incremented by 3 when going down, and incremented by 1 when going to the right.
So (r / 3) * 3 - is for going down
(c / 3) * 1 - is for going to the right.
You'll get (r / 3 ) * 3 + (c / 3) * 1 --> (r / 3) * 3 + (c / 3).*/
