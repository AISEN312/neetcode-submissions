class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
if (amount == 0) return 0;
const int INF = amount + 1; // sentinel greater than any possible minimum
vector<int> dp(amount + 1, INF);
dp[0] = 0;
for (int a = 1; a <= amount; ++a) {
for (int c : coins) {
if (c <= a) dp[a] = min(dp[a], dp[a - c] + 1);
}
}
return dp[amount] > amount ? -1 : dp[amount];
}
};