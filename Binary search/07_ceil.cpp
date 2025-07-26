//find ceil of an element
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int ans = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;         //storing the potential answer
                high = mid - 1;    // try to find smaller such element (left side)
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5, 5, 6, 8, 10};
    int x = 5;

    int index = sol.findCeil(arr, x);
    if (index != -1)
        cout << "Ceil of " << x << " is " << arr[index] << " at index " << index << endl;
    else
        cout << "No ceil found for " << x << endl;

    return 0;
}
