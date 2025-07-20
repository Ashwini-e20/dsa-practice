#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
      
        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        }

        int ub = upperBound(nums, target);
        return {lb, ub - 1};  
    }

private:
    // First index where value >= target
    int lowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }


    int upperBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
