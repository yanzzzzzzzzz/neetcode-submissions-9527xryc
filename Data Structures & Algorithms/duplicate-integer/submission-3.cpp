class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //用hashSet紀錄出現的頻率
        unordered_set<int> seen; 
        for(int num: nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};