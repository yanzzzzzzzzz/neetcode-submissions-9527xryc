class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //用hashmap紀錄出現的頻率
        unordered_map<int, bool> umap; 
        for(int i = 0; i < nums.size(); i++){
            if(umap[nums[i]]){
                return true;
            }
            umap[nums[i]] = true;
        }
        return false;
    }
};