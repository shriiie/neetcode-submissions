class Solution {
public:
    bool possible(int mid,vector<int>& nums,int days){
        int sum=0,cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                cnt++;
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int low=maxi,high=sum;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};