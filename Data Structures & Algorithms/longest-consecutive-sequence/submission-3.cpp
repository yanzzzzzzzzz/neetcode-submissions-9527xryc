class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        for(int num:nums){
            if(!s.count(num - 1)){
                int current = num;
                int count = 1;
                while(s.count(current + 1)){
                    current++;
                    count++;
                }
                maxLength = max(maxLength, count);
            }
        }
        return maxLength;
    }
};
