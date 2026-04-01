class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int count = height.size();
        int leftMax[count] = {0};
        int rightMax[count] = {0};
        leftMax[0] = height[0];
        for(int i = 1; i < count; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        rightMax[count - 1] = height[count - 1];
        for(int i = count - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        for(int i = 0; i < count; i++){
            res += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};
