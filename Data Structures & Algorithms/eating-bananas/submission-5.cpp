class Solution {
public:
    long long f(vector<int>& piles,int mid){
        long long th=0;
        for(int i=0;i<piles.size();i++){
            th+=ceil((double)piles[i]/mid);
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi=*max_element(piles.begin(),piles.end());
        int low=1,high=maxi;
        int ans;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(f(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
