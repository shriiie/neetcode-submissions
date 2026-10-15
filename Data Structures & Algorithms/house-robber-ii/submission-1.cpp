class Solution {
public:
    int hr(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int t=arr[i];
            if(i>1) t+=dp[i-2];
            int nt=dp[i-1];
            dp[i]=max(t,nt);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> nums1,nums2;
        for(int i=0;i<n-1;i++){
            nums1.push_back(nums[i]);
        }
        for(int i=1;i<=n-1;i++){
            nums2.push_back(nums[i]);
        }
        return max(hr(nums1),hr(nums2));
    }
};
