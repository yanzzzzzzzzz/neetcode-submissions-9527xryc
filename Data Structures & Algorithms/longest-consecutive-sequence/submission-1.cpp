class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestNum = 0;
        for(int num : s){
            // 檢查是不是起始數字,不是的話就不做
            if(s.find(num - 1) != s.end()){
                continue;
            }
            // 是起始數字, 開始找最大連接數量
            int current = num;
            int count = 1;
            while(s.find(current + 1) != s.end()){
                current++;
                count++;
            }
            longestNum = max(longestNum, count);
        }
        return longestNum;
    }
};
