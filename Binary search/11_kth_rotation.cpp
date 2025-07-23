#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();

        while (low <= high) {
            // Case when the subarray is already sorted
            if (nums[low] <= nums[high])
                return low;

            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Check if mid is the minimum element
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return mid;

            // Left half is sorted, search in right half
            if (nums[mid] >= nums[low])
                low = mid + 1;
            else // Right half is sorted, search in left half
                high = mid - 1;
        }

        return 0; // Array was not rotated
    }
};

int main() {
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    Solution sol;
    int k = sol.findKRotation(nums);
    cout << "Array is rotated " << k << " times." << endl;
    return 0;
}
