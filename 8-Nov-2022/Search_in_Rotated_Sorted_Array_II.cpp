// 81. Search in Rotated Sorted Array II

class Solution {
   public:
    bool search(vector<int>& nums, int key, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == key) return true;

            if (nums[l] == nums[mid] && nums[r] == nums[mid]) {
                l++;
                r--;
            }

            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= key && nums[mid] >= key)
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            else {
                if (nums[mid + 1] <= nums[r]) {
                    if (nums[mid + 1] <= key && nums[r] >= key)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};

// TC: O(NlogN)
// SC: O(1)