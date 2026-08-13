class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 用hashmap把同一群的字放在一起
        // 怎麼決定哪些字是同一群:排序string讓他們有相同特徵
        unordered_map<string, vector<string>> mp;
        for(auto str: strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& [key, value] : mp){
            res.push_back(value);
        }
        return res;
    }
};
