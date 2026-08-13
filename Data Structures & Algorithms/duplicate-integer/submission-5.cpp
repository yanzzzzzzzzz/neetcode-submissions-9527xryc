class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // more than once, 用hashset檢查
        // 如果set沒有數字, 就把數字放進set
        // set有數字, 就傳false
        // 檢查完全部數字都沒有重複就傳true
        unordered_set<int> mySet;
        for(int num:nums){
            if (mySet.contains(num)) {
                return true;
            }
            mySet.insert(num);
        }
        return false;
    }
};