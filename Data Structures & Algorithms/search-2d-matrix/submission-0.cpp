class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int r = row * col - 1;
        int l = 0;
        while(r >= l){
            int mid = (r + l) / 2;
            int m = mid / col;
            int n = mid % col;
            if(matrix[m][n] == target){
                return true;
            }
            else if(matrix[m][n] > target){
                r = mid - 1;
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
};
