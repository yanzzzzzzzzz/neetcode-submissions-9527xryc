class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            auto it = umap.find(diff);
            if (it != umap.end()) {
                return {it->second, i};
            }
            umap[nums[i]] = i;
        }
        return {0 ,0};
    }
};
