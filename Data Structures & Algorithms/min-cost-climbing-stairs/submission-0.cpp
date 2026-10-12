class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return 0;
        vector<int> dp(n+1);
        dp[0]=0,dp[1]=0;
        for(int i=2;i<=n;i++){
            int l=dp[i-1]+cost[i-1];
            int r=INT_MAX;
            if(i>1){
                r=dp[i-2]+cost[i-2];
            }
            dp[i]=min(l,r);
        }
        return dp[n];
    }
};
