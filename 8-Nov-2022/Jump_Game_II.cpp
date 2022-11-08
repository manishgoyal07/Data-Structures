// 45. Jump Game II

// Recursion:
class Solution {
   public:
    int func(vector<int>& nums, int idx) {
        if (idx >= nums.size() - 1) return 0;
        int temp = 1e8;
        for (int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, 1 + func(nums, idx + i));
        }
        return temp;
    }
    int jump(vector<int>& nums) {
        return func(nums, 0);
    }
};

// TC: O(k^N)
// SC: O(N)

// Memoization:
class Solution {
   public:
    int func(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size() - 1) return 0;
        if (dp[idx] != -1) return dp[idx];
        int temp = 1e8;
        for (int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, 1 + func(nums, idx + i, dp));
        }
        return dp[idx] = temp;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(nums, 0, dp);
    }
};

// TC: O(N*k)
// SC: O(N)

// Tabulation:
class Solution {
   public:
    int func(vector<int>& nums, vector<int>& dp, int n) {
        dp[n - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int temp = 1e8;
            for (int j = i + 1; j <= min(i + nums[i], n - 1); j++) {
                temp = min(temp, 1 + dp[j]);
            }
            dp[i] = temp;
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(nums, dp, n);
    }
};

// TC: O(N*K)
// SC: O(N)