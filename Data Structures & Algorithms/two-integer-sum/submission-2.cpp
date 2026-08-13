class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 要從nums找出兩個相加的數字等於target
        // 已知其中一個數字, 只要找到另一個互補值(target - num), 需要快速查詢某數字是否存在
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            auto it = mp.find(target - num);
            if(it != mp.end()){
                return {it->second, i};
            }else{
                mp[num] = i;
            }
        }
        return {}; 
    }
};
