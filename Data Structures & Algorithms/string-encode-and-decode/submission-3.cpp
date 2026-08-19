class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs){
            ans += to_string(str.size()) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int i = 0;
        while(i < s.length()){
            string numStr = "";
            int j = i;
            for(j = i; j < s.length(); j++){
                if(s[j] == '#'){
                    break;
                }
                numStr += s[j];
            }
            int num = stoi(numStr);
            int startIndex = j + 1;
            vec.push_back(s.substr(startIndex, num));
            i += numStr.length() + 1 + num;
        }
        return vec;
    }
};
