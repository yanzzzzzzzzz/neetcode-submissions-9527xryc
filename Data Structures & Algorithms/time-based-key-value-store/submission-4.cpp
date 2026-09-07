class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { 
        auto& vec = mp[key];
        if(vec.empty() || vec[0].first > timestamp){
            return "";
        }
        int left = 0;
        int right = vec.size() - 1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if(vec[mid].first > timestamp){
                right = mid - 1;
            }else {
                left = mid;
            }
        }
        return vec[left].second;
    }
};
