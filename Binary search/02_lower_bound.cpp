#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
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
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int target = 9;

    int lb = sol.lowerBound(arr, target);
    cout << "Lower Bound index for " << target << " is: " << lb << endl;

    return 0;
}
