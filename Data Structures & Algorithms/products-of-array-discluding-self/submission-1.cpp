class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 1;i < n; i++){
            // ans 1 1 2 8
            ans[i] = ans[i-1] * nums[i-1];
        }
        int postfix = 1;
        for(int i = n-2;i >= 0; i--){
            postfix *= nums[i+1]; // 48 24 6 1
            ans[i] *= postfix;
        }
         for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }

        return ans;
    }
};
