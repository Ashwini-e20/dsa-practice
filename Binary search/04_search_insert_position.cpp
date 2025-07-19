#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n;
        int low = 0, high = n - 1;

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
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "Index to insert " << target << " is: " << result << endl;

    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "Index to insert " << target << " is: " << result << endl;

    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "Index to insert " << target << " is: " << result << endl;

    return 0;
}
