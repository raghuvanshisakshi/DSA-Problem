class Solution {
public:
    int solve(vector<int>&coins, int amount, int i, vector<vector<int>>&dp){

        if(i== 0) {
            if(amount%coins[i] == 0) return amount/coins[i];
                return INT_MAX;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take = INT_MAX;
        if(coins[i]<=amount){
         take = solve(coins,amount-coins[i], i, dp);
         if(take!=INT_MAX){
            take = 1+take;
         }
        }
        int nottake = 0+solve(coins, amount, i-1, dp);
        dp[i][amount]=min(take,nottake);
        return dp[i][amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,-1));
        int ans  = solve(coins, amount, coins.size()-1, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
