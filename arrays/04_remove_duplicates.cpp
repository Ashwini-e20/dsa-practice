//Remove duplicates from sorted array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};

    Solution sol;
    int uniqueCount = sol.removeDuplicates(nums);

    cout << "Unique elements after removing duplicates:\n";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }

    cout << "\nTotal unique elements: " << uniqueCount << endl;
    return 0;
}
