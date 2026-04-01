class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i = 1;i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i = n-2;i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        // for(int i = 0; i < n; i++){
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; i++){
        //     cout << right[i] << " ";
        // }
        vector<int> ans;
        for(int i = 0;i < n; i++){
            ans.push_back(left[i] * right[i]);
        }

        return ans;

        // left 1 1 2 8
        // right 48 24 6 1
    }
};
