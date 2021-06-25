class Solution {
    //leetcode 494
    int subset(vector<int>&nums,int sum){
        // according to the question
        int n=nums.size();
        int dp[n+1][sum+1];
        
        dp[0][0]=true;
        for(int i=1;i<=n;i++)dp[i][0]=1;
        for(int j=1;j<=sum;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        } 
        return dp[n][sum]; 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if((target+sum)%2==1)return 0;
        int target_sum=(sum+target)/2;
        return subset(nums,target_sum);
    }
};