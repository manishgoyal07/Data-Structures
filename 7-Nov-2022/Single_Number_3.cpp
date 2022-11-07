// 260. Single Number III

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        long long int Xor = 0;
        vector<int> ans(2, 0);
        for (auto i : nums) Xor ^= i;  //[1^2^1^3^2^5] => [5^3]
        long long int pos = Xor & ~(Xor - 1);
        for (auto i : nums) {
            if (i & pos) {    // Set Bit at pos
                ans[0] ^= i;  //[2^3^2]^[5^3]
            } else {          // Non-Set Bit at pos
                ans[1] ^= i;  //[1^1^5]^[5^3]
            }
        }
        return ans;
    }
};

//TC: O(2N)
//SC: O(1)