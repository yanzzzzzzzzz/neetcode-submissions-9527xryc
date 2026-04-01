class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // sudoku 要合法, 分成多個地方檢察
        // 1. 每一列不能有重複數字
        // 2. 每一排不能有重複數字
        // 3. 每3x3的九宮格不能重複數字
        // 以上條件達成就能視為合法
        for(int i = 0; i < 9; i++){
            int check[9] = {0};
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                if(check[idx] > 0){
                    return false;
                }
                check[idx]++;
            }
        }
        for(int i = 0; i < 9; i++){
            int check[9] = {0};
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                int idx = board[j][i] - '1';
                if(check[idx] > 0){
                    return false;
                }
                check[idx]++;
            }
        }
        for(int x = 0; x < 9; x+=3){
            for(int y = 0; y < 9; y+=3){
                int check[9] = {0};
                for(int i = x; i < x + 3; i++){
                    for(int j = y; j < y + 3; j++){
                        if(board[i][j] == '.') continue;
                        int idx = board[i][j] - '1';
                        if(check[idx] > 0){
                            return false;
                        }
                        check[idx]++;
                    }
                }
            }
        }
        return true;
    }
};
