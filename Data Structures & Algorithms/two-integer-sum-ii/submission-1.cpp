class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int number = numbers[left] + numbers[right];
            if(number > target){
                right--;
            }
            else if(number < target){
                left++;
            }
            else{
                return {left + 1, right + 1};
            }
        }
        return {0, 0};
    }
};
