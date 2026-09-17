class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int right = 0; right <nums.size(); right++){
            int left = right - k + 1;

            if(!q.empty() && q.front() < left){
                q.pop_front();
            }

            while(!q.empty() && nums[right] > nums[q.back()]){
                q.pop_back();
            }

            q.push_back(right);

            if(right >= k - 1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
