class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){    
                int val = s.top();
                res[val] = i - val;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
