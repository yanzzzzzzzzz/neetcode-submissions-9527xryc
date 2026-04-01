class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // sudoku 要合法, 分成多個地方檢察
        // 1. 每一列不能有重複數字
        // 2. 每一排不能有重複數字
        // 3. 每3x3的九宮格不能重複數字
        // 以上條件達成就能視為合法
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int b = (i/3)*3 + j/3;
                if(row[i][num] || col[j][num] || box[b][num]){
                    return false;
                }
                row[i][num]++;
                col[j][num]++;
                box[b][num]++;
            }
        }
        return true;
    }
};
