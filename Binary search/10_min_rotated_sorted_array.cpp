#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the subarray is already sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;  // eliminate left half
            }
            // If right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;  // eliminate right half
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int minElement = sol.findMin(nums);
    cout << "Minimum element in the rotated sorted array is: " << minElement << endl;
    return 0;
}
