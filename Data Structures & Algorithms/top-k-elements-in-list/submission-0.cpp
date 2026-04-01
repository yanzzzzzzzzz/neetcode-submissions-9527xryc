class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            vec.push_back(make_pair(it->second, it->first));
        }
        sort(vec.rbegin(), vec.rend());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};
