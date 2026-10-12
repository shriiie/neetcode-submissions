class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=0,prev=0;
        for(int i=2;i<=n;i++){
            int l=prev+cost[i-1];
            int r=INT_MAX;
            if(i>1){
                r=prev2+cost[i-2];
            }
            int curr=min(l,r);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
