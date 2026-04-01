class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestNum = 0;
        for(int num : s){
            // 檢查是不是起始數字,不是的話就不做
            if(s.count(num - 1)){
                continue;
            }
            // 是起始數字, 開始找最大連接數量
            int current = num;
            int count = 1;
            while(s.count(current + 1)){
                current++;
                count++;
            }
            longestNum = max(longestNum, count);
        }
        return longestNum;
    }
};
