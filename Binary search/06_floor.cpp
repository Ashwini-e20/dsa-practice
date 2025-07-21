#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int ans = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = mid;        //may or may not be an answer
                low = mid + 1;    // Try to find a bigger one
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 4, 4, 6, 8, 10};
    int x = 4;

    int index = sol.findFloor(arr, x);
    if (index != -1)
        cout << "Floor of " << x << " is " << arr[index] << " at index " << index << endl;
    else
        cout << "No floor found for " << x << endl;

    return 0;
}
