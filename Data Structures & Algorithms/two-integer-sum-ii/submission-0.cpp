class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int l = 0;
        int r = len - 1;
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum > target){
                r--;
            }
            else if(sum < target){
                l++;
            }
            else{
                return {l+1, r+1};
            }
        }
        return {0, 0};
    }
};
