class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int lmax = 0, rmax = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= lmax){
                    lmax = height[left];
                }
                else{
                    ans += lmax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rmax){
                    rmax = height[right];
                }
                else{
                    ans += rmax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
