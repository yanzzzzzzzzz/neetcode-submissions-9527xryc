class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestNum = 0;
        for(int i = 0; i < nums.size(); i++){
            // 檢查是不是起始數字,不是的話就不做
            if(s.find(nums[i] - 1) != s.end()){
                continue;
            }
            // 是起始數字, 開始找最大連接數量
            int startNum = nums[i];
            int count = 0;
            while(s.find(startNum) != s.end()){
                startNum++;
                count++;
            }
            longestNum = max(longestNum, count);
        }
        return longestNum;
    }
};
